#include <stdlib.h>
#include <stdio.h>
#include "include/record.h"
#include"include/tree.h"
#include"include/DataTypes.h"


int main(){
	Tree tree;
	Tree_new(&tree);

	RecordMetaData* metadata=malloc(sizeof(RecordMetaData));
	unsigned long arr[]={4,4,8,4};
	char keys[]={0};
	char sort[]={2};
	RecordMetaData_new(metadata, arr,4, keys, 1,sort,1);
	RecordMetaData_Print(metadata);
	unsigned int stride=metadata->stride;

	Node* n1=Node_new_heap(stride);
	Record* r=Node_getRecord(n1);
	long a=0xc0ffee;
	Record_set(metadata, r,2,&a);
	Record_setInt(metadata, r,0,0x11223344);
	Record_setLong(metadata, r,2,0x8899AABBCCDDEEFFL);
	Node_Print(n1);

	//free(metadata);
	return 0;
}

