#pragma once
#include<stdbool.h>
#include <stdio.h>
#define MAX_SIZE 20

typedef struct RecordMetaData{
	int n;
	unsigned int offsets[MAX_SIZE];
	unsigned int sizes[MAX_SIZE];
	char key[MAX_SIZE];
	int key_n;
	char sort[MAX_SIZE];
	int sort_n;
	int stride;
} RecordMetaData;



typedef struct Record{
	const void* data;
} Record;

int Record_CompareTo(Record* r1,Record* r2);
int Record_EqualTo(Record* r1,Record* r2);

void Record_set(RecordMetaData* metadata,Record* r,int i,const void* data);

void RecordMetaData_new(RecordMetaData* rmd,unsigned long sizes[],int n,char key[],unsigned int key_n,char sort[],unsigned int sort_n);

void RecordMetaData_Print(RecordMetaData* rmd);

#define RECORD_SET_X_MACRO(fun,type) \
	void fun(RecordMetaData* metadata,Record* r,int i,type val);

#define RECORD_SET_X_DEF_MACRO(fun,type) \
	void fun(RecordMetaData* metadata,Record* r,int i,type val){\
		void* start=(void*)r;\
		start+=(metadata->offsets[i]);\
		*((type*)start)=val;\
	}\

RECORD_SET_X_MACRO(Record_setInt,int)
RECORD_SET_X_MACRO(Record_setFloat,float)
RECORD_SET_X_MACRO(Record_setDouble,double)
RECORD_SET_X_MACRO(Record_setLong,long)

