#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<cassert>
#include<signal.h>
  
using namespace std;

int max_height=0,no_of_elements=0;

struct tree
{
	int data;
	struct tree *left,*right,*next;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	node->next=NULL;
	return node;
}


void inorder(struct tree *root)
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

void special_display(struct tree *root)
{
	if(root!=NULL)
	{
		special_display(root->left);
		
		cout<<root->data<<"->";
		
		if(root->next)
			cout<<root->next->data<<"\n";
		else
			cout<<"NULL\n";
		
		special_display(root->right);
	}
}

struct tree* create_temp()
{
	struct tree *root=create_tree(7);
	root->left=create_tree(3);
	root->right=create_tree(11);
	
	root->left->left=create_tree(1);
	root->left->right=create_tree(5);
	
//	root->left->left->left=create_tree(0);
//	root->left->left->right=create_tree(2);

	root->left->right->left=create_tree(4);
	root->left->right->right=create_tree(6);
	
	root->right->left=create_tree(9);
	root->right->right=create_tree(13);
	
	root->right->left->left=create_tree(8);
	root->right->left->right=create_tree(10);
	
	root->right->right->left=create_tree(12);
	root->right->right->right=create_tree(14);

	
/*	struct tree* root = create_tree(1);
    root->left = create_tree(2);
    root->right = create_tree(3);
    root->left->left = create_tree(4);
    root->left->right = create_tree(5);
    root->right->left = create_tree(6);
    root->right->right = create_tree(7);
    root->left->left->left = create_tree(8);
    root->left->right->right = create_tree(9);
    root->right->right->left = create_tree(10);
*/
	return root;
}


struct tree * connect_nodes_at_same_level_method1(struct tree *root)
{
	queue<struct tree *>q;
	q.push(root);
	int cnt=1;
	struct tree *temp=NULL;;
	while(!q.empty())
	{
		while(cnt--)
		{
			if(temp)
				temp->next=q.front();
				
			temp=q.front();
			q.pop();
			
			if(temp->left)
				q.push(temp->left);
				
			if(temp->right)
				q.push(temp->right);
		}
		
		temp=NULL;
		cnt=q.size();
	}
	
	return root;
}

void connect_nodes_at_same_level_method2(struct tree *root)
{
	if(root==NULL)
		return;
		
	connect_nodes_at_same_level_method2(root->next);
	
	if(root->left)
	{
		if(root->right)
		{
			root->left->next=root->right;
			
			if(!root->next)
				root->right->next=NULL;
			
			else if(root->next->left)
				root->right->next=root->next->left;
				
			else
				root->right->next=root->next->right;
		}
		
		else
		{
			if(!root->next)
				root->left->next=NULL;
			
			else if(root->next->left)
				root->left->next=root->next->left;
				
			else
				root->left->next=root->next->right;
		}

	}
	
	else if(root->right)
	{
		
		if(!root->next)
			root->right->next=NULL;
			
		else if(root->next->left)
			root->right->next=root->next->left;
			
		else
			root->right->next=root->next->right;
	}
	
	connect_nodes_at_same_level_method2(root->left);
	
}

struct tree * connect_nodes_at_same_level(struct tree *root)
{
	if(root==NULL)
		return NULL;
		
//	connect_nodes_at_same_level_method1(root);
	connect_nodes_at_same_level_method2(root);
}

int main()
{
	
	struct tree *root= create_temp(),*root2=NULL,*temp=NULL;
	
    connect_nodes_at_same_level(root);

    special_display(root);
    cout<<"\n";
    
      // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
	printf("nextRight of %d is %d \n", root->data,
           root->next? root->next->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->next? root->left->next->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->next? root->right->next->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->next? root->left->left->next->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->next? root->right->right->next->data: -1);
 	
	getchar();
	return 0;
}
