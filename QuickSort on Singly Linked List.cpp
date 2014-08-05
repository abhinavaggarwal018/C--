#include<abhinav.h>

struct list
{
	int data;
	struct list *next;
};

struct list* create_list(int data)
{
	struct list *node= new struct list;
	
	node->next=NULL;
	node->data=data;
	
	return node;
}

void display(struct list *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<"->";
		root=root->next;
	}
	cout<<"END\n";
}

struct list* quick_sort(struct list *root, struct list *end)
{
	if(root==end)
		return root;
		
	struct list* pivot_prev;
/*	while(start->next!=end)
	{
		pivot_prev=start;
		start=start>next;
	}*/
	struct list *pivot=end,*start=root,*curr,*temp;
	
	while(start->data > pivot->data && start!=pivot)
	{
		pivot_prev=start;
		end->next=start;
		temp=start->next;
		start->next=NULL;
		start=temp;
		end=end->next;
	}
	
	curr=start;
	
	while(curr!=pivot)
	{
		pivot_prev=curr;
		
		if(curr->data <= pivot->data)
			curr=curr->next;
			
		else
		{
			end->next=curr;
			temp=curr->next;
			curr->next=NULL;
			curr=temp;
			end=end->next;
		}
	}
	
	quick_sort(start,pivot_prev);
	quick_sort(pivot->next,end);
}

int main()
{
	struct list *head=create_list(1),*temp=head;
	int i=10;
	while(i>0)
	{
		i++;
		temp->next=create_list(i*7 % 11);
	}
	display(temp);
}
