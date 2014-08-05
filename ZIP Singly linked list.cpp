#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list* next;
};

struct list* create_list(int val)
{
	if(val<=0)
		return NULL;
		
	struct list *node=new struct list;
	
	node->data=val;
	node->next=create_list(val-1);
	
	return node;
}

void display(struct list *head)
{
	if(head==NULL)
		return;
		
	cout<<head->data<<"->";
		
	return display(head->next);
}

void zip(struct list *head)
{
	if(head==NULL)
		return;
		
	if(head->next==NULL)
		return;
		
	if(head->next->next==NULL)
		return;

		
	struct list *temp=head->next,*end=head;
	
	while(end->next->next)
		end=end->next;
	
	head->next=end->next;
	head=head->next;
	head->next=temp;
	
	end->next=NULL;
	
	return zip(temp);
	
}

int main()
{
	int val;
	cin>>val;
	struct list* head=create_list(val);
	
	display(head);
	cout<<"\n";
	zip(head);

	display(head);
	cout<<"\n";
	
}
