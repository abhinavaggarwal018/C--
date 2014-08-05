#include<iostream>

using namespace std;

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *next;
};

struct tree* create_node(int val)
{
	struct tree* node=new struct tree;
	
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	node->next=NULL;
	
	return node;
}

struct tree *inorder(struct tree *root)
{
	if(root==NULL)
		return NULL;
	
	if(root->left)
		inorder(root->left)->next=root;
	
	if(root->right)
		root->next=inorder(root->right);
	
	if(!root->right)
		root->next=NULL;
	
	return root;
}

struct tree *display(struct tree *root)
{
	while(root->left)
		root=root->left;
	
	while(root->next)
	{
		cout<<root->data<<"->";
		root=root->next;
	}
	cout<<root->next;
	cout<<root->right;
}
	
int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct tree *root = create_node(10);
    root->left        = create_node(8);
    root->right       = create_node(12);
    root->left->left  = create_node(3);
 
    // Populates nextRight pointer in all nodes
    inorder(root);
    display(root);
}
