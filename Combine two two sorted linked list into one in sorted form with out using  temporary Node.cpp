#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list* next;
};

struct list* create_list(int num)
{
	struct list *node=new struct list;
	
	node->data=num;
	node->next=NULL;
	
	return node;		
}

void display(struct list* node)
{
	cout<<"\n";
	int num=100;
	while(node!=NULL&&num>0)
	{
		num--;
		cout<<node->data<<"->";
		node=node->next;
	}
	
	cout<<":END\n";
}

struct list * merge_sorted(struct list *head1,struct list *head2)
{
	if(head1==NULL)
		return head2;
		
	if(head2==NULL)
		return head1;
		
	if(head1->data <= head2->data)
	{
		head1->next=merge_sorted(head1->next,head2);
		return head1;
	}
	
	if(head1->data > head2->data)
	{
		head2->next=merge_sorted(head1,head2->next);
		return head2;
	}
}

int main()
{
	struct list *head1=NULL,*head2=NULL,*head;

	int n=10;
	head1=create_list(1);
	
	struct list *temp=head1;
	
	for(int i=1;i<10;i++)
	{
		temp->next=create_list(2*i + 1);
		temp=temp->next;
	}
	
	head2=create_list(0);
	
	temp=head2;
	
	for(int i=1;i<10;i++)
	{
		temp->next=create_list(2*i);
		temp=temp->next;
	}
	
	display(head1);
	display(head2);
	
	head=merge_sorted(head1,head2);
	
	display(head1);
	display(head2);
	display(head);
	
}
