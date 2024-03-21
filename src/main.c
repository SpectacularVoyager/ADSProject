#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/record.h"
#include"include/tree.h"
#include"include/list.h"
#include"include/DataTypes.h"

#define printInt(x) printf("%d\n",(int)x)

void addNode(Tree* tree,int a,float b,long c,char* d){
	RecordMetaData* metadata=tree->metadata;
	unsigned int stride=metadata->stride;
	Node* n2=Node_new_heap(stride);
	Record* r2=Node_getRecord(n2);
	Record_setInt(metadata, r2,0,a);
	Record_setFloat(metadata, r2,1,b);
	Record_setLong(metadata, r2,2,c);
	Record_setString(metadata, r2,3,d);
	Tree_Insert_Node(tree,n2);
}
void flushTree(Tree* tree,char* file){
	FILE* f=fopen(file,"w");
	TreetoDisk(f,tree);
	fclose(f);
}
void printSSTable(char* filename,RecordMetaData* metadata){
	printf("[SSTABLE]:\t%s\n",filename);
	FILE* f=fopen(filename,"r");
	List* set=getSortedTable(f,metadata);
	for(int i=0;i<set->n;i++){
		Node_Print(List_get(set,i), metadata);
	}
	fclose(f);
}
int main(){


	RecordMetaData* metadata=malloc(sizeof(RecordMetaData));
	unsigned long arr[]={4,4,8,20};
	char keys[]={0,1};
	char sort[]={0};
	DataTypes types[]={INT,FLOAT,LONG,STRING};
	const char *names[]={"int","float","long","string"};
	RecordMetaData_new(metadata, arr,4, keys, 2,sort,1,types,names);
	RecordMetaData_Print(metadata);
	unsigned int stride=metadata->stride;


	Tree tree;
	Tree_new(&tree,metadata);

	addNode(&tree,1,2,13,"abc");
	addNode(&tree,5,1,321,"abc");
	addNode(&tree,3,9,5,"abc");
	addNode(&tree,5,9,5,"abc");
	//Tree_Print(&tree);
	List l;
	const int arg1=2;
	const int arg2=5;

	List_init(&l,Tree_Node_size(&tree));
	Node_getRange(tree.root,&l,&arg1,&arg2,tree.metadata);

	printf("NODE\n");
	for(int i=0;i<l.n;i++){
		Node_Display((Node*)List_get(&l,i),metadata);
	}
	printSSTable("res/sstable3",metadata);
	//Node_write(&tree->root,)
	flushTree(&tree,"res/sstable3");
	free(metadata);
	return 0;
}

