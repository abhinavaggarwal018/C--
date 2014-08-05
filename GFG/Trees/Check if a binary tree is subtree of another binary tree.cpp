#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* A utility function to check whether trees with roots as root1 and
   root2 are identical or not */
bool isIdentical(struct node * root1, struct node *root2)
{
    /* base cases */
    if(root1 == NULL && root2 == NULL)
        return true;
 
    if(root1 == NULL || root2 == NULL)
        return false;
 
    /* Check if the data of both roots is same and data of left and right
       subtrees are also same */
    return (root1->data == root2->data   &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right) );
}
 
 
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(struct node *T, struct node *S)
{
	if(T==NULL)
		return true;
		
	if(S==NULL)
		return false;
		
	if(T->data == S->data)
		if(isIdentical(T,S))
			return true;
	return isIdentical(T->left,S)|isIdentical(T,S->left);
}
 
 
/* Helper function that allocates a new node with the given data
   and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
 
/* Driver program to test above function */
int main()
{
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if( isSubtree(T, S) )
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");
 
    getchar();
    return 0;
}
