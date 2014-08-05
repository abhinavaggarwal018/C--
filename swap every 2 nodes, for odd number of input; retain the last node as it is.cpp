#include<iostream>
#include<stdio.h>

using namespace std;

struct list{
	int val;
	struct list *next;
};

struct list* getNode(int data)
{
	struct list* node=new list;
	node->val=data;
	node->next=NULL;
	return node;
}

void insert(struct list* &head,int data)
{
	struct list* curr=head;
	if(NULL==head)
	{
		head=getNode(data);
		return ;
	}
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=getNode(data);
}

void display(struct list* head)
{
	struct list* curr=head;
	if(curr==NULL)
	{
		cout<<"END\n";
		return;
	}
	cout<<curr->val<<"->";
	display(curr->next);
}


// 18,19 Rajasthali DDA Market
// Vishal 45577438,45577439
//WEEkdays 9-11am 4pm-6pm
//Weekend Saturdays->12noon-8pm
//sunday 10-2pm

struct list* swap_nodes(struct list* head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	if(head->next->next==NULL)
	{
		struct list* curr=head;
		struct list* next1=(head->next);
		
		curr=next1;
		next1->next=head;
		head->next=NULL;
		return curr;
	}	
	struct list* curr=head;
	struct list* next1=(head->next);
	struct list* next2=(head->next->next);
	
	cout<<head->val<<"\t"<<next1->val<<"\t"<<next2->val<<"\n";
	
	curr=next1;
	next1->next=head;
	head->next=swap_nodes(next2);
	return curr;
}


void delete1(struct list* head)
{
	struct list* curr = head;
	struct list* curr1;
	while(curr!=NULL)
	{
		curr1=curr->next;
		delete curr;
		curr=curr1; 
	}
}

int main()
{
	int n,val;
	struct list* head=NULL;
	cin>>n;
	while(n--)
	{
		cin>>val;
		insert(head,val);
	}
	display(head);
	head=swap_nodes(head);
	display(head);
	delete1(head);
}
