#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list* next;
};

struct list* create_list(int num)
{
	struct list *node=new struct list;
	
	node->data=num;
	node->next=NULL;
	
	return node;		
}

void make_circular (struct list* &head)
{
	struct list * node=head;
	
	if(node==NULL)
		return;
		
	while(node->next!=NULL)
	{
		node=node->next;
	}
	node->next=head;
}

void display(struct list* node)
{
	cout<<"\n";
	int num=100;
	while(node!=NULL&&num>0)
	{
		num--;
		cout<<node->data<<"->";
		node=node->next;
	}
	
	cout<<":END\n";
}

void reverse_list(struct list * &node,struct list* &start,int end)
{
	if(end==0||end==1)
		return ;
	
	cout<<"node:"<<node->data<<"start:"<<start->data<<"end:"<<end;
	
	struct list *temp,*temp1;
	end--;
	if(node->next!=NULL)
	{

		temp1= node;
		temp=node->next;
		//temp2=node->next->next;
		
		node->next=node->next->next;
		temp->next=start;
		
		start=temp;
		display(start);		
		return reverse_list(temp1,start,end);
	}
	cout<<"ERROR!!\n";
}

struct list* break_list(struct list * head)
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
	
	struct list* temp=node1;
	node1->next=head;
	
	if(node2->next==temp)
		node2->next=temp;
	else if(node2->next->next==temp)
		return temp;
}

struct list* reverse_list1(struct list *root,struct list *prev)
{

	if(root->next==NULL)
	{
		root->next=prev;
		return root;
	}
	
	struct list *root2= root->next->next,*root1=root->next;
	
	root->next->next=root;
	root->next=prev;
	
	if(root2!=NULL)
		return reverse_list1(root2,root1);
	else
		return root1;
}

void get_nth_node(struct list* head,int n)
{
	if(n<0)
	{
		cout<<"N must be greater than zero:END\n";
		return;
	}
	n--;
	while(head->next!=NULL&&n!=0)
	{
		n--;	
		head=head->next;
	}
	
	if(n==0)
		cout<<head->data<<":END\n";
	
	else
		cout<<"Such element does not exist!:END\n";
}

void delete_data_of_given_pointer(struct list* node_to_be_deleted)
{
	if(node_to_be_deleted==NULL)
		return;
		
	else if(node_to_be_deleted->next==NULL)
		node_to_be_deleted=NULL;
		
	else 
	{
		struct list*temp=node_to_be_deleted->next;
		
		node_to_be_deleted->data=temp->data;
		node_to_be_deleted->next=temp->next;
		
		delete temp;
	}
	
	return;
}

struct list * reverse_alternate(struct list * head,int k)
{
	struct list *root=head,*temp=root->next,*prev=NULL;
	int flag=1,num=k;
	
	display(root);
	flag=1;

	num=k;
	while(num>0&&root->next!=NULL)
	{
		num--;
		temp=root->next;
		temp->next=prev;
		prev=root;
		root=temp;
	}
	
	head->next=root;
	num=k;
	while(num>0 && root->next!=NULL)
		{
			num--;
			cout<<5;
			root=root->next;
		}
	cout<<6;

	if(root->next!=NULL)
		root->next=reverse_alternate(root->next, k);
	
	else
		root->next=prev;
	return prev;
}

struct list *k_alt_reverse(struct list *head, int k)
{
    struct list* current = head;
    struct list* next;
    struct list* prev = NULL;
    int count = 0;  
 
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
   
    /* 2) Now head points to the kth node.  So change next
       of head to (k+1)th node*/
    if(head != NULL)
      head->next = current;  
 
    /* 3) We do not want to reverse next k nodes. So move the current
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
 
    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
    if(current !=  NULL)
       current->next = k_alt_reverse(current->next, k);
 
    /* 5) prev is new head of the input list */
    return prev;
}

