#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

struct node
{
	int freq; // freq of max_cnt
	int left_freq,right_freq;
	int left_val,right_val;
	int cnt;
};

struct node tree[300050];
int arr[100010],n,q,x,y;

/*void display(struct node tree1)
{
	if(!tree1.freq)
		return;
	printf("%d %d %d %d %d %d\n",tree1.freq,tree1.cnt,tree1.left_val,tree1.left_freq,tree1.right_val,tree1.right_freq);
}
*/
struct node combine(struct node c1, struct node c2)
{
	if(c1.freq==0)
		return c2;
		
	if(c2.freq==0)
		return c1;
		
	struct node node1;
	
	node1.left_val=c1.left_val;
	node1.right_val=c2.right_val;
	
	if(c1.left_val==c2.left_val)
		node1.left_freq=c1.cnt+c2.left_freq;
	else
		node1.left_freq=c1.left_freq;
		
	if(c1.right_val==c2.right_val)
		node1.right_freq=c1.right_freq+c2.cnt;
	else
		node1.right_freq=c2.right_freq;
		
	node1.cnt=c1.cnt+c2.cnt;

	node1.freq=max(c1.freq,c2.freq);
	
	if(c1.right_val==c2.left_val)
		node1.freq=max(node1.freq,c1.right_freq+c2.left_freq);
	
	return node1;
}

void build(int node, int start, int end)
{
	if(start>end)
		return;
		
	if(start==end)
	{
		tree[node].freq=1;
		tree[node].left_val=arr[start];
		tree[node].right_val=arr[start];
		tree[node].left_freq=1;
		tree[node].right_freq=1;
		tree[node].cnt=1;
		
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
		
	if(x>end || y<start)
		return tree[0];
		
	int mid=start+(end-start)/2;
	
//	display(query(2*node,start, mid,x,y));
//	display(query(2*node+1,mid+1,end,x,y));
//	display(combine(query(2*node,start, mid,x,y),query(2*node+1,mid+1,end,x,y)));
	
	return combine(query(2*node,start, mid,x,y),query(2*node+1,mid+1,end,x,y));
}

int main()
{
	tree[0].freq=0;
	tree[0].left_freq=0;
	tree[0].right_freq=0;
	tree[0].left_val=-20000000;
	tree[0].right_val=-20000000;
	tree[0].cnt=0;
	
	scanf("%d",&n);
	
	while(n!=0)
	{
		scanf("%d",&q);
		
		for(int i=1;i<=3*n;i++)
		{
			tree[i].freq=0;
			tree[i].left_freq=0;
			tree[i].right_freq=0;
			tree[i].left_val=0;
			tree[i].right_val=0;
			tree[i].cnt=0;
		}
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
			
		build(1,0,n-1);
		
	//	for(int i=0;i<20;i++)
	//		printf("%d %d %d %d %d %d\n",tree[i].freq,tree[i].cnt,tree[i].left_val,tree[i].left_freq,tree[i].right_val,tree[i].right_freq);
		
		while(q--)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",query(1,0,n-1,x-1,y-1).freq);
		}
		
		scanf("%d",&n);
	}
	
	return 0;
			
}


