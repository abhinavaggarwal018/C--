#include<iostream>
#include<cstdio>
// if flag set that node updated. Need to just update children.
using namespace std;

struct node
{
	int flag;
	int mod_0;
	int mod_1;
	int mod_2;
	
};

struct node tree[301000];

struct node combine(struct node a, struct node b)
{
	struct node ans;
	
	ans.mod_0=a.mod_0+b.mod_0;
	ans.mod_1=a.mod_1+b.mod_1;
	ans.mod_2=a.mod_2+b.mod_2;
	ans.flag=0;
	
	return ans;
}

void incr(int a)
{
	tree[a].flag=(tree[a].flag+1)%3;
	
	int temp=tree[a].mod_0;
	tree[a].mod_0=tree[a].mod_2;
	tree[a].mod_2=tree[a].mod_1;
	tree[a].mod_1=temp;
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].mod_0=1;
		tree[node].mod_1=0;
		tree[node].mod_2=0;
		tree[node].flag=0;
		return;
	}
	
	int mid=start+(end-start)/2;
	
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

void update(int node, int start, int end, int p, int q)
{
	if(p>q || start>end)
		return;
		
	if(tree[node].flag)
	{
		tree[node].flag--;
		
		if(start!=end)
		{
			incr(2*node);
			incr(2*node+1);
		}
	}
		
	if(q<start || p>end)
		return;
		
	if(p<=start && q>=end)
	{
		incr(node);
				
		tree[node].flag--;
		
		if(start!=end)
		{
			incr(2*node);
			incr(2*node+1);
		}
	
		return;
	}
	
	int mid=start+(end-start)/2;
	
	update(2*node,start,mid,p,q);
	update(2*node+1,mid+1,end,p,q);
	
	tree[node]=combine(tree[2*node],tree[2*node+1]);
}

int query(int node, int start, int end, int p, int q)
{
	if(p>q || start>end)
		return 0;

	if(tree[node].flag)
	{
		if(start==end)
		{
			tree[node].flag=0;
			break;
		}
		
		tree[node].flag--;
		
		if(start!=end)
		{
			incr(2*node);
			incr(2*node+1);
		}
	}
		
	if(q<start || p>end)
		return 0;
		
	if(p<=start && q>=end)
		return tree[node].mod_0;
		

	int mid=start+(end-start)/2;
	
	return query(2*node,start,mid,p,q)+query(2*node+1,mid+1,end,p,q);
}

int main()
{
	int n,q,option, a,b,val;
	scanf("%d %d",&n,&q);

/*	for(int i=1;i<=n;i++)
			tree[i].mod_0=1;
*/
	
	build(1,0,n-1);

	for(int i=0;i<18;i++)
		printf("%d %d %d %d\n",tree[i].flag,tree[i].mod_0,tree[i].mod_1,tree[i].mod_2);
	
	while(q--)
	{
		scanf("%d %d %d", &option, &a, &b);
		if(option==0)
			update(1,0,n-1,a,b);
		else
			printf("%d\n",query(1,0,n-1,a,b));
			
		for(int i=0;i<18;i++)
			printf("%d %d %d %d\n",tree[i].flag,tree[i].mod_0,tree[i].mod_1,tree[i].mod_2);
	}
}
