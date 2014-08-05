/*
http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
Convert a given Binary Tree to Doubly Linked List
April 1, 2013

Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
*/

#include<stdio.h>
#include<iostream>

using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree* create_tree(int val)
{
	struct tree *node=new struct tree;
	
	node->data=val;
	
	node->left=NULL;
	node->right=NULL;
}

struct tree* convert_to_dll(struct tree* node,char c)
{
	/*if(node==NULL)
		return node;
	
	if(node->left!=NULL)
	{
		struct tree *left1=convert_to_dll(node->left);
		while(left1->right!=NULL)
			left1=left1->right;
		node->left=left1;
	}
	
	if(node->right!=NULL)
	{
		struct tree *right1=convert_to_dll(node->right);
		while(right1->left!=NULL)
			right1=right1->left;
		node->right=right11;
	}
	
	return node;*/
	
	if(node==NULL)
		return node;
	
	cout<<"Called for data node->data: "<<node->data<<"\n";
	
	if(node->left!=NULL)
	{
		node->left=convert_to_dll(node->left,'l');
		node->left->right=node;
	}
	
	if(node->right!=NULL)
	{
		node->right=convert_to_dll(node->right,'r');
		node->right->left=node;
	}

	if(c=='l' && node->right!=NULL)
		return node->right;
	
	if(c=='r' && node->left!=NULL)
		return node->left;
		
	return node;
}

int main()
{
			
	struct tree *root=create_tree(7);
	//cin>>num;
	//while
	//(num--)
	//{
		root->left=create_tree(3);
		root->right=create_tree(11);
		
		root->left->left=create_tree(1);
		root->left->right=create_tree(5);
		
		root->left->left->left=create_tree(0);
		root->left->left->right=create_tree(2);

		root->left->right->left=create_tree(4);
		root->left->right->right=create_tree(6);
		
		root->right->left=create_tree(9);
		root->right->right=create_tree(13);
		
		root->right->left->left=create_tree(8);
		root->right->left->right=create_tree(10);
		
		root->right->right->left=create_tree(12);
		root->right->right->right=create_tree(14);
	
    
	root=convert_to_dll(root,'l');
	
	struct tree* temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
		
	while(root->left!=NULL)
		root=root->left;
		
	struct tree * head=root;
	
	temp->right=head;
	head->left=temp;

	root=root->right;
		
	int cnt=10;
	
	while(cnt)
	{
		cnt--;
		cout<<head->data;
		head=head->right;
	}
}
