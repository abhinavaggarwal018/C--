#include<iostream>

using namespace std;

struct list
{
	int data;
	struct list *next;
	struct list *left;
	struct list *right;
};


struct list *create_list(int data)
{
	struct list *node=new struct list;
	node->data=data;
	node->next=NULL;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}

struct list *create()
{
	struct list *node,*head;
	int n;
	
	cin>>n;
	
	int val;
	cin>>val;
	
	node=create_list(val);
	head=node;
	
	while(--n)
	{
		cin>>val;
		node->next=create_list(val);
		node=node->next;
	}
	
	return head;
}

struct list *create1()
{
	struct list *node=create_list(0),*head;
	head=node;
	
	int n=5;
	while(n--)
	{
		node->next=create_list(10-2*n);
		node=node->next;
	}
//	node->next=head->next->next->next;
	
	return head;
}

struct list *create2()
{
	struct list *node=create_list(1),*head;
	head=node;
	
	int n=5;
	while(n--)
	{
		node->next=create_list(11-2*n);
		node=node->next;
	}
	
	return head;
}

void display(struct list *head)
{
	int n=100;
	
	while(n-- && head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	
	cout<<"\n\n";
}

struct list *merge(struct list *head1, struct list *head2)
{
	if(head1==NULL)
		return head2;
	
	if(head2==NULL)
		return head1;
		
	if(head1->data <= head2->data)
	{
		head1->next=merge(head1->next,head2);
		return head1;
	}
	
	if(head1->data > head2->data)
	{
		head2->next=merge(head1, head2->next);
		return head2;
	}
}

struct list *reverse_recur(struct list *root, struct list *prev)
{
	if(root==NULL)
		return NULL;
		
	if(root->next==NULL)
	{
		root->next=prev;
		return root;
	}
	struct list * node=root->next;
	root->next=prev;
	
	return reverse_recur(node,root);	
}

struct list *reverse_iter(struct list *root)
{
	if(root==NULL || root->next==NULL)
		return root;
		
	struct list *prev=NULL, *next;	
	
	while(root->next)
	{
		next=root->next;
		root->next=prev;
		
		prev=root;
		root=next;
	}
	
	root->next=prev;
	return root;
}

bool detect_loop_util(struct list * slow, struct list *fast)
{
	if(fast==NULL || fast->next==NULL)
		return false;
		
	if(fast==slow)
		return true;
		
	return detect_loop_util(slow->next,fast->next->next);
}

bool detect_loop(struct list *head)
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return false;
		
	if(head==head->next || head->next->next==head || head->next->next==head->next)
		return true;
		
	return detect_loop_util(head->next,head->next->next);
}



bool is_palindrome(struct list *head)
{
	if(head==NULL || head->next==NULL)
		return true;
		
	struct list *slow, *fast;
	
	slow=head->next;
	fast=head->next->next;
		
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	slow=reverse_iter(slow);
	display(head);
	
	while(slow)
	{
		if(slow->data!=head->data)
			return false;
			
		slow=slow->next;
		head=head->next;	
	}
	
	return true;	
}

struct list * tree_to_list(struct list *root)
{
	if(root==NULL)	
		return NULL;
		
	
	struct list *left=tree_to_list(root->left);
	struct list *right=tree_to_list(root->right);
	
	root->left=root;
	root->right=root;

	if(left && right)
	{
		left->left->right=root;
		root->left=left->left;
		root->right=right;
		left->left=right->left;
		right->left->right=left;		
		
		return left;
	}
	
	if(left)
	{
		left->left->right=root;
		root->left=left->left;
		root->right=left;
		left->left=root;
		
		return left;
	}
	
	if(right)
	{
	
		root->left=right->left;
		root->right=right;
		right->left=root;
		right->left->right=root;
		
		return root;		
	}
	
	return root;	
}

struct list* create_temp()
{
	struct list *root=create_list(7);
	root->left=create_list(3);
	root->right=create_list(11);
	
	root->left->left=create_list(1);
	root->left->right=create_list(5);
	
	root->left->left->left=create_list(0);
	root->left->left->right=create_list(2);

	root->left->right->left=create_list(4);
	root->left->right->right=create_list(6);
	
	root->right->left=create_list(9);
	root->right->right=create_list(13);
	
	root->right->left->left=create_list(8);
	root->right->left->right=create_list(10);
	
	root->right->right->left=create_list(12);
	root->right->right->right=create_list(14);

	return root;
}

struct list * copy_ll(struct list *root)
{
	if(root==NULL)
		return NULL;
}

void delete_alternate(struct list* head)
{
	while(head && head->next)
	{
		struct list *temp=head->next->next;
		delete head->next;
		head->next=temp;
		head=temp;
	}
}

struct list* pairwise_swap(struct list *head)
{
	if(head==NULL || head->next==NULL)
		return head;
		
	struct list *temp1=head,*temp2=head->next,*temp3=head->next->next;
	temp2->next=temp1;
	temp1->next=pairwise_swap(temp3);
	
	return temp2;	
}

void swap_k_alternate(struct list* head, int k)
{
	struct list *prev=NULL,*root;
	int cnt=1;
	
	while(head)
	{
		struct list *temp1=head->next;
		while(head!=NULL && k--)
		{
			struct list *temp= head->next;
			head->next=prev;
			prev=head;
			head=temp;
		}
		
		if(cnt==1)
		{
			root=head;
			cnt=2;
		}
		
		temp=temp1;
		
		while(head!=NULL && k--)
		{
			prev=head;
			head=head->next;
			
		}
	}
	
	return root;
}

int main()
{
	struct list *head1, *head2, *head;

	head=NULL;
//	cout<<detect_loop(head);
	
	head=create1();
	display(head);

	
//	delete_alternate(head);
//	head=pairwise_swap(head);
	
	display(head);

//	head=tree_to_list(head);
	
	display(head);
	
/*	head1=create1();
	
	display(head1);

	head=reverse_recur(head1,NULL);
	display(head);

	head=reverse_iter(head);
	display(head);
*/	
	
/*	head2=create2();
	head=merge(head1, head2);
	display(head);	*/
	
}
