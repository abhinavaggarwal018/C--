#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct tree
{
	int data;
	int height;
	struct tree * left;
	struct tree * right;
};

struct tree * create_tree(int val)
{
	struct tree * node= new struct tree;
	
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	node->height=1;
	
	return node;
}

void pre_order(struct tree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

int height(struct tree *root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;
}

struct tree *right_shift(struct tree *root)
{
	struct tree *node=root->left;
	struct tree *t=node->right;
	
	root->left=t;
	node->right=root;
	
	root->height=max(height(root->left),height(root->right))+1;
	node->height=max(height(node->left),height(node->right))+1;

	return node;
}

struct tree *left_shift(struct tree *root)
{
	struct tree *node=root->right;
	struct tree *t=node->left;
	
	root->right=t;
	node->left=root;
	
	root->height=max(height(root->left),height(root->right))+1;
	node->height=max(height(node->left),height(node->right))+1;

	return node;
}

struct tree * insert(struct tree *root, int data)
{

	if(root==NULL)
		return create_tree(data);
	
	else if(root->data < data)
		root->right=insert(root->right,data);
		
	else
		root->left=insert(root->left,data);

	root->height=max(height(root->left),height(root->right))+1;
	
	int balance;	
	balance=height(root->left)-height(root->right);
	

	if(balance > 1 && root->left->data > data)
		return right_shift(root);
		
	if(balance > 1 && root->left->data < data)
	{
		root->left=left_shift(root->left);
		return right_shift(root);
	}
		
	if(balance < -1 && root->right->data > data)
	{
		root->right=right_shift(root->right);
		return left_shift(root);
	}
	
	if(balance < -1 && root->right->data < data)
	{
		return right_shift(root);
	}

	return root;
}

struct tree *delete_node(struct tree *root, int data)
{
	if(root==NULL)
	{
		cout<<"Element not present:\n";
		return root;
	}
	
	if(root->data < data)
		root->right=delete_node(root->right,data);
		
	else if(root->data > data)
		root->left=delete_node(root->left,data);
		
	else if(root->data==data)
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		
		if(root->left && !root->right)
		{
			delete root;
			return root->left;
		}
		
		if(root->right && !root->left)
		{
			delete root;
			return root->right;
		}
		
		else
		{
			root->data=root->right->data;
			return delete_node(root->right,root->right->data);
		}
	}
	
	root->height=max(height(root->left),height(root->right))+1;
	
	int balance=height(root->left)-height(root->right);
	int balance_left=height(root->left->left)-height(root->left->right);
	int balance_right=height(root->right->left)-height(root->right->right);
	
	if(balance > 1 && balance_left>=0)
		return right_shift(root);
		
	if(balance > 1 && balance_left<0)
	{
		root->left=left_shift(root->left);
		return right_shift(root);
	}
		
	if(balance < -1 && balance_right>=0)
	{
		root->right=right_shift(root->right);
		return left_shift(root);
	}
	
	if(balance < -1 && balance_right<0)
	{
		return right_shift(root);
	}

	return root;
	
	
}

int main()
{
  struct tree *root = NULL;
 
  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 
    printf("Pre order traversal of the constructed AVL tree is \n");
    pre_order(root);
 
    root = delete_node(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    printf("\nPre order traversal after deletion of 10 \n");
    pre_order(root);
 
    return 0;
}
