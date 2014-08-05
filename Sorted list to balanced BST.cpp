#include<abhinav.h>

struct list 
{
	int data;
	struct list *next;
};

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct list *create_list(int data)
{
	struct list *node= new struct list;
	
	node->next=NULL;
	node->data=data;
	
	return node;
}

struct tree * create_tree(int data)
{
	struct tree *node= new struct tree;
	
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	
	return node;
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;
		

	cout<<root->data<<"->";
	inorder(root->left);
	inorder(root->right);
}

struct tree * to_balanced_bst(struct list **temp,int n)
{
	if(n<=0)
		return NULL;

	struct tree *left=to_balanced_bst(temp,n/2);
	struct tree *root=create_tree((*temp)->data);

	(*temp)=(*temp)->next;

	root->left=left;
	root->right=to_balanced_bst(temp,n-n/2-1);

	return root;
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

int main()
{
	struct list *head,*temp;
	struct tree *root;
	head=create_list(0);
	temp=head;
	
	for(int i=1;i<15;i++)
	{
		temp->next=create_list(i);
		temp=temp->next;
	}
	int n=15;	
	
	display(head);
	temp=head;
	root=to_balanced_bst(&temp,n);
	
	inorder(root);
}
