#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct tree
{
	int ele;
	int data;
	int height;
	struct tree * left;
	struct tree * right;
};

struct tree * create_node(int val)
{
	struct tree * node= new struct tree;
	
	node->ele=0;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	node->height=1;
	
	return node;
}

void preOrder(struct tree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int height(struct tree *root)
{
	if(!root)
		return 0;
	
	return root->height;
}

int cnt(struct tree *root)
{
	if(!root)
		return 0;
	
	return root->ele;
}

struct tree* right_shift(struct tree *y) //call it by referance
{
	cout<<"R0";
	struct tree *x, *T2;
	cout<<"R1";
	x=y->left;
	cout<<"R1.5";
//	if(x)
	T2=x->right;
//	else 
//		T2=NULL;
	cout<<"R2";
//	if(x)
		x->right=y;
	
	y->left=T2;
	cout<<"R3";
	y->height=max(height(y->left),height(y->right))+1;
	cout<<"R3.5";
//	if(x)
	x->height=max(height(x->left),height(x->right))+1;
	cout<<"R4";
	
	x->ele=(cnt(x->left)+cnt(x->right))+1;
	y->ele=(cnt(y->left)+cnt(y->right))+1;
	return x;
}


struct tree* left_shift(struct tree *x)
{
	struct tree *y,*T2;
	cout<<"L1";
	y=x->right;
	T2=y->left;
	cout<<"L2";
	y->left=x;
	x->right=T2;
	cout<<"L3";
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	
	x->ele=(cnt(x->left)+cnt(x->right))+1;
	y->ele=(cnt(y->left)+cnt(y->right))+1;
	
	return y;
}

struct tree* insert_node(struct tree *root, int val, int *cnt1)
{
	if(root==NULL)
		return create_node(val);
	
	if(root->data<val)
	{
		cnt1+=cnt(root->left)+1;
		root->right=insert_node(root->right,val,cnt1);
	}
	else
		root->left=insert_node(root->left,val,cnt1);
	cout<<"H-1";
		
	root->height=max(height(root->left),height(root->right))+1;
		
	root->ele=cnt(root->left)+cnt(root->right)+1;
	
	cout<<"H0";
	int balance;
	
	if(!root)
		balance=0;
	else 
		balance=height(root->left)-height(root->right);
	
	if(balance==0||balance==1||balance==-1)
		return root;
	cout<<"H1";	
	
	cout<<"\nBALaNCE:"<<balance<<"\n";
	preOrder(root);
	cout<<"\n\n";
	if(balance>1 && root->left->data < val)
	{
		root->left=left_shift(root->left);
		return right_shift(root);
	}
	cout<<"H2";
	if(balance<-1 && root->right->data > val)
	{
		root->right=right_shift(root->left);
		return left_shift(root);
	}
	cout<<"H3";
	if(balance>1 && root->left->data > val)
		return right_shift(root);
	cout<<"H4";
	if(balance<-1 && root->right->data < val)
		return left_shift(root);
		
	cout<<"H5";
	
	return root;
}


 
// Drier program to test above function
int main()
{
	struct tree *root = NULL;
	int n, arr[100],num;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n;i++)
	{
		num=0;
		root=insert_node(root,arr[i],&num);
		cout<<"\n\nANS::"<<num<<"\n\n";
		
	}
/* 	cout<<1; 
  // Constructing tree given in the above figure 
  root = insert_node(root, 10,0);
   	cout<<1;
  root = insert_node(root, 20,0);
   	cout<<1;
  root = insert_node(root, 30,0);
   	cout<<1;
  root = insert_node(root, 40,0);
  root = insert_node(root, 50,0);
  root = insert_node(root, 25,0);
 */
   /*The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 	cout<<1;
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
 
  return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 

// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. 
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
struct node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST rotation 
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* 2. Update height of this ancestor node 
    node->height = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced 
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer 
    return node;
}*/
