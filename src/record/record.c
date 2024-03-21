#include "../include/record.h"
#include <string.h>


RECORD_SET_X_DEF_MACRO(Record_setInt,int)
RECORD_SET_X_DEF_MACRO(Record_setFloat,float)
RECORD_SET_X_DEF_MACRO(Record_setDouble,double)
RECORD_SET_X_DEF_MACRO(Record_setLong,long)

void Record_setString(RecordMetaData* metadata,Record* r,int i,char* val){
	void* start=(void*)r;
	start+=(metadata->offsets[i]);
	unsigned long size=metadata->sizes[i];
	strncpy(start, val, size);
}

int Record_CompareTo(Record* r1,Record* r2){
	return -1;
}

void Record_set(RecordMetaData* metadata,Record* r,int i,const void* data){
	//void* start=(void*)r+metadata->offsets[i];
	void* start=(void*)r;
	start+=(metadata->offsets[i]);
	unsigned long size=metadata->sizes[i];
	memcpy(start,data, size);
}

const void* Record_get(RecordMetaData* metadata,Record* r,int i){
	void* start=(void*)r;
	start+=(metadata->offsets[i]);
	return start;
}
void Record_print(Record* r,RecordMetaData* metadata){
	const void* ptr=r;
	printf("node:[");
	for(int i=0;i<metadata->n;i++){
		DataTypes type=metadata->types[i];
		if(type==INT){
			printf("%d,",*(int*)ptr);
		}
		if(type==LONG){
			printf("%ld,",*(long*)ptr);
		}
		if(type==DOUBLE){
			printf("%lf,",*(double*)ptr);
		}
		if(type==FLOAT){
			printf("%f,",*(float*)ptr);
		}
		if(type==STRING){
			printf("'%.*s',",metadata->sizes[i],(char*)ptr);
		}
		ptr=ptr+metadata->sizes[i];
	}
	printf("]\n");
}

		
int RecordMetaData_getIndexFromString(RecordMetaData* metadata,const char* str){
	for(int i=0;i<metadata->n;i++){
		if(strncmp(str,metadata->columns[i],MAX_SIZE)==0){
			return i;
		}
	}
	return -1;
}
void RecordMetaData_new(RecordMetaData* rmd,unsigned long sizes[],int n,char key[],unsigned int key_n,char sort[],unsigned int sort_n,DataTypes *types,const char* columns[]){


	rmd->n=n;
	//memset(rmd->key,-1,sizeof(unsigned char)*MAX_SIZE);
	//memset(rmd->sort,-1,sizeof(unsigned char)*MAX_SIZE);
	//memset(rmd->offsets,-1,sizeof(void*)*MAX_SIZE);
	//memset(rmd->sizes,-1,sizeof(unsigned long)*MAX_SIZE);
	rmd->key_n=key_n;
	rmd->sort_n=sort_n;

	memcpy(rmd->key,key, key_n);
	memcpy(rmd->sort,sort, sort_n);
	int sum=0;
	for(int i=0;i<n;i++){
		rmd->offsets[i]=sum;
		rmd->sizes[i]=sizes[i];
		rmd->types[i]=types[i];
		rmd->columns[i]=columns[i];
		sum+=sizes[i];
	}
	rmd->stride=sum;
}
void RecordMetaData_Print(RecordMetaData* rmd){

	printf("-------------------------------------------\n");
	printf("RECORD META DATA\n");
	printf("-------------------------------------------\n");
	printf("OFFSETS:");
	for(int i=0;i<rmd->n;i++){
		printf("%u,",rmd->offsets[i]);
	}
	printf("\n");

	printf("SIZES:");
	for(int i=0;i<rmd->n;i++){
		printf("%u,",rmd->sizes[i]);
	}
	printf("\n");

	printf("KEYS:");
	for(int i=0;i<rmd->key_n;i++){
		printf("%hhx,",rmd->key[i]);
	}
	printf("\n");

	printf("SORT:");
	for(int i=0;i<rmd->sort_n;i++){
		printf("%hhx,",rmd->sort[i]);
	}
	printf("\n");

	printf("COLUMNS:");
	for(int i=0;i<rmd->n;i++){
		printf("%s,",rmd->columns[i]);
	}

	printf("\n");

	printf("\nSIZE:%d\n",rmd->stride);
	printf("-------------------------------------------\n");
	printf("-------------------------------------------\n");
}
