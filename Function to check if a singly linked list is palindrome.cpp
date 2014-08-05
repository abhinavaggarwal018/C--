#include<abhinav.h>

using namespace std;

struct list 
{
	char data;
	struct list *next;
};

struct list *create_list(char data)
{
	struct list *node= new struct list;
	
	node->next=NULL;
	node->data=data;
	
	return node;
}

void display(struct list *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->next;
	}
	
	cout<<"\n";
}

struct list *get_mid(struct list *head)
{
	if(head==NULL||head->next==NULL||head->next->next==NULL)
		return head;
		
	struct list *slow=head,*fast=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}	
	
	if(fast==NULL)
		return slow;
		 	
	return slow->next;
}

struct list* reverse(struct list *root,struct list *prev)
{
	if(root==NULL)
		return root;
		
	if(root->next==NULL)
	{
		root->next=prev;
		return root;
	}	
	
	struct list *temp=root->next;
	root->next=prev;
	return reverse(temp,root);
}

void check_palindrome(struct list *head)
{
	struct list* mid=get_mid(head);
	mid=reverse(mid,NULL);
	
	display(head);
	display(mid);
	
	while(mid!=NULL)
	{
		if(head->data=mid->data)
		{
			head=head->next;
			mid=mid->next;
		}
		
		else
		{
			cout<<"FALSE\n";
			return;
		}
	}
	
	cout<<"TRUE\n";
	return;
}

int main()
{

	struct list *head,*temp;
	head=create_list('R');
	temp=head;
	
	temp->next=create_list('A');
	temp=temp->next;
	
	temp->next=create_list('D');
	temp=temp->next;
	
	temp->next=create_list('D');
	temp=temp->next;

	temp->next=create_list('A');
	temp=temp->next;
	
	temp->next=create_list('R');
	temp=temp->next;
	
//	temp->next=create_list(36);
	
	display(head);
	temp=head;
	
	check_palindrome(head);
	
	stack<char> s;
	
	while(temp)
	{
		s.push(temp->data);
		temp=temp->next;
	}
	
	while(temp)
	{
		if(temp->data==s.top())
			temp=temp->next;
		else
		{
			cout<<"FALSE\n";
			break;
		}
	}
	
	if(temp==NULL)
		cout<<"TRUE\n";
}

