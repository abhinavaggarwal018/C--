#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>


using namespace std;

struct list
{
	int data;
	struct list *next;
};

struct list * create_list(int data)
{
	struct list *node= new struct list;
	node->data=data;
	node->next=NULL;
}

struct list * segregate(struct list * root)
{
	if(root==NULL)
		return NULL;
	
	int data= root->data,cnt1=0,cnt2=0;
	struct list *head_even=NULL,*head_odd=NULL,*head_e,*head_o;
//	cout<<1;
	while(root)
	{
		if(root->data % 2 == 0)
		{
			
			if(cnt1==0)
			{
				head_even=root;
				head_e=head_even;
				cnt1=1;
			}
			else
			{ 
				head_even->next=root;
				head_even=head_even->next;
			}
			root=root->next;
		}
		
		else
		{

			
			if(cnt2==0)
			{
				head_odd=root;
				head_o=head_odd;
				cnt2=1;
			}
			else
			{
				head_odd->next=root;
				head_odd=head_odd->next;
			}
			root=root->next;
		}
	}
	
	head_odd->next=NULL;
	head_even->next=NULL;
//	cout<<1;	
	if(data%2 == 0)
	{
		head_even->next=head_o;
	//	head_e->next=head_o;
		return head_e;
	}
	
	else
	{
		head_odd->next=head_e;
	//	head_o->next=head_e;
		return head_o;
	}
	
}

void display(struct list *root)
{
	while(root)
	{
		cout<<root->data<<" ";
		root=root->next;
	}
}

int main()
{
	struct list *head=create_list(0);
	struct list *temp=head;
	
	for(int i=0;i<10;i++)
	{
		temp->next=create_list(i+1);
		temp=temp->next;
	}
	
	head=segregate(head);
	display(head);
}
