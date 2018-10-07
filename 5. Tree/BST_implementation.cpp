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

bool search(node* root,int data){
	if(root==NULL) return false;
	else if(root->data==data) return true;
	else if(data<=root->data) return search(root->left,data);
	else return search(root->right,data);
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
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int findheight(node* root){
	if(root==NULL) return -1;
	return max(findheight(root->left),findheight(root->right))+1;
}

void levelorderTraversal(node* root){
	if(root==NULL) return;
	queue <node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node* current=Q.front();
		cout<<current->data<<" ";
		if(current->left !=NULL)
			Q.push(current->left);
		if(current->right!=NULL)
			Q.push(current->right);
		Q.pop();
	}
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
bool subtreelesser(node* root, int data){
	if(root==NULL) return true;
	if((root->data <= data) && subtreelesser(root->left,data) &&
	 subtreelesser(root->right,data))
		return true;
	else
		return false;
}
bool subtreegreater(node* root, int data){
	if(root==NULL) return true;
	if((root->data > data) && subtreegreater(root->left,data) &&
		subtreegreater(root->right,data))
		return true;
	else
		return false;
}

bool IsBST(node* root){
	if(root==NULL) return true;
	if(subtreelesser(root->left,root->data) && subtreegreater(root->right,root->data)
		&& IsBST(root->left) && IsBST(root->right))
		return true;
	else
		return false;
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
	int n;
	cout<<"Enter the value to be searched : ";
	cin>>n;
	if(search(root,n)==true) cout<<"Found\n";
	else cout<<"Not Found\n";
	cout<<"Min element of the tree is : "<<findmin(root)<<endl;
	cout<<"Max element of the tree is : "<<findmax(root)<<endl;
	cout<<"Min element of the tree is : "<<findminIterative(root)<<endl;
	cout<<"Max element of the tree is : "<<findmaxIterative(root)<<endl;
	cout<<"height of the tree is : "<<findheight(root)<<endl;
	cout<<"Level order Traversal : ";
	levelorderTraversal(root);
	cout<<endl;
	cout<<"Inorder Traversal : ";
	inorder(root);
	cout<<endl;
	cout<<"preorder Traversal : ";
	preorder(root);
	cout<<endl;
	cout<<"postrder Traversal : ";
	postorder(root);
	cout<<endl;
	if(IsBST(root)==true) cout<<"It is a BST\n";
	else cout<<"It is not a BST\n";
	node* temp=Delete(root,2);
	cout<<temp->data<<endl;
	cout<<"Inorder Traversal : ";
	inorder(root);
	cout<<endl;
	cout<<"Level order Traversal : ";
	levelorderTraversal(root);
	cout<<endl;
	return 0;
}