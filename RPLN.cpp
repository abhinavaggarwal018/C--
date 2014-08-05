#include<iostream>
#include<cassert>
#include<cstdio>

using namespace std;

int arr[100050],tree[300150];

void build(int pos,int start,int end)
{
	if(start>end)
		return;
	
	if(start==end)
	{
		tree[pos]=arr[start];
		return;
	}
	
	int lc=2*pos+1,rc=2*pos+2,mid=start+(end-start)/2;
		
	build(lc,start,mid);
	build(rc,mid+1,end);
	
	tree[pos]=min(tree[lc],tree[rc]);
}

int query(int node, int start, int end, int a, int b)
{
	if(a<=start && b>=end)
		return tree[node];
	
	int mid=start+(end-start)/2;	
	
	if(b<start || a>end)
		return 1000000009;
		
	return min(query(2*node + 1, start, mid, a, b),query(2*node + 2, mid+1, end, a, b));
}

int main()
{
	int t,n,q,a,b;
	
	scanf("%d",&t);
	
	for(int k=0;k<t;k++)
	{
		scanf("%d %d",&n,&q);
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		build(0,0,n-1);

		printf("Scenario #%d:\n",k+1);		
		
		while(q--)
		{
			scanf("%d %d",&a, &b);
			printf("%d\n",query(0,0,n-1,a-1,b-1));
		}
	}
	
}
