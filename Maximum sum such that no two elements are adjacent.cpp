#include<iostream>

using namespace std;

int main()
{
	int dp[100],n,arr[100],t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		dp[0]=arr[0];
		dp[1]=arr[1];
		dp[2]=arr[0]+arr[2];
		
		for(int i=3;i<n;i++)
			dp[i]=max(dp[i-2],dp[i-3])+arr[i];
			
		cout<<dp[n-1];
	}
}
