#include "../include/tree.h"
#include <stdio.h>
#include <string.h>
void Tree_Insert_Node(Tree* tree,Node* n){
	tree->root=Node_Insert(tree->root,n,tree->metadata);
}
void Tree_new(Tree* t,RecordMetaData* metadata){
	t->root=0;
	t->metadata=metadata;
}
void Tree_Print(Tree* t){
	if(!t->root){return;}
	Node_Print(t->root,t->metadata);
}

unsigned int Tree_Node_size(Tree* t){
	return t->metadata->stride+sizeof(Node);
}
int NodetoDisk(FILE* file,Node* node){
	if(!node){return 0;}	
	int ret=0;
	ret+=NodetoDisk(file,node->left);
	Node_write(file,node);
	ret+=NodetoDisk(file,node->right);
	return ret+1;
}
List* getSortedTable(FILE* file,RecordMetaData* metadata){
	List* l=malloc(sizeof(List));
	List_init(l,metadata->stride);
	int x;
	fread(&x,4,1,file);
	for(int i=0;i<x;i++){
		unsigned char data[metadata->stride];
		int width;
		fread(&width,4,1,file);
		fread(data,metadata->stride,1,file);
		Node* n=Node_new_heap(metadata->stride);
		memcpy(Node_getRecord(n),data, metadata->stride);
		List_add(l, n);
	}
	return l;
}
void TreetoDisk(FILE* file,Tree* tree){
	fseek(file,4,SEEK_SET);
	int x=NodetoDisk(file,tree->root);
	fseek(file,0,SEEK_SET);
	fwrite(&x,4,1,file);
}
