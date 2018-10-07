#include <iostream>
using namespace std;

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

int findmin(node* root){
	if(root==NULL) return -1;
	else if(root->left==NULL) return root->data;
	else return findmin(root->left);
}

int findminIterative(node* root){
	if(root==NULL) return -1;
	node* temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp->data;
}

int findmaxIterative(node* root){
	if(root==NULL) return -1;
	node* temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp->data;
}

int findmax(node* root){
	if(root==NULL) return -1;
	else if(root->right==NULL) return root->data;
	else return findmax(root->right);
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
	cout<<"Min element of the tree is : "<<findmin(root)<<endl;
	cout<<"Max element of the tree is : "<<findmax(root)<<endl;
	cout<<"Min element of the tree is : "<<findminIterative(root)<<endl;
	cout<<"Max element of the tree is : "<<findmaxIterative(root)<<endl;
	return 0;
}