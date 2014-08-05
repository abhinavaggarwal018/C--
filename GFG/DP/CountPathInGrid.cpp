#include<iostream>
using namespace std;

void recur(int n, int m, string str)
{
	int dp[100][100];
	
	for(int i=0;i<n;i++)
		dp[i][0]=1;
		
	for(int j=0;j<m;j++)
		dp[0][j]=1;	

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i!=0 && j!=0)
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
			cout<<dp[i][j]<<" ";
		}
		
		cout<<"\n";
	}
}	

int main()
{
	int n,m;
	cin>>n>>m;
	recur(n,m,"");
}
