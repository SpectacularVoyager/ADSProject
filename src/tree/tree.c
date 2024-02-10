#include "../include/tree.h"


void printBlob(const void* addr,unsigned long len){
	const void * final=addr+len;
	while(addr!=final){
		printf("%hhx ",*((char*)addr++));
	}
	printf("\n");
}



void Tree_Insert_Node(Tree* tree,Node* n){
	tree->root=Node_Insert(tree->root,n);
}

Node* Node_Insert(Node* root,Node* n){
	if(!root){
		root=n;
	}else{
		int x=Node_CompareTo(root,n);
		if(x==0){
		}else if(x>0){
			root->left=Node_Insert(root->left,n);
		}else{
			root->right=Node_Insert(root->right,n);
		}
	}
	return root;
}
int Node_CompareTo(Node* n1,Node* n2){
	//return compareInt(n1->a,n2->a);
	return -1;
}

//int compareInt (int a, int b)
//{
//    if (a < b) return -1;
//    if (a > b) return 1;
//    return 0;
//}

void Tree_new(Tree* t){
	t->root=0;
}

void Node_new(Node* n){
	n->left=0;
	n->right=0;
}

Node* Node_new_heap(int data){
	//printf("size:%d",sizeof(Node));
	Node* n= malloc(data+sizeof(Node));
	n->left=0;
	n->right=0;
	n->size=data;
	return n;
}
Record* Node_getRecord(Node* node){
	return (Record*)(node+1);

}
void Node_Print(Node* t){
	if(!t)return ;
	Node_Print(t->left);
	printf("[node]\n");
	printBlob(t+1,t->size);
	Node_Print(t->right);
}

void Tree_Print(Tree* t){
	if(!t->root){return;}
	Node_Print((t)->root);
}

