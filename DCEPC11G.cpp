#include<iostream>
#include<cstdio>

using namespace std;

struct node
{
	long long int sum;
	long long int flag;
}arr[3000099];

int n,p,q,option;

void update(int node, int start, int end, int x, int y, int flag)
{
//	cout<<"update("<<node<<", int "<<start<<", int "<<end<<", int "<<x<<", int "<<y<<", int "<<flag<<")\n";
	int mid=start+(end-start)/2;
	
	if(arr[node].flag)
	{
		arr[2*node].flag+=arr[node].flag;
		arr[2*node].sum+=(mid-start+1)*arr[node].flag + ((mid-start)*(mid-start+1)/2);
		
		arr[2*node+1].flag+=arr[node].flag+(mid-start+1);
		arr[2*node+1].sum+=(end-mid)*(arr[node].flag+(mid-start+1)) + ((end-mid-1)*(end-mid)/2);
	
		arr[node].flag=0;
	}
	
	if(start>y || end<x)
		return;
		
	if(x<=start && y>=end)
	{
		if(start!=end)
			arr[node].flag+=flag+(start-x);
		
		arr[node].sum+=(end-start+1)*(flag+(start-x))+((end-start)*(end-start+1)/2);
		
		return;
	}
	
	update(2*node,start,mid,x,y,flag);
	update(2*node+1,mid+1,end,x,y,flag);
	
	arr[node].sum=arr[2*node].sum+arr[2*node+1].sum;
}

int query(int node, int start, int end, int p, int q)
{
//	cout<<"node("<<node<<", int "<<start<<", int "<<end<<", int "<<p<<", int "<<q<<")\n";
	
	int mid=start+(end-start)/2;
	
	if(arr[node].flag)
	{
		arr[2*node].flag+=arr[node].flag;
		arr[2*node].sum+=(mid-start+1)*arr[node].flag + ((mid-start)*(mid-start+1)/2);
		
		arr[2*node+1].flag+=arr[node].flag+(mid-start+1);
		arr[2*node+1].sum+=(end-mid)*(arr[node].flag+(mid-start+1)) + ((end-mid-1)*(end-mid)/2);
	
		arr[node].flag=0;
	}

	if(start>end || p>end || q<start)
		return 0;	
		
	if(p<=start&&q>=end)
		return arr[node].sum;

	return query(2*node,start,mid,p,q)+query(2*node+1,mid+1,end,p,q);
}

int main()
{
	int c;
	scanf("%d %d",&n,&c);

	while(c--)
	{
		
//		for(int i=0;i<17;i++)
//			printf("%d.\t%lld\t%d\n",i,arr[i].sum,arr[i].flag);
		
		scanf("%d",&option);
		
		if(option==0)
		{
			scanf("%d %d",&p,&q);
			update(1,0,n-1,p-1,q-1,1);
		}
		
		else if(option==1)
		{
			scanf("%d %d",&p,&q);
			printf("%lld\n",query(1,0,n-1,p-1,q-1));
		}
	}
}
