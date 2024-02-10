#pragma once
#include"../include/record.h"
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* left;
	struct Node* right;
	int size;
} Node;

int Node_CompareTo(Node* n1,Node* n2);
void Node_new(Node* n);
Node* Node_new_heap(int data);
Node* Node_Insert(Node* root,Node* n);
void Node_Print(Node* t);
Record* Node_getRecord(Node* node);

typedef struct Tree{
	Node* root;	
} Tree;

void Tree_Insert_Node(Tree* tree,Node* n);
void Tree_new(Tree* t);
void Tree_Print(Tree* t);




int compareInt (int a, int b);
