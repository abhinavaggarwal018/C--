#include<iostream>
#include<cstdio>
#include<cassert>

using namespace std;

struct node
{
	bool hash[105];
	int cnt;
	
	node()
	{
		for(int i=0;i<105;i++)
			hash[i]=0;
			
		cnt=0;
	}
}tree[40005];

int arr[10005],n,q;

void build(int node, int start, int end)
{	
	if(start==end)
	{
		tree[node].hash[arr[start]]=true;
		tree[node].cnt=1;
		return;
	}
	
	if(start>end)
		return;
		
	int mid=(start+end)/2;
	int val=node<<1;
	
	build(val+1,start,mid);
	build(val+2,mid+1,end);	
	
	tree[node].cnt=0;
	
	for(int i=0;i<105;i++)
	{
		tree[node].hash[i]=tree[val+1].hash[i]|tree[val+2].hash[i];
		if(tree[node].hash[i])
			tree[node].cnt++;
	}
}

void query(int node, int start, int end, int x, int y, bool temp[])
{
	if(y<start || x>end)
		return;
		
	if(x<=start && y>=end)
	{
		for(int i=0;i<105;i++)
			temp[i]=tree[node].hash[i]||temp[i];
			
		return;
	}
	
	int val=node<<1;
	int mid=start+(end-start)/2;
		
	query(val+1,start,mid,x,y,temp);
	query(val+2,mid+1,end,x,y,temp);
	
	return;
}

int main()
{
	
	freopen("C:\\Users\\Abhinav\\AppData\\Local\\Temp\\xy.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	
	int x,y;
	scanf("%d %d",&n,&q);
	
	if(n>10000 || q>100000 || n<1 ||q<1)
		assert(0);

	bool temp[105];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
//		cout<<":"<<arr[i]<<":"<<":"<<i<<" ";
		if(arr[i]>100 || arr[i]<0)
			assert(0);
	}

	build(0,0,n-1);
	
/*	for(int i=0;i<3*n;i++)
	{
		cout<<i<<":\t"<<tree[i].cnt<<"\t";
		for(int j=1;j<=5;j++)
			cout<<tree[i].hash[j]<<"   ";
		cout<<"\n";	
	}
*/	
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&x,&y);
		if(x<1 || y<x ||y>n)
			assert(0);
		
		for(int j=0;j<105;j++)
			temp[j]=0;
		
		query(0,0,n-1,x-1,y-1,temp);
		
		int ans1=0;
		
		for(int j=0;j<105;j++)
		{
			if(temp[j])
				ans1++;
		}
			
//		for(int j=0;j<10;j++)
//			cout<<temp[j]<<" ";	
		
			
		printf("%d\n",ans1);
	}
	
}