void nth_from_end(struct list* node,int n)
{
	struct list *temp=node,*ans=node;
	
	if(NULL==node)
		return;
		
	while(n--)
	{
		temp=temp->next;
		
		if(temp==NULL&&n!=0)
		{
			cout<<"Node does not exist:END\n";
			return;
		}
	}
	
	while(temp!=NULL)
	{
		temp=temp->next;
		ans=ans->next;
	}
	
	cout<<ans->data<<":END\n";
	return;
}

void nth_from_end_recursive(struct list * node, int n)
{
	static int cnt=0;
	
	if(node==NULL)
		return;
		
	nth_from_end_recursive(node->next,n);
	
	if(++cnt==n)
		cout<<node->data<<":END\n";
}

void reverse_m_after_n(struct list *root,int m,int n)
{
	if(root==NULL)
		return ;
		
	struct list *temp=root,*prev=NULL,*next;
	int i=0;
	
	while(temp)
	{
		cout<<1;
		i=0;
		while(i<m && temp)
		{
			cout<<2;
			prev=temp;
			temp=temp->next;
			i++;
		}
		i=0;
		while(i<n && temp)
		{
			cout<<3;
			next=temp->next;
			temp->next=prev;
			prev=temp;
			temp=next;
			i++;
		}
		
	}
}

struct list* destroy(struct list * &node)
{
	struct list *curr=node;
	
	if(NULL==node)
		return node;
		
	curr=node->next;
	delete node;
	
	return destroy(curr);
}

void cnt_occurance(struct list *node,int num)
{
	int cnt=0;
	
	if(node==NULL)
	{
		cout<<0<<":END\n";
		return;
	}
	
	while(node!=NULL)
	{
		if(node->data==num)
			cnt++;
		node=node->next;
	}
	
	cout<<cnt<<":END\n";
	return;
}

struct list* reverse_linked_list_recursive(struct list *prev,struct list *node)
{
	if(node==NULL)
	{
		return prev;
	}
	struct list* temp;
	
	temp=node->next;
	node->next=prev;
	
	return reverse_linked_list_recursive(node,temp);
}

struct list* reverse_linked_list(struct list *head)
{
	if(head==NULL)
		return head;

	struct list *node=head,*temp=head,*prev=NULL;
		
	while(temp!=NULL)
	{
		temp=node->next;
		node->next=prev;
		prev=node;
		node=temp;
	}
	
	return prev;
}

void detect_loop(struct list *node)
{

	struct list *temp=node,*fast=node->next->next,*slow=node;
	
	if(node==NULL)
	{
		cout<<"Empty List!!!:END\n";
		return;
	}
	
	while(fast!=NULL && fast->next!=NULL && fast!=slow)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	if(fast==NULL||fast->next==NULL)
		cout<<"The list has no loop!:END\n";
	
	else
		cout<<"The list has a loop";
	
	return;
}

int main()
{
	int n,num;
	struct list *head=NULL;
	
	cin>>n;
	
	if((n--)>0)
	{
		cin>>num;
		head=create_list(num);
	}
	
	struct list *temp=head;
	
	while(n--)
	{
		temp=head;
		cin>>num;
		
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=create_list(num);
	}
	
	display(head);

	reverse_m_after_n(head,3,4);
	
//	head=reverse_list1(head,NULL);
	
	display(head);
	
	detect_loop(head);
	display(head);
	
	int end;
	cin>>end;
	reverse_list(head,head,end);
	
	display(head);
	head=k_alt_reverse(head,end);	
	display(head);
	
	reverse_alternate(head,end);
	display(head);
	head=reverse_linked_list(head);
	display(head);
	
	head=reverse_linked_list_recursive(NULL,head);
	display(head);

	cin>>n;
	nth_from_end(head,n);
	
	cin>>n;
	nth_from_end_recursive(head,n);
	
	cin>>n;
	get_nth_node(head,n);
	
	cin>>n;
	cnt_occurance(head,n);
	
	temp=head->next->next->next;
	delete_data_of_given_pointer(temp);
	display(head);
/*
	make_circular(head);
*/
	
	head=destroy(head);
	display(head);
}
