/*
Write a function to get the intersection point of two Linked Lists.
There are two singly linked lists in a system. 
By some programming error the end node of one of the linked list got linked into the second list, forming a inverted Y shaped list. 
Write a program to get the point where two linked list merge. 
*/
#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list *next;
}*head1,*head2;

struct list* add_node(int num)
{
	struct list * node=new struct list;
	node->data=num;
	node->next=NULL;
}

struct list* display(struct list *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<"END\n";
}

int length(struct list *head)
{
	int cnt=0;
	while(head!=NULL)
	{
		cnt++;
		head=head->next;
	}
	return cnt;
}

void display_address(struct list *node)
{
	if(node==NULL)
		return;
	
	cout<<node<<"\t"<<node->next<<"\n";
	return display_address(node->next);
}

struct list* initialise()
{
	int n,num;
	cin>>n;
	
	struct list *temp,*temp2;
	
	n--;
	cin>>num;
	head1 = add_node(num);
	
	temp=head1;
	
	while(n--)
	{
		cin>>num;
		
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=add_node(num);
		temp2=temp->next;
	}
	
	cin>>n;
	
	n--;
	cin>>num;
	head2 = add_node(num);
	
	temp=head2;
	
	while(n--)
	{
		cin>>num;
		
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=add_node(num);
		temp=temp->next;
	}
	temp2->next=temp;
	
	cin>>n;
	
	while(n--)
	{
		cin>>num;
		
		while(temp2->next!=NULL)
			temp2=temp2->next;
			
		temp2->next=add_node(num);
	}
	
	display(head1);
	display(head2);
	
//	display_address(head1);
//	display_address(head2);
}

void get_intersection()
{
	struct list *temp1=head1,*temp2=head2;
	int l1=length(head1);
	int l2=length(head2);
	
	if(l1>l2)
	{
		for(int i=0;i<l1-l2;i++)
			temp1=temp1->next;
		
		if(length(temp1)!=length(temp2))
			cout<<"ERROR!!!";
	}
	
	if(l2>l1)
	{
		for(int i=0;i<l2-l1;i++)
			temp2=temp2->next;
		
		if(length(temp1)!=length(temp2))
			cout<<"ERROR!!!";
	}
	
	while(temp1!=NULL)
	{
		if(temp1==temp2)
			{
				cout<<"The linked list meet at node with data:"<<temp1->data<<" :END\n";
				return;
			}
		temp1=temp1->next;
		temp2=temp2->next;
	}
}

int main()
{
	initialise();
	get_intersection();
}
