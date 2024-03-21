#pragma once
#include"record.h"
#include"node.h"
#include"DataTypes.h"
#include <stdio.h>
#include<stdlib.h>

typedef struct Tree{
	Node* root;	
	RecordMetaData* metadata;
} Tree;

void Tree_Insert_Node(Tree* tree,Node* n);
void Tree_new(Tree* t,RecordMetaData* metadata);
void Tree_Print(Tree* t);
unsigned int Tree_Node_size(Tree* t);

void TreetoDisk(FILE* file,Tree* tree);

List* getSortedTable(FILE* file,RecordMetaData* metadata);
