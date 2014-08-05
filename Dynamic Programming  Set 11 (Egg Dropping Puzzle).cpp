#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int find_trials(int n,int k)
{	
	vector< vector<int> > dp((k+1), vector<int> (k+1));
	//vector <int> temp(n);
	int temp;
	
	for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
 
    // We always need j trials for one egg and j floors.
    for (int j = 1; j <= k; j++)
        dp[1][j] = j;
 
    // Fill rest of the entries in table using optimal substructure
    // property
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                temp = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if (temp < dp[i][j])
                    dp[i][j] = temp;
            }
        }
    }

	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[j][i]<<" ";
		}
		cout<<"\n";
	} 
    // dp[n][k] holds the result
    return dp[n][k];
	
	/*
	for(int i=0;i<=k;i++)
	{
		dp[i][0]=0;
		dp[i][1]=i;
	}
	
	for(int j=0;j<=n;j++)
	{
		dp[0][j]=0;
		dp[1][j]=1;
	}
	for(int i=2;i<=k;i++)
	{
		temp=INT_MAX;
		for(int j=2;j<=n;j++)
		{
			dp[i][j]=INT_MAX;
			for(int l=1;l<=i;l++)
			{
				temp=1+max(dp[k-l][j-1],dp[i-l][j]);
				if(temp<dp[i][j])
					dp[i][j]=temp;
			}
		}
	}
	
	
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return dp[k][n];*/
}
int main()
{
	int n,k;
	while(1)
	{
		cin>>n>>k;
		cout<<"Trials:"<<find_trials(n,k);
	}
}
