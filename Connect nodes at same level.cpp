#include<iostream>
#include<queue>

using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	struct tree* next;
};

struct tree* create_tree(int data)
{
	struct tree * node=new struct tree;
	
	node->data=data;
	
	node->left=NULL;
	node->right=NULL;
	node->next=NULL;
	
	return node;
}

//update_next

void level_order(struct tree *root)
{
	queue<struct tree *> q0,q1;
	bool temp=0; // temp=0 represents q0, temp=1 represents q1
	q0.push(root);
	
	while(temp==0&&!q0.empty()||temp==1&&!q1.empty())
	{
		struct tree *node;
		
		if(temp==0)
		{
			
			node=q0.front();
			q0.pop();
			
			if(node->left)
				q1.push(node->left);
				
			if(node->right)
				q1.push(node->right);
				
			if(q0.empty())
			{
				temp=1;
				node->next=NULL;
			}
			else	
				node->next=q0.front();

		}
		
		else if(temp==1)
		{

			node=q1.front();
			
			q1.pop();
			
			if(node->left)
				q0.push(node->left);
				
			if(node->right)
				q0.push(node->right);
				
			if(q1.empty())
			{
				temp=0;
				node->next=NULL;
			}
			else
				node->next=q1.front();

		}
	}
}

void preorder_fill(struct tree * root)
{
	if(root==NULL)
		return;
		
	if(root->left)
		root->left->next=root->right;
	
	if(root->right)
	{
		if(root->next)
			root->right->next=root->next->left;
		else
			root->right->next=NULL;
	}
	preorder_fill(root->left);
	preorder_fill(root->right);
}

void display(struct tree *root)
{
	
	while(root)
	{
		struct tree* temp=root;
		while(temp)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL\n";
		root=root->left;
	}
}

void iterative(struct tree * root)
{
	if(!root)
		return;
		
	struct tree* temp=root,*prev=root,*curr=root;	
		
	root->next=NULL;
	
	while(prev!=NULL)
	{
		curr=prev;
		prev=NULL;
		cout<<1;
		while(curr&&!prev)
		{
			if(curr->left)
				prev=curr->left;
			else if(curr->right)
				prev=curr->right;
			else
				curr=curr->next;
		}
		cout<<2;
		while(curr)
		{
			if(curr->left&&prev!=curr->left)
			{
				prev->next=curr->left;
				prev=curr->left;
			}
			
			if(curr->right&&prev!=curr->right)
			{
				prev->next=curr->right;
				prev=curr->right;
			}
			
			curr=curr->next; 
		}
		cout<<3;
		if(prev)
			prev->next=NULL;

	}
}

void modified_order(struct tree* root)
{
	if(!root)
		return;
		
	if(root->left)
		root->left->next=root->right;
		
	if(root->right)
	{
		if(root->next->left)
			root->right->next=root->next->left;
		else
			root->right->next=NULL;
	}
	
	modified_order(root->next);
	modified_order(root->left);
}



int main()
{
	struct tree *root=create_tree(1);
	root->left=create_tree(2);
	root->right=create_tree(3);
	
	root->left->left=create_tree(4);
	//root->left->left->right=create_tree(5);
	
	//root->right->left=create_tree(6);
	root->right->right=create_tree(7);
	
//	level_order(root);
//	preorder_fill(root);
//	modified_order(root);
	iterative(root);	
	display(root);
}
