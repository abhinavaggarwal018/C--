#include<cstdio>
#include<iostream>
#include<cassert>
#include<queue>

using namespace std;

int level[1005],in[1005],width[1005],t,n;
bool vis[1005];

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	
	tree(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

struct range
{
	struct tree *node;
	int l;
	int r;
	
	range(struct tree *node1,int a, int b)
	{
		node=node1;
		l=a;
		r=b;
	}
};

int ind=0;
/*
struct tree * buildTree(int n)
{
	if(n==0)
		return NULL;
		
	if(n==1)
		return new tree(level[ind++]);
		
	struct tree * root = new tree(level[ind++]);
	
	queue<range> q;
	q.push(range(root,0,n-1));
	struct tree * node;
	int i;
	while(!q.empty())
	{
		
		node = q.front().node;
		int l= q.front().l;
		int r= q.front().r;
		
		q.pop();
		
		for(i=l;i<r && in[i]!=node->data;i++)
		{
			if(in[i]==level[ind])
				break;
		}
		
		if(in[i]==node->data || ind>n)	
			node->left=NULL;
		else
		{
			node->left = new tree(level[ind++]);			
			q.push(range(node->left,l,i-1));
		}
		
		for(;i<r;i++)
			if(in[i]==node->data)
				break;
				
		for(i=i+1;i<r;i++)
		{
			if(in[i]==level[ind])
				break;
		}
		
		if(i==r||ind>n)	
			node->right=NULL;
		else
		{
			
			node->right = new tree(level[ind++]);				
			q.push(range(node->right,i+1,r));
		}
	}
	
	return root;
}
*/

struct tree * buildTree(int s, int e)
{
	if(s>e||ind==n)
		return NULL;
		
	int val;
	bool flag=true;	
		
	int i,j;
		
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			for(j=s;j<=e;j++)
			{
				if(in[j]==level[i])
				{
					flag=false;
					vis[i]=true;
					break;
				}
			}
		}
		
		if(flag==false)
			break;
	}
			
	struct tree * root = new tree(level[i]);

	root->left = buildTree(s,j-1);
	root->right = buildTree(j+1,e);

	return root;
}

void Width(struct tree *root, int level)
{
	if(root==NULL)
		return;
		
	width[level]++;
	
	Width(root->left,level+1);
	Width(root->right,level+1);
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		ind=0;
		scanf("%d",&n);
		
		for(int i=0;i<1005;i++)
		{
			vis[i]=false;
			width[i]=0;
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&level[i]);
		}
		
		struct tree *root=buildTree(0,n-1);
		
		Width(root,0);
		
		int ans=0;
		
		for(int i=0;i<n;i++)
			ans=max(ans,width[i]);
			
		cout<<ans<<"\n";	
	}
}
