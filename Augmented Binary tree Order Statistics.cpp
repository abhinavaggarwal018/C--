#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<cassert>
#include<signal.h>
  
using namespace std;

int max_height=0,no_of_elements=0;

struct tree
{
	int data,nodes;
	struct tree *left,*right,*next;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	node->nodes=0;
	return node;
}


void inorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<":("<<root->nodes<<")->";
		inorder(root->right);
	}
}

int preorder(struct tree*root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}

void update_nodes(struct tree *root,int &cnt)
{
	if(root==NULL)
		return;
		
	update_nodes(root->left,cnt);	
	
	cnt++;
	root->nodes=cnt;
	
	update_nodes(root->right,cnt);
}

struct tree *insert(struct tree *root, int data)
{
	if(root==NULL)
		return create_tree(data);
	
	if(root->data > data)
		root->left=insert(root->left,data);
		
	if(root->data < data)
		root->right=insert(root->right,data);
	
	return root;
}

int find_element(struct tree *root, int k)
{
	if(root==NULL)
		return -1;
		
	if(root->nodes==k)
		return root->data;
		
	if(root->nodes < k)
		return find_element(root->right,k);
		
	if(root->nodes > k)
		return find_element(root->left,k);
}

int main()
{
	struct tree *root=NULL;
	
	root=insert(root,20);
	root=insert(root,8);
	root=insert(root,22);
	root=insert(root,4);
	root=insert(root,12);
	root=insert(root,10);
	root=insert(root,14);

	int cnt=0;
	update_nodes(root,cnt);
	
	inorder(root);

	for(int i=1;i<=7;i++)
		cout<<i<<": "<<find_element(root,i)<<"\n";
}
