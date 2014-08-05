#include<iostream>
#include<climits>
using namespace std;

int matrix_mult(int arr[],int n)
{
	int cost[100][100],part[100][100];
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			cost[i][j]={INT_MAX};
			
	for(int i=1;i<n;i++)
		cost[i][i]=0;
		
		for(int l=2;l<n;l++)
		{
			for(int i=1;i<=n-l+1;i++)
			{
				int j=i+l-1;
				for(int k=i;k<=j-1;k++)
				{
					int cost1=cost[i][k]+cost[k+1][j]+arr[i-1]*arr[k]*arr[j];
					if(cost1<cost[i][j])
					{
						cost[i][j]=cost1;
						part[i][j]=k;
					}
				}
			}
		}
	
	return cost[1][n-1];
}

int main()
{
	int n,arr[100];
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<matrix_mult(arr,n);
	}
}
