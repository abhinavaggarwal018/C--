#include<iostream>
//#include<climits>

#define INT_MAX 10000

using namespace std;

	long long int dp[100][10000];



int wordWrap(int arr[], int n, int i, int gap)
{

int M = 6;

	if(i==n)
		return 0;
	
	if(dp[i][gap]!=INT_MAX)
		return dp[i][gap];
	
	int val = INT_MAX;
	
	{
		
	if(arr[i]==gap)
	{
		cout<<1<<":"<<i<<":  "<<arr[i]<<"  :"<<gap<<"\n";
		val = wordWrap(arr,n,i+1,M);
	}
	else if(arr[i]==gap+1)
	{
		cout<<2<<":"<<i<<":  "<<arr[i]<<"  :"<<gap<<"\n";
		val = wordWrap(arr,n,i+1,M)+1;
	}
	else if(arr[i]<gap-1)
	{
		cout<<3<<":"<<i<<":  "<<arr[i]<<"  :"<<gap<<"\n";
		val = wordWrap(arr,n,i+1,gap-arr[i]-1);
	}
	
	}
	
	if(gap!=M)
	{
		cout<<4<<":"<<i<<":  "<<arr[i]<<"  :"<<gap<<"\n";	
		val = min(val,wordWrap(arr,n,i,M)+(gap+1)*(gap+1)*(gap+1));
	}
	
	dp[i][gap]=val;
	return val;	
}

int main()
{
	int arr[]={3,2,2,5};

	for(int i=0;i<4;i++)
		for(int j=0;j<=6;j++)
			dp[i][j]=INT_MAX;

	cout<<wordWrap(arr,4,0,6);

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<=6;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
