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

	if(root==end||end->next==root)
		return root;
	
	if(end!=NULL)
		cout<<root->data<<":"<<end->data<<"\n";
	else
		cout<<root->data<<":NULL\n";
	struct list* pivot_prev;

	struct list *pivot=end,*start=root,*curr,*temp,*end_final;
	
	curr=start;
	
	display(start);
	pivot_prev=root;
	
	while(curr->data > pivot->data && curr!=pivot)
	{
		end->next=curr;
		temp=curr->next;
		curr->next=NULL;
		curr=temp;
		end=end->next;
	}
	
	start=curr;
	pivot_prev=curr;
	
	while(curr!=pivot)
	{
		if(curr->data <= pivot->data)
		{
			pivot_prev=curr;
			curr=curr->next;
		}
		else
		{
			end_final=end->next;
			end->next=curr;
			temp=curr->next;
			curr->next=end_final;
			pivot_prev->next=temp;
			curr=temp;
			end=end->next;
		}
		
		display(start);
	}

	display(start);
	cout<<start->data<<":"<<pivot_prev->data<<"::"<<pivot->next->data<<":"<<end->data<<"\n";	
	quick_sort(start,pivot_prev);
	quick_sort(pivot->next,end);
	
	return start;
}

int main()
{
	struct list *head=create_list(10),*temp=head;
	int i=10;
	while(i>0)
	{
		i--;
		temp->next=create_list(i);
		temp=temp->next;
	}
	display(head);
	head=quick_sort(head,temp);
	display(head);
}
