#include<iostream>

using namespace std;

int main()
{
	int arr[100]={1},n,dp[100];
	
	dp[1]=1;
	
	cin>>n;
	
	for(int i=2;i<=n;i++)
	{
		dp[0]=0;
		dp[i]=1;
		for(int j=1;j<=i/2+1;j++)
		{
			dp[i]=max(dp[i],max(j,dp[j])*max(i-j,dp[i-j]));
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": "<<dp[i]<<"\n";
	}
}
