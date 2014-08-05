/*Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.
*/

#include<iostream>

using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* create_tree(int data)
{
	struct tree *node=new struct tree;
	
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	
	return node;
}

struct tree * build_tree(int arr[],int start,int end)
{
	if(start>end)
		return NULL;
		
	int mid=start+(end-start)/2;
	
	struct tree* root=create_tree(arr[mid]);
	
	root->left=build_tree(arr,start,mid-1);
	root->right=build_tree(arr,mid+1,end);
	
	return root;
}

void inorder(struct tree * root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

void postorder(struct tree * root)
{
	if(root==NULL)
		return;
	cout<<root->data<<"->";		
	postorder(root->left);
	postorder(root->right);

}

int main()
{
	int arr[]={1, 2, 3, 4, 5, 6, 7};
	int n=7;
	
	struct tree *root= build_tree(arr,0,n-1);
	
	inorder(root);	
	cout<<"\n ";
	postorder(root);
}
