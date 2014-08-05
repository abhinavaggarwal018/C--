#include<cstdio>
#include<iostream>
#include<cassert>

using namespace std;

struct node
{
	int sum; // sum of all nos. must be zero
	int maxm;  // maxm value of sum must be zero
	bool child;
}tree[90100];

char arr[30100];
int n,m,val;

struct node combine(struct node a, struct node b)
{
	struct node ans;
	
	ans.sum=a.sum+b.sum;
	ans.child=false;
	
	if(a.child)
		ans.maxm=a.sum+b.maxm;
	else
		ans.maxm=max(a.maxm,a.sum+b.maxm);
	
	return ans;
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		if(int(arr[start])==40)
		{
			tree[node].sum=-1;
			tree[node].maxm=-1;
			tree[node].child=true;
		}
		
		else if(int(arr[start])==41)
		{
			tree[node].sum=1;
			tree[node].maxm=1;
			tree[node].child=true;
		}
		
		else
			assert(0);
			
		return;
	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

void update(int node, int start, int end, int ind)
{
	if(start>end)
		assert(0);
		
	if(start==end)
	{
		if(start!=ind)
			assert(0);	
			
		else if(int(arr[start])==40)
		{
			arr[start]=')';
			tree[node].sum=1;
			tree[node].maxm=1;
		}
		
		else if(int(arr[start])==41)
		{
			arr[start]='(';
			tree[node].sum=-1;
			tree[node].maxm=-1;
		}		
		else
			assert(0);	
			
		return;
	}
	
	int mid=start+(end-start)/2;
	
	if(ind<=mid)
		update(2*node,start,mid,ind);
	else
		update(2*node+1,mid+1,end,ind);
		
	tree[node]=combine(tree[2*node],tree[2*node+1]);
	
	return;
}

int main()
{
	
	for(int t=1;t<=10;t++)
	{
	//cout<<int('('); this is 40
		scanf("%d",&n);	
		
		for(int i=0;i<3*n;i++)
		{
			tree[i].sum=0;
			tree[i].maxm=0;
		}
		
		scanf("%s",&arr);
		
		
		build(1,0,n-1);
			
//		for(int i=0;i<20;i++)
//			printf("Maxm: %d   Sum:%d   Child:%d\n",tree[i].maxm,tree[i].sum,tree[i].child);
		
		scanf("%d",&m);
	
		printf("Test %d:\n",t);
		
		while(m--)
		{
			scanf("%d",&val);
			
			if(val==0)
			{
				if(tree[1].sum!=0 || tree[1].maxm!=0)
					printf("NO\n");
				else
					printf("YES\n");	
			}
			
			else if(val!=0)
				update(1,0,n-1,val-1);
		}
	}
}
