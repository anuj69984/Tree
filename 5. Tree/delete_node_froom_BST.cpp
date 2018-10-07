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

struct node* Findmin(node* root){
	if(root==NULL) return root;
	if(root->left==NULL) return root;
	else
		return Findmin(root->left);
} 

struct node* Delete(node* root, int data){
	if(root==NULL) return root;
	if(data<root->data){
		root->left=Delete(root->left,data);
	}
	else if(data>root->data){
		root->right=Delete(root->right,data);
	}
	else{
		// case 1: no child
		if(root->left==NULL && root->right==NULL){
			delete (root);
			root=NULL;
		}
		else if(root->left==NULL){
			node* temp=root;
			root=root->right;
			delete(temp);
			
		}
		else if(root->right ==NULL){
			node* temp=root;
			root=root->left;
			delete(temp);
			
		}
		else{
			node* x=Findmin(root->right);
			root->data=x->data;
			root->right=Delete(root->right,x->data);			
		}
	}
	return root;
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
	node* temp=Delete(root,2);
	cout<<temp->data<<endl;
	cout<<"Inorder Traversal : ";
	inorder(root);
	cout<<endl;
	return 0;
}