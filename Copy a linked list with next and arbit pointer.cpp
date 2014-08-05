/*
http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. 
The second pointer however CAN point to any node in the list and not just the previous node. 
Now write a program in O(n) time to duplicate this list. 
That is, write a program which will create a copy of this list.

*/
#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list* next;
	struct list* arbit;
};

struct list* create_list(int num)
{
	struct list* node = new struct list;
	
	node->next=NULL;
	node->arbit=NULL;	
	node->data=num;
	
	return node;
}

void display(struct list *head)
{
	cout<<"\n";
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	
	cout<<"END\n";
}

void display_arbit(struct list *head)
{
	if(head==NULL)
		cout<<"Head does not exist!";
		
	cout<<"\n";
	while(head!=NULL)
	{
		cout<<head->arbit->data<<"->";
		head=head->next;
	}
	
	cout<<"END\n";
}

void assign_arbit(struct list* head)
{
	head->arbit=head->next->next;
	head->next->arbit=head;
	head->next->next->arbit=head->next->next->next->next;
	head->next->next->next->arbit=head->next->next;
	head->next->next->next->next->arbit=head->next->next->next;
}

void display_address(struct list *node)
{
	if(node==NULL)
		return;
	cout<<node<<"\t"<<node->next<<"\t"<<node->arbit<<"\n";
	return display_address(node->next);
}


struct list* initialise()
{
	int n,num;
	struct list *head;
	
	cin>>n;
	
	if((n--)>0)
	{
		cin>>num;
		head=create_list(num);
	}
	
	while(n--)
	{
		struct list *temp=head;
		
		cin>>num;
		
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=create_list(num);
	}
	assign_arbit(head);
	return head;
}

struct list* concat(struct list*node1,struct list* node2)
{
	struct list *temp1,*temp2,*param1,*param2;
	
	param1=node1;
	param2=node2;
		
	while(param1!=NULL)
	{
		temp1=param1->next;
		temp2=param2->next;
		
		param1->next=param2;
		param2->next=temp1;
		
		param1=temp1;
		param2=temp2;
	}
	
	return node1;
}

struct list* break_list(struct list* root,struct list* head,struct list* new_head)
{
	struct list *temp=root->next;

	head=root;
	new_head=root->next;

	while(new_head!=NULL)
	{
		if(head->next)
			head->next=head->next->next;
		else
			head->next=NULL;
		
		if(new_head->next)
			new_head->next=new_head->next->next;
		else
			new_head->next==NULL;

		head=head->next;
		new_head=new_head->next;
	}

	new_head=temp;
	
	return new_head;
}

struct list* copy_list(struct list *head)
{
	struct list *new_head,*temp=head,*new_temp;
	
	if(head==NULL)
		return NULL;
	
	if(head!=NULL)
		new_head=create_list(head->data);
	
	new_temp=new_head;
		
	while(temp->next!=NULL)
	{
		temp=temp->next;
		
		while(new_temp->next!=NULL)
			new_temp=new_temp->next;
			
		new_temp->next=create_list(temp->data);
	}
	
	struct list *root=concat(head,new_head);
	
	temp=root;
	while(temp!=NULL)
	{
		temp->next->arbit=temp->arbit->next;
		temp=temp->next->next;
	}

	new_head=break_list(root,head,new_head);
	
	display_arbit(head);
	display_arbit(new_head);
	
	display_address(head);
	cout<<"\n";
	display_address(new_head);
}


int main()
{
	struct list *head=initialise();
	copy_list(head);
}
