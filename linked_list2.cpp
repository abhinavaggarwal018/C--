#include<iostream>

/*16 — SortedIntersect()
Given two lists sorted in increasing order, create and return a new list representing the
intersection of the two lists. The new list should be made with its own memory — the
original lists should not be changed. In other words, this should be Push() list building,
not MoveNode(). Ideally, each list should only be traversed once. This problem along
with Union() and Difference() form a family of clever algorithms that exploit the
constraint that the lists are sorted to find common nodes efficiently.*/

using namespace std;

struct list
{
	int data;
	struct list *next;
}*head;

struct list * create_node(int num)
{
	struct list * node=new struct list;
	node->data=num;
	node->next=NULL;
}

struct list* display(struct list *head1)
{
	while(head1)
	{
		cout<<head1->data<<"->";
		head1=head1->next;
	}
	cout<<" :END\n";
}

struct list* merge(struct list* &start,struct list * &mid,struct list * &end)
{
	if(end!=NULL)
		cout<<"\nSTART of merge for start:"<<start->data<<"  mid:"<<mid->data<<"  end:"<<end->data<<"\n";
	else
		cout<<"\nSTART of merge for start:"<<start<<"  mid:"<<mid<<"  end:"<<end<<"\n";
	if(start==end||start->next==end)
		return start;
		
	if(start->next->next==end)
	{
		if(start->data>start->next->data)
		{
			int temp=start->data;
			start->data=start->next->data;
			start->next->data=temp;
			display(start);
			return start;
		}
	}
	struct list *temp1=start->next,*temp2=mid,*node,*new_head;
	
	while(temp1!=mid && temp2->next!=end)
	{
		if(temp1->data<=temp2->data)
		{
			node=create_node(temp1->data);
			temp1=temp1->next;
		}
		
		else
		{
			node=create_node(temp2->data);
			temp1=temp2->next;
		}
	
		node=node->next;	
	}
	
	while(temp1!=mid)
	{
		node=create_node(temp1->data);
		temp1=temp1->next;
	}
	
	while(temp2!=end)
	{
		node=create_node(temp2->data);
		temp2=temp2->next;
	}
	
	if(end!=NULL)
	cout<<"\nEND of merge for start:"<<start->data<<"  mid:"<<mid->data<<"  end:"<<end->data<<"\n";
	
	display(start);
	return start;
}

struct list *get_mid(struct list * head,struct list * end)
{
	if(head==end|| head->next==end)
		return head;	
	
	struct list *slow=head,*fast=head;
	while(fast!=end && fast->next!=end)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	return slow;
}

struct list* merge_sort(struct list* &head,struct list* &end)
{
	if(end==NULL)
		cout<<"struct list* merge_sort(struct list* &head):"<<head->data<<",struct list* &end):"<<end<<"\n";
	else
		cout<<"struct list* merge_sort(struct list* &head):"<<head->data<<",struct list* &end):"<<end->data<<"\n";
	
	struct list* mid=get_mid(head,end);
	cout<<mid->data;
	if(head!=end&&head->next!=end)
	{
		int n;
		cin>>n;
		merge_sort(head,mid);
		merge_sort(mid,end);
	}
		merge(head,mid,end);

}

void initialise()
{
	struct list *head=create_node(0),*temp=head,*end=NULL;
	int num=15,i=1;
	while(num)
	{
		temp->next=create_node(num);
		temp=temp->next;
		num--;
	}
	
	display(head);
	merge_sort(head,end);
	display(head);
}

int main()
{
	initialise();
}
