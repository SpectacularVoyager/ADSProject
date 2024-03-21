#include "record.h"
#include "list.h"
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

void Node_getPoint(Node* n,List* l,const void* data,RecordMetaData* metdata);
void Node_getRange(Node* n,List* l,const void* v1,const void* v2,RecordMetaData* metadata);


int Node_CompareToPoint(Node* n1,const void* point,RecordMetaData* metadata);
unsigned int Node_getSize(Node * n);

void Node_Display(Node* t,RecordMetaData* metadata);
