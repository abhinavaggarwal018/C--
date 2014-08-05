#include<abhinav.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree * create_tree(int data)
{
	struct tree *node= new struct tree;
	
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	
	return node;
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int diameter(struct tree *root, int *dia)
{
	if(root==NULL)
		return 0;
	
	int height1,height2;
	
	height1=diameter(root->left,dia);
	height2=diameter(root->right,dia);
	
	*dia=height1+height2+1;

	return max(height1,height2)+1;
}

int main()
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
	
/*	root->right->left=create_tree(9);
	root->right->right=create_tree(13);
	
	root->right->left->left=create_tree(8);
	root->right->left->right=create_tree(10);
	
	root->right->right->left=create_tree(12);
	root->right->right->right=create_tree(14);
*/
	inorder(root);
	cout<<"END\n";

	int dia=0;
	diameter(root,&dia);
	cout<<dia;
}


