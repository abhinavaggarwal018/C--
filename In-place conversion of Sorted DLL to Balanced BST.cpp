/*
	
In-place conversion of Sorted DLL to Balanced BST
February 3, 2012

Given a Doubly Linked List which has data members sorted in ascending order. 
Construct a Balanced Binary Search Tree which has same data members as the given Doubly Linked List. 
The tree must be constructed in-place (No new node should be allocated for tree conversion)

Examples:

Input:  Doubly Linked List 1 <--> 2 <--> 3
Output: A Balanced BST 
     2   
   /  \  
  1    3 


Input: Doubly Linked List 1 <--> 2 <-->3 <--> 4 <-->5 <--> 6 <--> 7
Output: A Balanced BST
        4
      /   \
     2     6
   /  \   / \
  1   3  4   7  

Input: Doubly Linked List 1 <--> 2 <--> 3 <--> 4
Output: A Balanced BST
      3   
    /  \  
   2    4 
 / 
1

Input:  Doubly Linked List 1 <--> 2 <--> 3 <--> 4 <--> 5 <--> 6
Output: A Balanced BST
      4   
    /   \  
   2     6 
 /  \   / 
1   3  5   

The Doubly Linked List conversion is very much similar to this Singly Linked List problem and the method 1 is exactly same as the method 1 of previous post. 
Method 2 is also almost same. 
The only difference in method 2 is, instead of allocating new nodes for BST, we reuse same DLL nodes. 
We use prev pointer as left and next pointer as right.
*/

#include<iostream>
#include<cstdio>

using namespace std;

struct list
{
	int data;
	struct list *next;
	struct list *prev;
};

struct list* insert(int data)
{
	struct list * node=new struct list;

	node->next=NULL;
	node->prev=NULL;
	node->data=data;
	
	return node;
}

struct list *display(struct list *node)
{
	if(node==NULL)
		return node;
		
	while(node!=NULL)
	{
		cout<<node<<":";
		cout<<node->data<<"\n";
		node=node->next;
	}
}

int postorder(struct list *root,char c)
{
	getchar();
	if(root!=NULL)
	{
		cout<<root<<"\t"<<root->prev<<"\t"<<root->next<<"::"<<c<<"\n";
		
		if(root->prev&&root->next)
		cout<<root->data<<"\t"<<root->prev->data<<"\t"<<root->next->data<<"::"<<c<<"\n";
		
		postorder(root->prev,'l');
		postorder(root->next,'r');
	}
}

struct list* get_mid(struct list* root,struct list* end)
{
/*Question 1 : How to find middle element of linked list in one pass?
Read more: http://javarevisited.blogspot.com/2013/03/top-15-data-structures-algorithm-interview-questions-answers-java-programming.html#ixzz2WabOR664
*/
	struct list* node1=root->next,*node2=root->next->next;
	
	if(root==end)
	{
		return root;
	}
	
	if(node1==end||node2==end)
	{
		return root;
	}
	
	if(node2->next==end)
	{
		return node1;
	}
	//by varying last condition the number can be chosen for the odd number of terms comment &&node2->next->next!=end &see effect
	while(node1!=end&&node1->next!=end&&node2!=end&&node2->next!=end&&node2->next->next!=end)
	{
		node1=node1->next;
		node2=node2->next->next;
	}
	
	return node1;
}

struct list * convert_to_bst(struct list *head,struct list *end)
{
	if(head==NULL)
		return head;
	
	if(end!=NULL)
		cout<<"struct list * convert_to_bst(struct list *head: "<<head->data<<" ,struct list *end: "<<end->data<<")\n";
	else
		cout<<"struct list * convert_to_bst(struct list *head: "<<head->data<<" ,struct list *end: NULL)\n";		

	if(head==end||head->next==end)
	{
		head->next=NULL;
		head->prev=NULL;
		return head;
	}

	struct list *mid_el=get_mid(head,end);
	
	cout<<"Mid is:"<<mid_el->data<<"\n";
	

	mid_el->next=convert_to_bst(mid_el->next,end);
	mid_el->prev=convert_to_bst(head,mid_el);
	
	return mid_el;
}

struct list* convert_to_bst(struct list * &head,int n)
{
	if(n==0)
		return NULL;
		
	struct list *left=convert_to_bst(head,n/2);
	struct list *root=head;
	
	root->prev=left;
	head=head->next;
	
	root->next=convert_to_bst(head,n-n/2-1);
}


int main()
{
	struct list *node=insert(0),*root=node;
	
	int n=10;

	while(--n)
	{
		node->next=insert(10-n);
		node=node->next;
	}
	
	display(root);
	
	cout<<"\n";
	
	node=convert_to_bst(root,NULL);
	postorder(node,'b');
}
