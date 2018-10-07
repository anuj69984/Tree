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

node* insert(node* root,int data){
	if(root==NULL){
		root=getnewnode(data);
		//return root;
	} 
	else if(data<=root->data){
		root->left=insert(root->left,data);
		//return root;
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
void BFS(node* root){
	if(root==NULL) return;
	queue <node*> Q;
	Q.push(root);
	cout<<"Level order : ";
	while(!Q.empty()){
		node* temp=Q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL) Q.push(temp->left);
		if(temp->right!=NULL) Q.push(temp->right);
		Q.pop();
	}
	cout<<endl;
}
int max(int a, int b){
	if(a>b) return a;
	else return b;
}
int findheight(node* root){
	if(root==NULL) return -1;
	else
		return max(findheight(root->left),findheight(root->right))+1;
}
bool subtreelesser(node* root, int data){
	if(root==NULL) return true;
	if(root->data<=data && subtreelesser(root->left,data) &&
	 subtreelesser(root->right,data))
		return true;
	else return false;
}
bool subtreegreater(node* root,int data){
	if(root==NULL) return true;
	if(root->data > data && subtreegreater(root->right,data) &&
	 subtreegreater(root->left,data))
		return true;
	else return false;
}
bool IsBst(node* root){
	if(root==NULL) return true;
	if(IsBst(root->left) && IsBst(root->right) &&
	 subtreelesser(root->left,root->data) && subtreegreater(root->right,root->data))
		return true;
	else return false;
}

void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
node* findmin(node* root){
	if(root==NULL) return root;
	if(root->left==NULL) return root;
	else
		return findmin(root->left);
}
node* Delete(node* root,int data){
	if(root==NULL) return root;
	if(data < root->data){
		root->left=Delete(root->left,data);
	}
	else if(data > root->data){
		root->right=Delete(root->right,data);
	}
	else{
		if(root->right ==NULL && root->left==NULL){
			delete(root);
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
			node* temp=findmin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
}
int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=insert(root,12);
	root=insert(root,10);
	root=insert(root,8);
	root=insert(root,11);
	root=insert(root,15);
	root=insert(root,13);
	root=insert(root,16);
	inorder(root);
	cout<<endl;
	BFS(root);
	cout<<"Height of tree is : "<<findheight(root)<<endl;
	if(IsBst(root)==true) cout<<"It is a BST\n";
	else cout<<"It is not a BST\n";
	node* temp=Delete(root,13);
	BFS(root);

	return 0;
}