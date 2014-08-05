#include<abhinav.h>

using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	return node;
}


int inorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
}
int main()
{
		struct tree *root=create_tree(7);
	//cin>>num;
	//while
	//(num--)
	//{
		root->left=create_tree(3);
		root->right=create_tree(11);
		
		root->left->left=create_tree(1);
		root->left->right=create_tree(5);
		
		root->left->left->left=create_tree(0);
		root->left->left->right=create_tree(2);

		root->left->right->left=create_tree(4);
		root->left->right->right=create_tree(6);
		
		root->right->left=create_tree(9);
		root->right->right=create_tree(13);
		
		root->right->left->left=create_tree(8);
		root->right->left->right=create_tree(10);
		
		root->right->right->left=create_tree(12);
		root->right->right->right=create_tree(14);
		//root->right=insert(root->right,b);
	//}

	//cout<<root->right;
	inorder(root);
	cout<<"END\n";

	struct tree *temp=root;
	
	stack<int> s;
	queue<struct tree*> q;
	
	s.push(root->data);
	q.push(root);
	
	while(!q.empty())
	{
		struct tree* node=q.front();
		q.pop();

		if(node->right)
			s.push(node->right->data);

		if(node->left)
			s.push(node->left->data);
		
		if(node->right)
			q.push(node->right);
						
		if(node->left)
			q.push(node->left);
		
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<"->";
		s.pop();
	}
}
