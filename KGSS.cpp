#include<iostream>
#include<cassert>
#include<cstdio>
#include<vector>

#define MAX 100050

using namespace std;

struct node
{
	int data;
	int idx;
	
	node()
	{
		data=0;
		idx=0;
	}
};

int n,q,x,y;
char c;
vector<int> arr(MAX);
vector<struct node> tree(3*MAX);

using namespace std;

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].data=arr[start];
		tree[node].idx=start;
		return;
	}
	
	int mid=start+(end-start)/2, lc=2*node;

	build(lc,start,mid);
	build(lc+1,mid+1,end);
	
	if(tree[lc].data>=tree[lc+1].data)
	{
		tree[node].data=tree[lc].data;
		tree[node].idx=tree[lc].idx;
	}
		
	else
	{
		tree[node].data=tree[lc+1].data;
		tree[node].idx=tree[lc+1].idx;
	}
	
	return;
}

void update(int node, int start, int end, int ind, int val)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].data=val;
		
		if(tree[node].idx!=ind)
			assert(0);
		
		return;
	}
	
	int mid=start+(end-start)/2,lc=2*node;
	
	if(mid>=ind)
		update(lc,start,mid,ind,val);
		
	else
		update(lc+1,mid+1,end,ind,val);
	
	if(tree[lc].data>=tree[lc+1].data)
	{
		tree[node].data=tree[lc].data;
		tree[node].idx=tree[lc].idx;
	}	
	else
	{
		tree[node].data=tree[lc+1].data;
		tree[node].idx=tree[lc+1].idx;
	}	
}

struct node temp;

struct node query(int node, int start, int end, int x, int y)
{

	if(end<x || start>y || x>y)
		return tree[0];

	if(start>=x && end<=y)
		return tree[node];
		
	int lc=2*node,mid=start+(end-start)/2;
		
	struct node ans1=query(lc,start,mid,x,y),ans2=query(lc+1,mid+1,end,x,y);
	
	if(ans1.data>=ans2.data)
	{
		temp.data=ans1.data;
		temp.idx=ans1.idx;
	}
	else
	{
		temp.data=ans2.data;
		temp.idx=ans2.idx;
	}
	
	return temp;
}

int main()
{
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	build(1,0,n-1);
	scanf("%d",&q);
	
	while(q--)
	{
		
		cin>>c;
		scanf("%d %d",&x,&y);
		
		if(c=='Q')
		{
			struct node ans1=query(1,0,n-1,x-1,y-1);
			printf("%d\n",ans1.data+max(query(1,0,n-1,x-1,ans1.idx-1).data,query(1,0,n-1,ans1.idx+1,y-1).data));
		}			
		
		else if(c=='U')
			update(1,0,n-1,x-1,y);
	}
}
