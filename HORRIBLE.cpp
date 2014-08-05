#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 100010

struct node
{
	long long int sum;
	int cnt;
	int flag;
};

struct node tree[3*MAX];

int arr[MAX],option,p,q,v,t,n,c;

struct node combine(node c1, node c2)
{
	struct node parent;
	
	parent.sum=c1.sum+c2.sum+c2.flag+c1.flag;
	parent.cnt=c1.cnt+c2.cnt;
	parent.flag=0;
	
	return parent;
}

void build(int node, int start, int end)
{
	if(start>end)
	return;
		
	if(start==end)
	{

		tree[node].cnt=1;
		tree[node].sum=0;
		tree[node].flag=0;

		return;

	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

void update(int node, int start, int end, int p, int q, int v)
{	
	if(start>end)
		return;

	if(p>end || q<start)
	{
		tree[node].sum+=tree[node].flag*tree[node].cnt;
		
		if(start==end)
			return;
			
		tree[2*node].flag+=v;
		tree[2*node+1].flag+=v;
		
		tree[node].flag=0;
		return;
	}
		
	if(p<=start && q>=end)
	{	
		tree[node].flag+=v;
		tree[node].sum+=tree[node].flag*tree[node].cnt;
		
		if(start==end)
			return;
			
		tree[2*node].flag+=tree[node].flag;
		tree[2*node+1].flag+=tree[node].flag;
		
		tree[node].flag=0;
		
		return;
	}
	
	int mid=start+(end-start)/2;
	
	update(2*node,start,mid,p,q,v);
	update(2*node+1,mid+1,end,p,q,v);
	
	tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
	
}

struct node query(int node, int start, int end, int p, int q, int flag)
{
	if(start>end || p>start || q <end)
		return tree[0];
		
	flag+=tree[node].flag;	
	tree[node].flag=0;
		
	if(p<=start&&q>=end)
	{
		tree[node].sum+=flag;
		
		if(start==end)
			return tree[node];
			
		tree[2*node].flag+=flag;
		tree[2*node+1].flag+=flag;
		
		return tree[node];
	}

	int mid=start+(end-start)/2;
	
	query(2*node,start,mid,p,q,flag);
	query(2*node+1,mid+1,end,p,q,flag);
	
	return combine(query(2*node,start,mid,p,q,flag),query(2*node+1,mid+1,end,p,q,flag));
	
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d %d",&n,&c);

		for(int i=0;i<3*n;i++)
		{
			tree[i].flag=0;
			tree[i].sum=0;
		}
		
		build(1,0,n-1);
		
		while(c--)
		{
			
			for(int i=0;i<17;i++)
				printf("%lld %d %d\n",tree[i].sum,tree[i].flag,tree[i].cnt);
			
			scanf("%d",&option);
			
			if(option==0)
			{
				scanf("%d %d %d",&p,&q,&v);
				update(1,0,n-1,p-1,q-1,v);
			}
			
			else if(option==1)
			{
				scanf("%d %d",&p,&q);
				printf("%lld\n",query(1,0,n-1,p-1,q-1,0).sum);
			}
			
		}
	}
}
