#include<iostream>
#include<stdio>

using namespace std;

char str[5005],dp[5005]={0};

int main()
{
	while(1)
	{
		scanf("%s",&str);
		if(str[0]=='0')
		break;
		
		int m=strlen(str);
		
		if(str[0]<='2')
		{
			if(m>=2 && str[1]!=2)
			{
				dp[0]=1;
				dp[1]=2;
			}
			else
				dp[0]=1;
		}
		else
		{
			dp[0]=1;
			dp[1]=1;
		}
		
		for(int i=2;i<n;i++)
		
		
		printf("%lld\n",dp[m-1]);
	}
}
