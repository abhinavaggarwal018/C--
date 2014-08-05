#include<iostream>

using namespace std;

struct my_stack
{
	int data;
	my_stack *prev;
	my_stack *next;
}*head,*mid;

static int cnt=0;

struct my_stack* insert(int data)
{
	struct my_stack *node=new struct my_stack;
	node->data=data;
	
	node->next=NULL;
	node->prev=NULL;
	
	return node;
}

struct my_stack* push(int data)
{	
	if(cnt==0)
		head=insert(data);
	
	else
	{
		struct my_stack* node=insert(data);
		
		node->next=head;
		head->prev=node;
	
		head = node;
	}
	
	cnt++;
	
	if(cnt&1)
	{
		if(cnt==1)
			mid=head;
		else
			mid=mid->prev;
	}
}

int pop()
{
	int ans;
	if(head==NULL)
		return 0;
		
	struct my_stack* temp=head;
	
	ans=temp->data;
	
	head=head->next;
	delete temp;
	
	cnt--;
	
	if(cnt%2==0)
	{
		if(cnt==0)
			mid=NULL;
		else	
			mid=mid->next;
	}
	
	return ans;
}

void display(struct my_stack *node)
{
	if(node->next==NULL)
		return;
	while(node!=NULL)
	{
		cout<<node->data<<"->";
		node=node->next;
	}
	cout<<"\nmid->data"<<mid->data<<"\n";
}

int main()
{
    push(11);
	push(22);
    push(33);
	push(44);
    push(55);
    push(66);
    push(77);
    display(head);
    pop();
    display(head);
    pop();
    display(head);
    pop();
    display(head);
    pop();
    display(head);

}

