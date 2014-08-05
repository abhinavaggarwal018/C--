#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* create_tree(int val)
{
	struct tree * node=new struct tree;
	
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	
	return node;	
}

vector<int> arr;

struct tree* create()
{
	struct tree *root=create_tree(7);
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
	
	return root;
}

void display_path(struct tree* root)
{
	if(root==NULL)
		return;
	
	if(root->left==NULL&&root->right==NULL)
	{
		arr.push_back(root->data);
		for(int i=0;i<arr.size();i++)
			cout<<arr[i];
		arr.pop_back();
		cout<<"\n";
		return;
	}
	
	if(root!=NULL)
	{
		struct tree *node=root;
		arr.push_back(node->data);
		display_path(node->left);
		display_path(node->right);
	}
}

int main()
{
	struct tree *root=create();
	display_path(root);
}
