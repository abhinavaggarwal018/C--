#include<iostream>

using namespace std;

int ans=INT_MAX,cnt[1000]=0;
bool level[1000];


int minFunc(int ind, int nodes, int num)
{
	int cnt=0,arr[1000],n;
	
	for(int i=0;i<n;i++)
	{
		if(arr[ind][i])
			arr[cnt++]=minFunc(i,)
	}
	
	
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		for(int i=0;i<1005;i++)
			level[i]=false;
			
		ans=INT_MAX;
		
		scanf("%d",&n);
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				arr[i][j]=0;
		
		int val=n-1;
		
		while(val--)  
		{
			scanf("%d %d",&a,&b);
			arr[a][b]=true;
			arr[b][a]=true;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(arr[i][j])
					cnt[i]++;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			level[i]=true;
			minFunc(i);
			level[i]=false;
		}
	}
}
