#include<iostream>
#include<vector>

using namespace std;

int arr[1000];

void partition_array(int n, int sum)
{
	vector< vector<bool> >dp((sum/2+1),vector<bool> (n+1));
	
	for(int i=0;i<sum/2;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=false;
			
	for(int i=0;i<=sum/2;i++)
		dp[i][0]=false;
		
	for(int i=0;i<n;i++)
		dp[0][i]=true;	
	
	for(int i=1;i<=sum/2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			
			if(i>=arr[j-1])
				if(dp[i-arr[j-1]][j-1]||dp[i][j])
					dp[i][j]=true;
		}
	}
	
	for(int i=0;i<=sum/2;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int n,sum;
	while(1)
	{
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%2==1)
			cout<<"False\n";
			
		else
			partition_array(n,sum);
		
	}
	
}
