#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list *next;
}*head;

struct list * create_node(int num)
{
	struct list * node=new struct list;
	node->data=num;
	node->next=NULL;
}

struct list* display(struct list *head1)
{
	while(head1)
	{
		cout<<head1->data<<"->";
		head1=head1->next;
	}
	cout<<" :END\n";
}

void remove_duplicates(struct list * head)
{
	struct list* temp=head,*trash;

	if(NULL==head)
	{
		cout<<"Head is NULL\n";
		return;
	}	
	
	while(temp->next)
	{
		if(temp->data==temp->next->data)
		{
			trash=temp->next;
			temp->next=temp->next->next;
			delete trash;
		}
		else 
			temp=temp->next;
	}
	display(head);	
}

void initialise()
{
	struct list *head=create_node(0),*temp=head;
	int num=15,i=1;
	while(num)
	{
		temp->next=create_node(i);
		temp=temp->next;
		num--;
	
		if(num==1)
			i=6;
		if(num>1)
			i=5;
		if(num>3)
			i=4;
		if(num>7)
			i=3;
		if(num>=10)
			i=2;
	
	}
	
	display(head);
	remove_duplicates(head);
}

int main()
{
	initialise();
}
