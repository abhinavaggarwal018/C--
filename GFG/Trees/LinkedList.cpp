#include<iostream>
using namespace std;

struct list
{
	int data;
	struct list *next;

	list(int val)
	{
		data=val;
		next=NULL;
	}
};

struct list * getAlt(struct list *head, struct list **head1, struct list **head2)
{
	(*head1)=head;
	(*head2)=head->next;

	struct list *temp1,*temp2;

	temp1=(*head1);
	temp2=(*head2);

	while(head && head->next)
	{
		temp1 = head;
		temp2 = head->next;
		
		if(head->next)	
			head=head->next->next;
	}
	
	temp1->next=NULL;
	
	if(temp2)
		temp2->next=NULL;
}

struct list * reverseList(struct list *head)
{
	if(head==NULL)
		return NULL;
			
	struct list *node = reverseList(head->next);
	
	if(node)
		node->next = head;
		
	head->next=NULL;
}

void RevAltAndAppend(struct list *head)
{
	if(head==NULL)
		return;
		
	struct list *head1=NULL,*head2=NULL;
	
	getAlt(head,&head1,&head2);
	
	head2=reverseList(head2);
	
	struct list *temp=head1;
	
	while(temp->next)
		temp=temp->next;
		
	temp->next=head2;
}

void display(struct list *node)
{
	if(node==NULL)
		return;
		
	cout<<node->data<<"->";
	
	display(node->next);
}

int main()
{
	struct list *head = new list(1);
	head->next = new list(2);	
	head->next->next = new list(3);	
	head->next->next->next = new list(4);	
	head->next->next->next->next = new list(5);	
	head->next->next->next->next->next = new list(6);	
	head->next->next->next->next->next->next = new list(7);
	
	display(head);
	
//	RevAltAndAppend(head);	

	head=reverseList(head);	
	display(head);
	
}
