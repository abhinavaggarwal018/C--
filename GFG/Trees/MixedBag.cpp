#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

int val, htMax=0;

struct tree
{
	int data;
	struct tree *left, *right;
	tree(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

struct tree * createTree()
{
	struct tree *root = new struct tree(1);
	
	root->left = new struct tree(2);
	root->right = new struct tree(3);

	root->left->left = new struct tree(4);
	root->left->right = new struct tree(5);

	root->right->left = new struct tree(6);
	root->right->right = new struct tree(7);

	root->right->left->left = new struct tree(8);
	root->right->left->right = new struct tree(9);
	
	root->right->left->right->left = new struct tree(10);
	root->right->left->right->right = new struct tree(11);

	root->right->right->left = new struct tree(12);
	root->right->right->right = new struct tree(13);
	
	root->right->right->right->left = new struct tree(14);
	root->right->right->right->right = new struct tree(15);

	return root;
}
/*
			1
		2		3
	4	 5    6       7
			8  9    12  13
			  10 11    14 15
*/
void deepestLeft(struct tree * root, int ht, char c)
{
	if(root==NULL)
		return;
		
	if(htMax<ht && c =='L')
	{
		htMax=ht;
		val=root->data;
	}
	
	deepestLeft(root->left,ht+1,'L');
	deepestLeft(root->right,ht+1,'R');
}

void nextRight(struct tree *root, int data)
{
	if(root==NULL)
		return;

	struct tree * node =root;
	int cnt=1;
	queue<struct tree *> s;
	s.push(node);
	
	while(!s.empty())
	{
		node= s.front();
		s.pop();
		cnt--;
		
		if(node->left)
			s.push(node->left);
			
		if(node->right)
			s.push(node->right);

		if(cnt==0)
		{
			if(node->data==data)
				break;
			else
				cnt=s.size();		
		}		
		
		if(node->data==data)
		{
			cout<<s.front()->data;
			break;
		}
	}
	
	while(!s.empty())
		s.pop();
}

struct tree* prevLeft(struct tree *root, int data)
{
	if(root==NULL)
		return NULL;

	struct tree * node =root;
	int cnt=1;
	queue<struct tree *> s;
	s.push(node);
	
	while(!s.empty())
	{
		node= s.front();
		s.pop();
		cnt--;
		
		if(node->left)
			s.push(node->left);
			
		if(node->right)
			s.push(node->right);

		if(cnt==0)
		{
			if(node->data==data)
				break;
			else
				cnt=s.size();		
		}		
		
		if(node->data==data)
		{
			cout<<s.front()->data;
			break;
		}
	}
	
	while(!s.empty())
		s.pop();
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int maxSum=0;

void rootToLeafPath(struct tree *root, int val)
{
	if(root==NULL)
	{
		maxSum+=val;
		cout<<val<<"\n";
		return ;
	}
	val=val*10 + root->data;
	
	if(root->left==NULL && root->right==NULL)
		rootToLeafPath(root->left,val);
	else
	{
		rootToLeafPath(root->left,val);
		rootToLeafPath(root->right,val);
	}
	
	val/=10;
	return;
}

int minLevel=125,maxLevel=125;

bool isHeightRBTree(struct tree * root, int &minm, int &maxm)
{
	if(root==NULL)
	{
		minm=0;
		maxm=0;
		return true;
	}
	
	if(root->left==NULL && root->right==NULL)
	{
		minm=1;
		maxm=1;
		return true;
	}
	
	int min1,max1,min2,max2;
	
	if(isHeightRBTree(root->left,min1,max1)&isHeightRBTree(root->right,min2,max2))
	{
			maxm=max(max1,max2)+1;
			minm=min(min1,min2)+1;

		if(max2>2*minm)
			return false;
			
		else
			return true;
	}
	
	return false;
}

int arr[1000],vis[1000];

void printKdistNode(struct tree *root, int level, int k)
{
	if(root==NULL)
	{
		if(level>k && !vis[level-k-1])
			cout<<arr[level-k-1];
		vis[level-k-1]=true;
		return;
	}
	
	arr[level]=root->data;
	vis[level]=false;
	
	printKdistNode(root->left,level+1,k);	
	printKdistNode(root->right,level+1,k);
}

struct tree *curr=NULL,*head=NULL;

bool leavesOfBTreeToDll(struct tree *root)
{
	if(root==NULL)
		return false;
		
	if(root->left==NULL && root->right==NULL)
	{
		if(curr==NULL)
		{
			head=root;
			curr=root;
			curr->left=NULL;
			curr->right=NULL;
		}
		else
		{
			curr->right=root;
			root->left=curr;
			curr=curr->right;
		}
		
		return true;
	}
	
	if(leavesOfBTreeToDll(root->left))
		root->left=NULL;
		
	if(leavesOfBTreeToDll(root->right))
		root->right=NULL;
		
	return false;
}

void displayList(struct tree *root)
{
	
	if(root==NULL)
		return;
	
	cout<<root->data<<"->";
	displayList(root->right);
}

bool prunePath(struct tree *root, int k, int &sum)
{
	if(root==NULL)
		return sum>=k;
		
	sum = sum + root->data;
	
	bool a = prunePath(root->left,k,sum);
	bool b = prunePath(root->right,k,sum);
	
	sum = sum - root->data;
	
	if(!a)
	{
		root->left=NULL;
	}

	if(!b)
	{
 		root->right=NULL;
	}

	if(!a&&!b)
		delete root;
	
	return a|b;
}

int main()
{
	struct tree *root = createTree();
	inorder(root);
	cout<<"END\n";
//	deepestLeft(root,0,'L');
//	cout<<htMax<<val;

//	nextRight(root,9);
	
//	rootToLeafPath(root,0);
//	cout<<maxSum;

//	int mi1,ma1;
//	cout<<isHeightRBTree(root,mi1,ma1);

//	int m1=10000;
//	printKdistNode(root,0,0);
	
/*	leavesOfBTreeToDll(root);
	inorder(root);
	cout<<"END\n";

	displayList(head);		
	cout<<"END\n";*/

	int sum=0;	
	prunePath(root,1000,sum);
	
	inorder(root);
}
