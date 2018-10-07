#include <iostream>
#include <queue>
using namespace std;
/*
								15
							   /  \
							 10	   25
							/ \   /	 \
						   2  14 19   26
						    \    /
						     4  16
						         \
						         17

*/

struct node{
	int data;
	node* left;
	node* right;
};


node* getnewnode(int data){
	node* newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* insert(node* root, int data){
	if(root == NULL){
		root=getnewnode(data);
		
	}
	else if(data <=root->data){
		root->left=insert(root->left,data);
		
	}
	else{
		root->right=insert(root->right,data);
		
	}
	return root;
}
void inorder(node* root){
	if(root==NULL) return;
	node* temp=root;
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}

void preorder(node* root){
	if(root==NULL) return;
	node* temp=root;
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}

void postorder(node* root){
	if(root==NULL) return;
	node* temp=root;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=getnewnode(15);
	root=insert(root,10);
	root=insert(root,25);
	root=insert(root,2);
	root=insert(root,19);
	root=insert(root,26);
	root=insert(root,4);
	root=insert(root,16);
	root=insert(root,14);
	root=insert(root,17);
	cout<<"Inorder Traversal : ";
	inorder(root);
	cout<<endl;
	cout<<"preorder Traversal : ";
	preorder(root);
	cout<<endl;
	cout<<"postrder Traversal : ";
	postorder(root);
	cout<<endl;
	return 0;
}