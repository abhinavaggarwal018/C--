#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t,n,ans,arr[100];
	bool hash[8000],found;
	
	scanf("%d",&t);
	
	while(t--)
	{
		ans=0;
		
		scanf("%d",&n);
		
		if(n>25)
		{
			printf("YES\n");
			continue;
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			ans+=arr[i];
		}
		
		ans=ans+5;
		
		for(int i=0;i<=ans;i++)
			hash[i]=0;
		
		hash[0]=1;
		found=false;
			
		for(int i=0;(i<n && (!found));i++)
		{
			int ans_temp=ans-arr[i];
			
			for(int j=0;(j<=ans_temp);j++)
			{
				if(arr[j])
				{
					if(arr[j+arr[i]])
					{
						found=true;
						break;
					}
					
					arr[j+arr[i]]=true;
				}
			}
		}
		
		for(int i=0;i<ans;i++)
			if(hash[i])
				printf("%d",i);
		
		if(found)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
