#include<abhinav.h>

using namespace std;

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

int preorder(struct tree*root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}

int postorder(struct tree*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"->";
	}
}

bool is_identical(struct tree *tree1, struct tree *tree2)
{
	if(tree1==NULL&&tree2==NULL)
		return true;
		
	if(tree1==NULL||tree2==NULL)
		return false;

	
		return (tree1->data==tree2->data)&is_identical(tree1->left,tree2->left)&is_identical(tree1->right,tree2->right);
		
	
}

bool is_subtree(struct tree *tree1,struct tree *tree2)
{
	cout<<1;
	if(tree1==NULL)
		return false;
		
	if(tree2==NULL)
		return true;
	cout<<2;
	if(is_identical(tree1,tree2))
		return true;
	cout<<3;	
	return (is_subtree(tree1->left,tree2)||is_subtree(tree1->right,tree2));
}

int main()
{
	struct tree *n1 = create_tree(1);
    n1->left        = create_tree(2);
    n1->right       = create_tree(3);
    n1->left->left  = create_tree(4);
    n1->left->right = create_tree(5);
    n1->right->left  = create_tree(6);
    n1->left->right->left = create_tree(7);
    n1->left->right->right = create_tree(8);
 
    struct tree *n2 = create_tree(5);
    n2->left         = create_tree(7);
    n2->right        = create_tree(8);

	cout<<is_subtree(n1,n2);
}
