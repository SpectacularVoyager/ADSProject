#include "../include/tree.h"





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











Node* Node_Insert(Node* root,Node* n,RecordMetaData* metadata){
	if(!root){
		root=n;
		return root;
	}else{
		int x=Node_CompareTo(root,n,metadata);
		int eq=Node_Equal(root,n,metadata);
		if(eq==0){
			printf("COLLISION\n");
			//return root;
			n->left=root->left;
			n->right=root->right;
			return n;
		}
		if(x==0){
			root->right=Node_Insert(root->right,n,metadata);
		}else if(x>0){
			root->left=Node_Insert(root->left,n,metadata);
		}else{
			root->right=Node_Insert(root->right,n,metadata);
		}
	}
	return root;
}

int Node_Equal(Node* n1,Node* n2,RecordMetaData* metadata){
	//return compareInt(n1->a,n2->a);
	DataTypes type=metadata->types[0];
	Record *r1=Node_getRecord(n1);
	Record *r2=Node_getRecord(n2);
	for(int i=0;i<metadata->key_n;i++){

		int keyCol=metadata->key[i];
		int x= Datatype_Compare(type, Record_get(metadata, r1,keyCol), Record_get(metadata, r2,keyCol),metadata->sizes[keyCol]);
		if(x!=0){return x;}
	}
	return 0;
}
int Node_CompareTo(Node* n1,Node* n2,RecordMetaData* metadata){
	//return compareInt(n1->a,n2->a);
	DataTypes type=metadata->types[0];
	Record *r1=Node_getRecord(n1);
	Record *r2=Node_getRecord(n2);
	for(int i=0;i<metadata->sort_n;i++){

		int sortCol=metadata->sort[i];
		int x= Datatype_Compare(type, Record_get(metadata, r1,sortCol), Record_get(metadata, r2,sortCol),metadata->sizes[sortCol]);
		if(x!=0){return x;}
	}
	return 0;
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

void Node_Print(Node* t,RecordMetaData* metadata){
	if(!t)return ;
	Node_Print(t->left,metadata);

	Record* r=(Record*)(t+1);
	Record_print(r,metadata);
	Node_Print(t->right,metadata);
}
