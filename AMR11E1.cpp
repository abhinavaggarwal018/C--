#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

#define MAX 2505
#define NUM 50

std::vector<bool> arr(MAX);
std::vector<int> ans(2005);

int main()
{
	
	int i;
	bool flag=true;
	
	for(int j=4;j<MAX;j+=2)
		arr[j]=1;

	for(int j=9;j<MAX;j+=6)
		arr[j]=1;
	
	for(i=5;i<NUM;)
	{
		if(!arr[i])
		{
			for(int j=i*i, k=(i<<1);j<MAX;j+=k)
				arr[j]=1;
		}
		
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}	

	int pos=1;

	for(int n=30;pos<=1050;n++)
	{
		int cnt=0;
		int n1=n;
		int sqrtn=sqrt(n)+1;

		for(int i=2;i<=sqrtn;i++)
		{
			if((!(arr[i]))&&(!(n1%i)))
			{
				cnt++;
								
				while(!(n1%i))
					n1=(n1/i);
	
				if(cnt>=3)
					break;
			}
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
		printf("%d\n",ans[n]);	
	}
		
}

