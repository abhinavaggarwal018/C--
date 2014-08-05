#include<iostream>
#include<cstdio>
#include<vector>
#include<cassert>

using namespace std;

struct node
{
	int max_left;
	int max_right;
	int sum;
	int ans;
};

#define MAX 50050
struct node tree[3*MAX];
int arr[MAX],n,q,x,y;

struct node combine(struct node a, struct node b)
{
	struct node node1;
	
	node1.max_left=max(a.max_left,a.sum+b.max_left);
	node1.max_right=max(b.max_right,a.max_right+b.sum);
	
	if(a.max_right==0 && b.max_left==0)
		node1.ans=max(a.ans,b.ans);
	else
		node1.ans=max(max(a.ans,b.ans),a.max_right+b.max_left);
	
	node1.sum=a.sum+b.sum;
	
	return node1;
}

struct node query(int node, int start, int end, int x, int y)
{
	if(x<=start && y>=end)
		return tree[node];
		
	if(y<start || x>end)
		return tree[0];
		
	int mid=start+(end-start)/2;
		
	return combine(query(2*node,start,mid,x,y),query(2*node+1,mid+1,end,x,y));
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].ans=arr[start];
		tree[node].sum=arr[start];
		
		if(arr[start]>0)
		{
			tree[node].max_left=arr[start];
			tree[node].max_right=arr[start];
		}
		else
		{
			tree[node].max_left=0;
			tree[node].max_right=0;
		}
		
		return;
	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

int main()
{
	tree[0].ans=-10;
	tree[0].sum=-10;
	tree[0].max_left=0;
	tree[0].max_right=0;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	 build(1,0,n-1);
		
	scanf("%d",&q);
	
	while(q--)
	{
		
/*		for(int i=0;i<10;i++)
			printf("%d %d %d %d\n",tree[i].sum,tree[i].ans,tree[i].max_left,tree[i].max_right);
		printf("\n");
*/		
		scanf("%d %d",&x,&y);
		printf("%d\n",query(1,0,n-1,x-1,y-1).ans);
	}
}
