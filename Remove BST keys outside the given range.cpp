#include<abhinav.h>

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	return node;
}


int inorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
}

void delete_tree(struct tree *root)
{
	if(root==NULL)
		return;
	struct tree *left,*right;
	left=root->left;
	right=root->right;
	delete root;

	if(left)
		delete_tree(left);

	if(right)
		delete_tree(right);
}

struct tree* remove_keys(struct tree* root,int min,int max)
{
	if(root==NULL)
		return NULL;
	cout<<1;	
	if(root->data >= min && root->data <=max)
	{
		root->left=remove_keys(root->left,min,max);
		root->right=remove_keys(root->right,min,max);
		return root;
	}	
	cout<<2;
	if(root->data > max)
	{
		struct tree *temp=root->left;
		delete_tree(root->right);
		delete root;
		return remove_keys(temp,min,max);
	}
	cout<<3;
	if(root->data < min)
	{
		struct tree *temp=root->right;
		delete_tree(root->left);
		delete root;
		return remove_keys(temp,min,max);
	}
	cout<<4;
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

	root=remove_keys(root,10,1);
	
	inorder(root);
	cout<<"END\n";
}
