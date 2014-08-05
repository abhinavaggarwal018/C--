/*
Given a value N, if we want to make change for N cents, and we have infinite supply 
of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5
*/

#include<iostream>
#include<vector>

using namespace std;

int find_coins(int arr[],int n,int num)
{
	vector<int> coins(num+5,0);
	
	coins[0]=1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=arr[i];j<=num;j++)
		{
			coins[j]+=coins[j-arr[i]];
		}
		
	}
	return coins[num];
}

int main()
{
	int n,arr[100],val,num;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>num;
		cout<<find_coins(arr,n,num);
	}
}
