#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;

int n,m,t;
long long int arr[30005];

void b_search(long long int arr[],long long int maxm,long long int sum)
{
//	cout<<maxm<<":"<<sum<<"\n";
	long long int curr_val,val;
	int cnt;
	
	if(maxm==(maxm+(sum-maxm)/2))
	{
//		cout<<maxm;
		long long int ans=0;
		cnt=1;
		curr_val=0;
		val=maxm;
		for(int i=0;i<n;i++)
		{
			if((curr_val+arr[i])<=val)
				curr_val=curr_val+arr[i];
				
			else
			{
				curr_val=arr[i];
				cnt++;
			}
			
			ans=max(curr_val,ans);
		}
		
		if(cnt==m)
		{
			printf("%lld\n",ans);
			return;
		}
		
		else
		{
			val=sum;
			ans=0;
			cnt=1;
			curr_val=0;
			for(int i=0;i<n;i++)
			{
				if((curr_val+arr[i])<=val)
					curr_val=curr_val+arr[i];
					
				else
				{
					curr_val=arr[i];
					cnt++;
				}
				
				ans=max(curr_val,ans);
			}
			
			if(cnt<=m)
			{
				printf("%lld\n",ans);
				return;
			}
		}
	}
	
	val=sum+(maxm-sum)/2;
	cnt=0;curr_val=0;
	
	for(long long int i=0;i<n;i++)
	{
		if((curr_val+arr[i])<=val)
			curr_val=curr_val+arr[i];
			
		else
		{
			curr_val=arr[i];
			cnt++;
		}
	}
	
	if(cnt>m)
		b_search(arr,val,sum);
		
	if(cnt<=m)
		b_search(arr,maxm,val);	
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n,&m);
		long long int maxm1=0;
		long long int sum=0;
		

		for(int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			maxm1=maxm1>arr[i]?maxm1:arr[i];
			sum+=arr[i];
		}
		
		b_search(arr,maxm1,sum);		
	}
	
	return 0;
}
