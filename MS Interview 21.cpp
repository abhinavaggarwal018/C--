#include<iostream>

struct list
{
	int data;
	struct list *next;
};

int n;

struct list *create()
{
	
	scanf("%d",&n);
	struct list *start,*prev=new struct list;
	scanf("%d",&val);
	prev->data=val;
	prev->next=prev;
	start=prev;
	
	while(--n)
	{
		scanf("%d",&val);
		struct list *node=new struct list;
		node->data=val;
		prev->next=node;
		node->next=start;
		prev=node;
	}
}

struct list *display(int n,struct list *head)
{
	n+=2;
	
	while(n--)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"\n";
}

struct list *insert(struct list *head)
{
	struct list *slow=head,*fast=head->next,*node1=head,*node2=head->next;
	
	int n=1;
	
	while(slow!=fast)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	
	
}

