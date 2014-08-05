#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

struct node
{
	int sum,ans,suffix,prefix;
};

int arr[50010],n,m,c,x,y;
struct node tree[150000];

struct node combine(struct node c1, struct node c2)
{
	struct node node1;
	
	node1.ans=max(c1.ans,max(c2.ans,c1.suffix+c2.prefix));
	node1.sum=c1.sum+c2.sum;
	node1.prefix=max(c1.prefix,c1.sum+c2.prefix);
	node1.suffix=max(c1.suffix+c2.sum,c2.suffix);
	
	return node1;
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].sum=arr[start];
		tree[node].ans=arr[start];
		tree[node].suffix=arr[start];
		tree[node].prefix=arr[start];
		
		return;
	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

struct node query(int node, int start, int end, int x, int y)
{
	if(x<=start && y>=end)
		return tree[node];
		
	if(x>end || y<start)
		return tree[0];
		
	int mid=start+(end-start)/2;

	return combine(query(2*node,start,mid,x,y),query(2*node+1,mid+1,end,x,y));
}

void update(int node, int start, int end, int x, int y)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		if(start!=x)
			assert(0);
			
		tree[node].sum=y;
		tree[node].ans=y;
		tree[node].suffix=y;
		tree[node].prefix=y;
		
		return;
	}
	
	int mid=start+(end-start)/2;
	
	if(x<=mid)
		update(2*node,start,mid,x,y);
	else
		update(2*node+1,mid+1,end,x,y);
		
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

int main()
{
	tree[0].ans=-100050;
	tree[0].suffix=-100050;
	tree[0].prefix=-100050;
	tree[0].sum=-100050;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	build(1,0,n-1);
	
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d %d",&c,&x,&y);

		if(c==0)
			update(1,0,n-1,x-1,y);
		else if(c==1)
			printf("%d\n",query(1,0,n-1,x-1,y-1).ans);

	}
}
