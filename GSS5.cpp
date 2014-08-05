#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
	int prefix,suffix,ans,sum;
};

struct node tree[300300];
int arr[100100],t,n,m,x1,y1,x2,y2;

struct node combine(struct node c1, struct node c2)
{
	
	struct node node1;
	
	node1.ans=max(max(c1.ans,c2.ans),c1.suffix+c2.prefix);
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
		tree[node].ans=arr[start];
		tree[node].sum=arr[start];
		tree[node].prefix=arr[start];
		tree[node].suffix=arr[start];
		
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
		
	if(y<start || x>end)
		return tree[0];
		
	int mid=start+(end-start)/2;
	
	return combine(query(2*node,start,mid,x,y),query(2*node+1,mid+1,end,x,y));
}

int main()
{

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(int i=0;i<=3*n;i++)
		{
			tree[i].ans=0;
			tree[i].sum=0;
			tree[i].prefix=0;
			tree[i].suffix=0;
		}
		
		tree[0].ans=-100050;
		tree[0].sum=0;
		tree[0].prefix=-100050;
		tree[0].suffix=-100050;

		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		build(1,0,n-1);
			
		scanf("%d",&m);
		
		while(m--)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			--x1;
			--y1;
			--x2;
			--y2;
			
/*			for(int i=0;i<15;i++)
				printf("%d %d %d %d\n",tree[i].sum,tree[i].ans,tree[i].prefix,tree[i].suffix);
			printf("\n");
*/			
			if(x1==y2)
				printf("%d\n",query(1,0,n-1,x1,x1).ans);
			
			else if(x2==y1)
				printf("%d\n",max(query(1,0,n-1,x1,y1).suffix+max(0,query(1,0,n-1,x2+1,y2).prefix),max(0,query(1,0,n-1,x1,y1-1).suffix)+query(1,0,n-1,x2,y2).prefix));
			
			else if(x2>y1)
				printf("%d\n",query(1,0,n-1,x1,y1).suffix+query(1,0,n-1,x2,y2).prefix+query(1,0,n-1,y1+1,x2-1).sum);
			
			else if(x2<y1)
				printf("%d\n",max(max(max(0,query(1,0,n-1,x1,x2-1).suffix)+query(1,0,n-1,x2,y2).prefix,query(1,0,n-1,x1,y1).suffix+max(0,query(1,0,n-1,y1+1,y2).prefix)),query(1,0,n-1,x2,y1).ans));
		}
	}
}
