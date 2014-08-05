#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int dp[1000]={0},n;
	while(1)
	{
		scanf("%d",&n);
		
		dp[0]=0;
		dp[1]=1;
		dp[2]=1;
		
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i]=max(max(((i-j)*j),(i-j)*dp[j]),dp[i]);
			}
		}
		
		cout<<dp[n];
		
	}
}
