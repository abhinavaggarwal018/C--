#include<iostream>

using namespace std;

struct list{
	int data;
	list *next;
};

struct list* insert(int val)
{
	struct list* node=new struct list;
	node->data=val;
	node->next=NULL;
	return node;
}

struct list* display(struct list* root)
{
	struct list *node=root;
	while(node!=NULL)
	{
		cout<<node->data<<"->";
		node=node->next;
	}
	cout<<"END\n";
}

void mid(struct list* root)
{
/*Question 1 : How to find middle element of linked list in one pass?
Read more: http://javarevisited.blogspot.com/2013/03/top-15-data-structures-algorithm-interview-questions-answers-java-programming.html#ixzz2WabOR664
*/
	struct list* node1=root->next,*node2=root->next->next;
	
	if(root==NULL)
	{
		cout<<"Does not exist\n";
		return;
	}
	
	if(node1==NULL||node2==NULL)
	{
		cout<<root->data<<":END\n";
		return;
	}
	
	if(node2->next==NULL)
	{
		cout<<node1->data<<":END\n";
		return;
	}
	//by varying last condition the number can be chosen for the odd number of terms comment &&node2->next->next!=NULL &see effect
	while(node1!=NULL&&node1->next!=NULL&&node2!=NULL&&node2->next!=NULL&&node2->next->next!=NULL)
	{
		node1=node1->next;
		node2=node2->next->next;
	}
	
	cout<<node1->data<<":END\n";
	return;
}

void third_from_last(struct list* root)
{
	/*How to find 3rd element from end in a linked list in one pass?

	Read more: http://javarevisited.blogspot.com/2013/03/top-15-data-structures-algorithm-interview-questions-answers-java-programming.html#ixzz2WadGUU8H
	*/
	if(root==NULL)
	{
		cout<<"List Empty!!! Less than 3 elements:END\n";
		return;
	}

	if(root->next==NULL)
	{
		cout<<"Less than 3 elements:END\n";
		return;
	}

	if(root->next->next==NULL)
	{
		cout<<"Less than 3 elements:END\n";
		return;
	}
	
	if(root->next->next->next==NULL)
	{
		cout<<"Less than3 elements:END\n";
		return;
	}
	
	struct list*node1=root,*node2=root->next->next->next;
	while(node2!=NULL)
	{
		node2=node2->next;
		node1=node1->next;
	}
		cout<<node1->data<<":END\n";
}

struct list* delete_node(struct list *root,int val)
{
	struct list* node=root,*node_prev=NULL;
	
	while(node->data!=val&&node->next!=NULL)
	{
		if(node_prev==NULL)
			node_prev=root;
		else
			node_prev=node_prev->next;
	
		node=node->next;
	}
	
	if(node==root)
		return root->next;
	
	if(node->next==NULL&&node->data!=val)
	{
		cout<<"Not foundin list:END\n";
		return root;
	}
	
	if(node->next==NULL&&node->data==val)
	{
		delete node;
		node_prev->next=NULL;
		return root;
	}
	
	else
	{
		node_prev->next=node->next;
		delete node;
		return root;
	}
}

struct list* reverse(struct list* root)
{
	struct list *curr,*prev,*temp;

	curr=root;
	
	if(curr==NULL)
		return NULL;
	
	if(curr->next==NULL)
		return curr;
	
	prev=NULL;
	
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	return prev;		
}
//wrong!
struct list *reverse_recursive(struct list* root,struct list* prev)
{
		struct list *node,*temp;
	
		if(root->next==NULL)
		{
			node->next=prev;
			return prev;
		}
		
		else
		{
			temp=reverse_recursive(node->next, node);
			node->next=prev;
			return temp;
		}
}

struct list * sum(struct list *head1,struct list * head2)
{
	struct list *sum=insert(0),*head=sum;
	int add,carry=0;
	
	while(head1&&head2)
	{
		add=head1->data+head2->data+carry;
		sum->next=insert(add%10);
		carry=add/10;
		head1=head1->next;
		head2=head2->next;
		sum=sum->next;
	}
	
	while(head1)
	{
		add=head1->data+carry;
		sum->next=insert(add%10);
		carry=add/10;
		head1=head1->next;
		sum=sum->next;
	}
	
	while(head2)
	{
		add=head2->data+carry;
		sum->next=insert(add%10);
		carry=add/10;
		head2=head2->next;
		sum=sum->next;
	}

	sum=head->next;
	delete head;
	return sum;	
}

int main()
{
	struct list* root=NULL,*root2=NULL;
	
	root=insert(3);root2=insert(2);
	struct list* node=root;
	int n;
	cin>>n;
	
	while(n--)
	{
		int val;
		cin>>val;
		node->next=insert(val);
		node=node->next;
	}

	cin>>n;
	node=root2;
	while(n--)
	{
		int val;
		cin>>val;
		node->next=insert(val);
		node=node->next;
	}
	
	display(root);
	display(root2);
	display(sum(root,root2));
	
	mid(root);
	third_from_last(root);
	root=delete_node(root,3);
	display(root);

}
