#include<iostream>
#include<cstdio>

using namespace std;

struct list
{
	int data;
	struct list* next;
};

struct list* create_node(int num)
{
	struct list *node=new struct list;
	
	node->data=num;
	node->next=node;
	
	return node;
}

void add_node(struct list* head,int num)
{
	struct list*node=head;
	
	while(node->next!=head)
		node=node->next;
		
	node->next=create_node(num);
	node->next->next=head;
}

void display(struct list* head)
{
	struct list*node=head->next;
	
	cout<<"\n"<<head->data<<"->";
	
	while(node!=head)
	{
		cout<<node->data<<"->";
		node=node->next;
	}
	
	cout<<"END\n";
}

struct list* break_list(struct list* head)
{
	struct list *node1=head,*node2=head;
	
	if(head==NULL)
	{
		cout<<"IMPOSSIBLE!! List empty!!!:END\n";
		return head;
	}
	
	if(head->next==head)
	{
		cout<<"IMPOSSIBLE!! List has only one element!!!:END\n";
		return head;
	}
	
	while ( node2->next!=head && node2->next->next!=head)
	{
		node1=node1->next;
		node2=node2->next->next;
	}
	
	struct list* temp=node1->next;
	
	node1->next=head;
	
	if(node2->next==head)
		node2->next=temp;
	
	else if(node2->next->next==head)
		node2->next->next=temp;
	
	return temp;
}

int main()
{
	struct list *head,*head1,*head2;
	int num,n,data;
	
	cin>>data;
	
	head=create_node(data);
	
	cin>>num;
	
	while(num--)
	{
		cin>>n;
		add_node(head,n);
	}
	
	display(head);
	
	cin>>n;
	
	head1=head;
	head2=break_list(head1);
	
	display(head1);
	display(head2);
}
