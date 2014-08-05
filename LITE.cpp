#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
	bool flag;
	int cnt;
};

struct node tree[100100];

void update(int node, int start, int end, int p, int q)
{
	if(p>q)
		return;
		
	if(start>q || end<p)
		return;
		
	if(p<=start && q>=end)
	{
		tree[node].cnt=(end-start+1-tree[node].cnt);
		tree[node].flag=tree[node].flag^true;
		
		return;
	}
	
	if(start==end)
		return;
	
	int mid=start+(end-start)/2;
	
	update(2*node,start,mid,p,q);
	update(2*node+1,mid+1,end,p,q);
	
	tree[node].cnt=tree[2*node].cnt+tree[2*node+1].cnt;
}

int query(int node, int start, int end, int p, int q)
{
	if(start>end)
		return 0;
		
	if(start>q || end<p)
		return 0;
	
	if(p<=start && q>=end)
		return tree[node].cnt;
		
	if(start==end)
		return 0;
	
	if(tree[node].flag)
	{
		tree[node].flag^=tree[node].flag;
		
		tree[2*node].flag^=true;
		tree[2*node+1].flag^=true;
		
		int mid=start+(end-start)/2;
		
		tree[2*node].cnt=mid-start+1-tree[2*node].cnt;
		tree[2*node+1].cnt=end-mid-tree[2*node+1].cnt;
	}
		
	int mid=start+(end-start)/2;
	
	return query(2*node,start,mid,p,q)+query(2*node+1,mid+1,end,p,q);
}

int main()
{
	int n,m,option,p,q;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<100000;i++)
	{
		tree[i].cnt=0;
		tree[i].flag=false;
	}
	
	while(m--)
	{
		scanf("%d %d %d",&option,&p,&q);
	
		if(option==0)
			update(1,0,n-1,p-1,q-1);
	
		else if(option==1)
			printf("%d\n",query(1,0,n-1,p-1,q-1));

	/*	for(int i=0;i<3*n;i++)
			printf("%d %d\n",tree[i].cnt,tree[i].flag);
*/
	}
}
