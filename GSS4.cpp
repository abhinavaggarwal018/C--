#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

struct node
{
	int cnt;
	long long int sum;
	bool ones;
};

int arr[100010],n,m,option,x,y;
struct node tree[300030];

struct node combine(struct node c1, struct node c2)
{
	struct node parent;
	parent.cnt=c1.cnt+c2.cnt;
	parent.sum=c1.sum+c2.sum;
	
	if(c1.ones && c2.ones)
		parent.ones=true;
	else
		parent.ones=false;
	return parent;
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{		
		if(arr[start]==1)
			tree[node].ones=true;
		else
			tree[node].ones=false;
		
		tree[node].cnt=1;
		tree[node].sum=arr[start];
	
		return;
	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

void update(int node, int start, int end, int x, int y)
{
	
	if(x>y|| start>end)
		return;

	if(tree[node].ones)
		return;

	if(x>end || y<start)
		return;

	if(start==end)
	{
		tree[node].sum=sqrt(tree[node].sum);
		if(tree[node].sum==1)
			tree[node].ones=true;
			
		return;
	}

	int mid=start+(end-start)/2;
	
	update(2*node,start,mid,x,y);
	update(2*node+1,mid+1,end,x,y);

	tree[node]=combine(tree[2*node],tree[2*node+1]);
	return;	
}

long long int query(int node, int start, int end, int x, int y)
{
	if(x>y)
		return 0;
	
	if(tree[node].ones)
		return tree[node].cnt;
		
	if(x>end || y<start)
		return 0;
		
	if(x<=start && y>=end)
		return tree[node].sum;
		
	int mid=start+(end-start)/2;
		
	return query(2*node,start,mid,x,y)+query(2*node+1,mid+1,end,x,y);
}

int main()
{
	int t=0;
	while(scanf("%d",&n)!=EOF)
	{
		t++;
		/*for(int i=0;i<3*n;i++)
		{
			tree[i].ones=0;
			tree[i].sum=0;
			tree[i].cnt=0;
		}*/
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		build(1,0,n-1);
			
		printf("Case #%d:\n",t);		
		scanf("%d",&m);
		
		while(m--)
		{

	/*	for(int i=0;i<10;i++)
			printf("Count:%d   Sum:%d    Ones:%d\n",tree[i].cnt,tree[i].sum,tree[i].ones);		
*/
			scanf("%d %d %d",&option,&x,&y);
			
			if(option==0)
				update(1,0,n-1,x-1,y-1);
			
			else if(option==1)
				printf("%lld\n",query(1,0,n-1,x-1,y-1))	;	
		}
		
		printf("\n");
	}

}


