#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[10005],add[10005],cum_sum;

int main()
{
	int t,n;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		cum_sum=0;
		
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			cum_sum+=arr[i];
			add[i]=cum_sum;
		}
		
		sort(arr,arr+n);
		
		int ans=-1;
		
		for(int j=n;j>=3;j--)
		{
			if((2*arr[j-1])<add[j-1])
			{
				ans=j;
				break;
			}
		}
		
		printf("%d\n",ans);
	}
}
