#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 1000010
#define NUM 1005

vector<int> arr(MAX);


int main()
{
	bool incr=true;
	
	for(int i=2;i<MAX;i+=2)
		arr[i]=2;
		
	for(int i=3;i<MAX;i+=6)
		arr[i]=3;

	int i;
	
	for(i=5;i<NUM;)
	{
		if(!arr[i])
		{
			arr[i]=i;
			for(int j=i*i,k=(i<<1);j<MAX;j+=k)
			{
				if(!arr[j])
					arr[j]=i;
			}
		}
		if(incr)
			i+=2;
		else
			i+=4;
			
		incr=incr^true;
	}
	
	for(;i<MAX;)
	{
		if(!arr[i])
			arr[i]=i;
				
		if(incr)
			i+=2;
		else
			i+=4;
			
		incr=incr^true;
	}
	
	for(int i=2;i<MAX;i++)
		if(!arr[i])
		{
			cout<<i<<" ";
			getchar();
		}
		
	int t,n;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		int ans=n;
		
		while(n!=1)
		{
			ans-=(ans/arr[n]);
			
			int val=arr[n];
	
			while(arr[n]!=0 && val==arr[n])
				n=n/arr[n];
		}
		
		printf("%d\n",ans);
		
	}
	
}
