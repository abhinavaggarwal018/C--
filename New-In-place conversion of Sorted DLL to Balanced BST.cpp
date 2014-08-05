#include<abhinav.h>

struct list
{
	int data;
	struct list *left,*right;
};

struct list * create_list(int data,struct list *prev)
{
	struct list *node= new struct list;
	
	node->data=data;
	node->left=prev;
	node->right=NULL;
	
	return node;
}

void display(struct list *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	
	cout<<"END\n";
}

struct list * get_mid_prev(struct list *start,struct list *end)
{
	if(start==NULL)
		return NULL;

	if(start==end)
		return start;
	if(start->right==NULL||start->right==end)
		return start;
	if(start->right->right==end)
		return start;
	
	return get_mid_prev(start->right,end);
}

struct list * to_bst(struct list *head,struct list *end)
{
	if(head==end)
		return NULL;

	struct list *mid=get_mid_prev(head,end);

	struct list *root= mid->right;
	
	root->left=to_bst(head,mid);
	root->right=to_bst(mid->right->right,end);
	
	return root;
}

struct list * to_bst(struct list **head,int n)
{
	if(n==0)
		return NULL;
	struct list *left=to_bst(head,n/2);
	struct list *root= *head;
	
	(*head)=(*head)->right;
	(root)->left=left;

	(root)->right=to_bst(head,n-n/2-1);
	
	return root;
}

void inorder(struct list *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int main()
{
	struct list *head=create_list(0,NULL);
	struct list *temp=head;
	
	int n=10;
	
	for(int i=1;i<=n;i++)
	{
		temp->right=create_list(i,temp);
		temp=temp->right;
	}
	
	display(head);
	
	head=to_bst(&head,n+1);
	
	inorder(head);
}
