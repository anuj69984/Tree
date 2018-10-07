#include <iostream>
#include <queue>
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
	if(root==NULL){
		root=getnewnode(data);
	}
	else if(data <= root->data){
		root->left=insert(root->left,data);

	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void levelBylevel(node* root){
	if(root==NULL) return;
	queue <node*> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		node* temp=Q.front();
		if(temp==NULL){
			Q.push(NULL);
			Q.pop();
			cout<<endl;
			return;
		}
		cout<<temp->data<<" ";

		if(temp->left!=NULL) Q.push(temp->left);
		if(temp->right!=NULL) Q.push(temp->right);
		if(temp==NULL){
			Q.push(NULL);
			cout<<endl;
		}
		Q.pop();
	}
		
}
int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=insert(root,12);
	root=insert(root,8);
	root=insert(root,10);
	root=insert(root,7);
	root=insert(root,9);
	root=insert(root,25);
	root=insert(root,20);
	root=insert(root,26); 
	cout<<"Inorder : ";
	inorder(root);
	cout<<endl;
	cout<<"levelBylevel : ";
	levelBylevel(root);
	cout<<endl;
	return 0;
}
