#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char arr[100];
	int dp[100]={0};
	scanf("%s",&arr);
	
	int len=strlen(arr);
	
	if(len==1)
	{
		cout<<1;
		return 0;
	}
	
	if(len>=2)
	{
		if(arr[0]=='0')
		{
			dp[0]=1;
			dp[1]=1;
		}
		
		else if(arr[0]=='1')
		{
			dp[0]=1;
			dp[1]=2;
		}
		
		else if(arr[0]=='2' && arr[1]=='0')
		{
			dp[0]=1;
			dp[1]=2;
		}
		
		else
		{
			dp[0]=1;
			dp[1]=1;
		}
	}
	
	for(int i=2;i<len;i++)
	{
		if(arr[i-1]=='0')
			dp[i]=dp[i-1];
			
		else if(arr[i-1]=='1')
			dp[i]=dp[i-1]+dp[i-2];
		
		else if(arr[i-1]=='2' &&arr[i]=='0')
			dp[i]=dp[i-1]+dp[i-2];
			
		else
			dp[i]=dp[i-1];
	}
	
	cout<<dp[len-1];
	return 0;
}
