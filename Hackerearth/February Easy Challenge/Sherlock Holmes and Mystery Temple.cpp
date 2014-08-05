#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t,n,cost[105];
	
	scanf("%d",&t);
	bool arr[10005];
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&cost[i]);
			sum+=cost[i];
		}

		for(int i=0;i<sum+5;i++)
			arr[i]=0;

		arr[0]=1;
			
		for(int i=n-1;i>=0;i--)
			for(int j=sum;j>=0;j--)
				if(arr[j])
					arr[j+cost[i]]=true;
					
		if(arr[sum/2] && sum%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
