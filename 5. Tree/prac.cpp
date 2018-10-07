#include <iostream>
#include <queue>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
}; 

struct node* getnewnode(int data){
	node* newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insert(node* root, int data){
	if(root ==NULL){
		root=getnewnode(data);
	}
	else if(data <= root->data){
		root->left=insert(root->left,data);
	}
	else if(data > root->data){
		root->right=insert(root->right,data);
	}
	return root;
}
bool search(node* root,int data){
	if(root==NULL) return false;
	if(root->data ==data ) return true;
	if(data < root->data){
		return search(root->left,data);
	}
	else return search(root->right,data);
}
int findminIterative(node* root){
	if(root==NULL) return -1;
	if(root->right==NULL && root->left==NULL) return root->data;
	node* temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	return temp->data;
}
int findmaxIterative(node* root){
	if(root==NULL) return -1;
	if(root->left==NULL && root->right==NULL) return root->data;
	node* temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp->data;
}
int findminrecursive(node* root){
	if(root==NULL) return -1;
	if(root->left==NULL && root->right==NULL) return root->data;
	return findminrecursive(root->left);
}

int findmaxrecursive(node* root){
	if(root==NULL) return -1;
	if(root->left==NULL && root->right==NULL) return root->data;
	return findmaxrecursive(root->right); 
}
int max(int a, int b){
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
		node* temp=Q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			Q.push(temp->left);
		if(temp->right!=NULL)
			Q.push(temp->right);		
		Q.pop();
	}
}
void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
bool IsSubTreeLesser(node* root, int data){
	if(root==NULL) return true;
	if(root->data <= data && IsSubTreeLesser(root->right,data) &&
		IsSubTreeLesser(root->left,data))
		return true;
	else
		return false;	
}
bool IsSubTreeGreater(node* root, int data){
	if(root==NULL) return true;
	if(root->data > data && IsSubTreeGreater(root->right,data)&&
		IsSubTreeGreater(root->left,data))
		return true;
	else return false;
}
bool IsBst(node* root){
	if(root==NULL) return true;
	if(root->left==NULL && root->right==NULL ) return true;
	if(IsBst(root->left) && IsBst(root->right) &&
		IsSubTreeLesser(root->left,root->data) && IsSubTreeGreater(root->right,root->data))
		return true;
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
	if(data < root->data){
		root->left=Delete(root->left,data);
	}
	if(data > root->data){
		root->right=Delete(root->right,data);
	}
	else{
		if(root->left==NULL && root->right==NULL){
			delete(root);
			root=NULL;
		}
		else if(root->right==NULL){
			node* temp=root;
			root=root->left;
			delete(root);
		}
		else if(root->left==NULL){
			node* temp=root;
			root=root->right;
			delete(temp);
		}
		else{
			node* temp=Findmin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;

}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,25);
	root=insert(root,2);
	if(IsBst(root)==true)
		cout<<"It is a Binary Search Tree (BST)\n";
	else
		cout<<"Not a BST\n";
	cout<<"levelorderTraversal : ";
	levelorderTraversal(root);
	cout<<endl;
	cout<<"inorder : ";
	inorder(root);
	cout<<endl;
	cout<<"preorder : ";
	preorder(root);
	cout<<endl;
	cout<<"postorder : ";
	postorder(root);
	cout<<endl;
	cout<<"Height of the tree : "<<findheight(root)<<endl;
	int n;
	cout<<"Enter the number to be searched : ";
	cin>>n;
	if(search(root,n)==true) cout<<"found\n";
	else cout<<"not found\n";
	cout<<"Min element of the tree is : "<<findminIterative(root)<<endl;
	cout<<"Max element of the tree is : "<<findmaxIterative(root)<<endl;
	cout<<"Min element of the tree is : "<<findminrecursive(root)<<endl;
	cout<<"Max element of the tree is : "<<findmaxrecursive(root)<<endl;
	return 0;
}