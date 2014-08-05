#include<iostream>
#include<climits>
#include<cstdio>

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


int preorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}

void display(struct tree *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	
	cout<<"\n";
}

struct tree* to_list(struct tree *root)
{
	if(root==NULL)
		return root;
	
	struct tree *left,*right;
		
	left=to_list(root->left);
	right=to_list(root->right);
	
	root->left=root;
	root->right=root;
	
	struct tree* temp;
	
	if(left||right)
	{
		if(left)
		{
			left->left->right=root;
			root->left=left->left;
			root->right=left;
			left->left=root;
		}
		
		if(right)
		{
			temp=right->left;
			right->left=root;
			root->right=right;
		}
		
		if(left)
		{
			left->left=temp;
			temp->right=left;
		}
		
		if(!left)
		{
			root->left=temp;
			temp->right=root;
		}
	}
	else
		return root;
//	if(left && right)
	{
//		left->left->=right->right;
//		right->left=left->right;
	}
	
	return left;
}

void merge_list(struct tree *head1,struct tree *head2,struct tree **head)
{
	if(head1==NULL)
	{
		*head=head2;
		return;
	}
	
	if(head2==NULL)
	{
		*head=head1;
		return;
	}
		
	if(head1->data <= head2->data)
		*head=head1;
		
	struct tree *temp;
	
	if(head1->data > head2->data)
	{
		*head=head2;
		temp=head2->right;
		head2->right=head1;
		head1->left=head2;
		*head=head2;
		temp->left=NULL;
		head2=temp;
	}

	temp=*head;
	struct tree *temp1=*head,*temp2;

	while(head2!=NULL)
	{
		if(head2->data <= temp->right->data)
		{
			temp2=temp->right;
			temp->right=head2;
			head2->left=temp;
			temp1=head2->right;
			head2->right=temp2;
			temp2->left=head2;
			temp=temp->right;
			head2=temp1;
		}
		else
			temp=temp->right;
	}
	
}

struct tree *to_tree(struct tree **head,int n)
{
	if(n<=0)
		return NULL;
		
	struct tree *left=to_tree(head,n/2);
	
/*	(*head)=(*head)->right;
	if(!(*head))
		return left;
*/		
	struct tree *root = *head;
	
	(*head)=(*head)->right;
	
	root->left=left;
	root->right= to_tree(head,n-n/2-1);
	
	return root;
}

int main()
{
	struct tree *root1=create_tree(7);

	root1->left=create_tree(3);
	root1->right=create_tree(11);
	
	root1->left->left=create_tree(1);
	root1->left->right=create_tree(5);
	
	root1->left->left->left=create_tree(0);
	root1->left->left->right=create_tree(2);

	root1->left->right->left=create_tree(4);
	root1->left->right->right=create_tree(6);
	
	root1->right->left=create_tree(9);
	root1->right->right=create_tree(13);
	
	root1->right->left->left=create_tree(8);
	root1->right->left->right=create_tree(10);
	
	root1->right->right->left=create_tree(12);
	root1->right->right->right=create_tree(14);

	struct tree *root2=create_tree(7);

	root2->left=create_tree(3);
	root2->right=create_tree(11);
	
	root2->left->left=create_tree(1);
	root2->left->right=create_tree(5);
	
	struct tree *head1,*head2,*head,*root,*temp;
	
	head1=to_list(root1);	
	
	temp=head1;
	while(temp->right!=head1)
		temp=temp->right;
	temp->right=NULL;

	display(head1);
	
	head2=to_list(root2);

	temp=head2;
	while(temp->right!=head2)
		temp=temp->right;
	temp->right=NULL;

	display(head2);
	
	merge_list(head1,head2,&head);

	display(head);
		
	root=to_tree(&head,20);

	preorder(root);
}

