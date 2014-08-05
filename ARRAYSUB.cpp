#include<iostream>
#include<cstdio>

using namespace std;

int arr[1000010],tree[3000030],n,k;

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node]=arr[start];
		return;
	}
	
	int lc=2*node+1,mid=start+(end-start)/2;
	
	build(lc,start,mid);
	build(lc+1,mid+1,end);
	
	tree[node]=max(tree[lc],tree[lc+1]);
}

int query(int node, int start, int end, int x, int y)
{
	if(start>=x&&end<=y)
		return tree[node];
		
	if(start>y || end <x)
		return -100000;
		
	int mid=start+(end-start)/2;
		
	return max(query(2*node+1,start,mid,x,y),query(2*node+2,mid+1,end,x,y));
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	scanf("%d",&k);
	
	build(0,0,n-1);
	
	for(int i=0;i<(n-k+1);i++)
		printf("%d ",query(0,0,n-1,i,i+k-1));
}
