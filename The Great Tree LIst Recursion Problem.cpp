#include<abhinav.h>

using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
}*mid=NULL;



struct tree* create_tree(int data)
{
	struct tree *node= new struct tree;
	
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	
	return node;
}
struct tree* tree_to_list_right(struct tree**);
struct tree* tree_to_list_left(struct tree** root)
{
	if((*root)==NULL)
		return NULL;
		
	struct tree *left,*right;
	left=tree_to_list_left(&((*root)->left));
	
	if(left)
		left->right=(*root);
	
	(*root)->left=left;
	
	right=tree_to_list_right(&((*root)->right));
	
	(*root)->right=right;
	
	if(right)
		right->left=(*root);
	
	if(right)
	{
		struct tree *root1=*root;
		while((root1)->right!=NULL)
			(root1)=(root1)->right;
		
		return root1;
	}
	return (*root);
}

struct tree* tree_to_list_right(struct tree** root)
{
	if((*root)==NULL)
		return NULL;
		
	struct tree *left,*right;
	left=tree_to_list_left(&((*root)->left));
	
	if(left)
		left->right=(*root);
	
	(*root)->left=left;
	
	right=tree_to_list_right(&(*root)->right);
	
	(*root)->right=right;
	
	if((*root)&&(*root)->left&&(*root)->right)
	cout<<(*root)->data<<" \t: \t"<<(*root)->left->data<<" vs "<<left->data<<"\t:\t"<<(*root)->right->data<<" vs "<<right->data<<"\n";
	
	if(right)
		right->left=(*root);
	
	if(left)
	{
		struct tree *root1=*root;
		while((root1)->left!=NULL)
			(root1)=(root1)->left;
	
		return root1;
	}
	
	return (*root);
}
/*
				 7
		    3        11
		 1    5    9    13
		0 2  4 6  8 10 12 14 
										*/

void inorder(struct tree* root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

void display(struct tree* root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	cout<<"END\n";
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
		//root->right=insert(root->right,b);
	//}

	//cout<<root->right;
	inorder(root);
	cout<<"END\n";
	
	struct tree* root1;
	root1=tree_to_list_right(&(root));
	display(root1);
}
