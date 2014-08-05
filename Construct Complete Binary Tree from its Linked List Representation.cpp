#include<abhinav.h>

using namespace std;

struct list 
{
	int data;
	struct list *next;
};

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct list *create_list(int data)
{
	struct list *node= new struct list;
	
	node->next=NULL;
	node->data=data;
	
	return node;
}

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

void display(struct list *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->next;
	}
	
	cout<<"\n";
}

int main()
{
	struct list *head,*temp;
	head=create_list(10);
	temp=head;
	
	temp->next=create_list(12);
	temp=temp->next;
	
	temp->next=create_list(15);
	temp=temp->next;
	
	temp->next=create_list(25);
	temp=temp->next;
	
	temp->next=create_list(30);
	temp=temp->next;
	
	temp->next=create_list(36);
	
	display(head);

	queue<struct tree*> q;
	
	struct tree* root=create_tree(head->data);
	head=head->next;
	q.push(root);

	while(head)
	{
		struct tree* node=q.front();
		q.pop();
		
		if(head!=NULL)
		{
			node->left=create_tree(head->data);
			head=head->next;
			q.push(node->left);
			
		}
		
		if(head!=NULL)
		{
			node->right=create_tree(head->data);
			head=head->next;
			q.push(node->right);
			
		}
	}
	
	inorder(root);
}
