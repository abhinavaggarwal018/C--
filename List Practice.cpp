#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list *next;
	struct list *left;
	struct list *right;
};


struct list *create_list(int data)
{
	struct list *node=new struct list;
	node->data=data;
	node->next=NULL;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}

struct list *create1()
{
	struct list *node=create_list(0),*head;
	head=node;
	
	int n=5;
	while(n--)
	{
		node->next=create_list(10-2*n);
		node=node->next;
	}
	
	return head;
}

struct list *create2()
{
	struct list *node=create_list(1),*head;
	head=node;
	
	int n=5;
	while(n--)
	{
		node->next=create_list(11-2*n);
		node=node->next;
	}
	
	return head;
}

void display(struct list *head)
{
	int n=100;
	
	while(n-- && head)
	{
		cout<<head->data;
		head=head->next;
	}
	
	cout<<"\n\n";
}

struct list *merge(struct list *head1, struct list *head2)
{
	if(head1==NULL)
		return head2;
	
	if(head2==NULL)
		return head1;
		
	if(head1->data <= head2->data)
	{
		head1->next=merge(head1->next,head2);
		return head1;
	}
	
	if(head1->data > head2->data)
	{
		head2->next=merge(head1, head2->next);
		return head2;
	}
}

int main()
{
	struct list *head1, *head2, *head;
	head1=create1();
	head2=create2();
	head=merge(head1, head2);
	display(head);	
}
