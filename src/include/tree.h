#pragma once
#include"record.h"
#include"DataTypes.h"
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	int size;
} Node;

int Node_CompareTo(Node* n1,Node* n2,RecordMetaData* metadata);

void Node_new(Node* n);
Node* Node_new_heap(int data);
Node* Node_Insert(Node* root,Node* n,RecordMetaData* metadata);
void Node_Print(Node* t,RecordMetaData* metadata);
Record* Node_getRecord(Node* node);
int Node_Equal(Node* n1,Node* n2,RecordMetaData* metadata);

typedef struct Tree{
	Node* root;	
	RecordMetaData* metadata;
} Tree;

void Tree_Insert_Node(Tree* tree,Node* n);
void Tree_new(Tree* t,RecordMetaData* metadata);
void Tree_Print(Tree* t);




int compareInt (int a, int b);
