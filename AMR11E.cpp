#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define MAX 10005
#define NUM 105

std::vector<int> arr(MAX);
std::vector<int> ans(2005);

int main()
{
	int i;
	bool flag=true;
	
	arr[1]=0;
	
	for(int j=2;j<MAX;j+=2)
		arr[j]=2;

	for(int j=3;j<MAX;j+=6)
		arr[j]=3;
	
	for(i=5;i<NUM;)
	{
		if(!arr[i])
		{
			arr[i]=i;
			for(int j=i*i, k=(i<<1);j<MAX;j+=k)
			{
				if(!arr[j])
					arr[j]=i;
			}
		}
		
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}	
	
	for(;i<MAX;)
	{
		if(!arr[i])
		{
			if(!arr[i])
				arr[i]=i;		
		}
		
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}

	int pos=0;

	for(int n=30;pos<=1050;n++)
	{
		int cnt=0;
		int n1=n;
	
		while(arr[n1])
		{
			cnt++;
							
			int v=arr[n1];
		
			while(v==arr[n1])
				n1=(n1/arr[n1]);

			if(n1==1)
				break;
		}
			
		if(cnt>=3)
		{
			ans[pos]=n;
			pos++;
		}
	}
	
	int t,n;
	
	scanf("%d",&t);

	

	while(t--)
	{
		scanf("%d",&n);
		if(n<=0)
		{
			cout<<0;
			continue;
		}
		
		printf("%d\n",ans[n-1]);	
	}
		
}

