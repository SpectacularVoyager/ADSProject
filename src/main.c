#include <stdlib.h>
#include <stdio.h>
#include "include/record.h"
#include"include/tree.h"
#include"include/DataTypes.h"


int main(){

	RecordMetaData* metadata=malloc(sizeof(RecordMetaData));
	unsigned long arr[]={4,4,8,4};
	char keys[]={0};
	char sort[]={1};
	DataTypes types[]={INT,FLOAT,LONG,STRING};
	const char *names[]={"int","float","long","string"};
	RecordMetaData_new(metadata, arr,4, keys, 1,sort,1,types,names);
	RecordMetaData_Print(metadata);
	unsigned int stride=metadata->stride;

	Tree tree;
	Tree_new(&tree,metadata);

	Node* n1=Node_new_heap(stride);
	Record* r=Node_getRecord(n1);
	Record_setInt(metadata, r,0,500);
	Record_setFloat(metadata, r,1,1.0);
	Record_setLong(metadata, r,2,2048);
	Record_setString(metadata, r,3,"ab");

	Node* n2=Node_new_heap(stride);
	Record* r2=Node_getRecord(n2);
	Record_setInt(metadata, r2,0,800);

	Tree_Insert_Node(&tree,n1);
	Tree_Insert_Node(&tree,n2);
	Tree_Print(&tree);
	
	//Node_Print(n1,metadata);

	//printf("%d",RecordMetaData_getIndexFromString(metadata,"int"));
	free(metadata);
	return 0;
}

