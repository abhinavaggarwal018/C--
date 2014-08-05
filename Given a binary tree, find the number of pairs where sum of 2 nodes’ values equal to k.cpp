#include<iostream>
#include<stack>

using namespace std;
int n=0,arr[50],k,cnt=0;;
struct tree
{
	int data;
	struct tree *left,*right;
}*root;

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
		arr[n]=root->data;
		n++;
		cout<<root->data<<"("<<arr[n-1]<<")->";
		inorder(root->right);
	}
}

int inorder(int data)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		if(root->data==data)
			cnt++;
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

int check_sum(struct tree*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		inorder(k-(root->data));
	}
}

int  main()
{
	int val,num;
	cin>>k;
	//cin>>val;
	root=create_tree(7);
	//cin>>num;
	//while(num--)
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

	int p=0,q=n-1,cnt=0;
	
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<"->";
	}
	
	cout<<"END\n";
	
	for(int j=0;p<=q;j++)
	{
		if((arr[p]+arr[q])==k)
		{
			cnt++;
			p++;
			q--;
		}
		else if(arr[p]+arr[q]<k)
			p++;
		else 
			q--;
	}
	
	cout<<"The number of elements is:"<<cnt<<"\n";
	
	check_sum(root);
	cout<<"A"<<::cnt;
}



/*
				 7
		    3        11
		 1    5    9    13
		0 2  4 6  8 10 12 14*/
