#include<iostream>

using namespace std;

int main()
{
	int n, arr[1000], sum;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	bool subset[10000]={0};
	subset[0]=1;
	cin>>sum;
	
	for(int i=0;i< sum+5;i++)
	{
		for(int j=0;j<sum-arr[i]+5;j++)
		{
			if(subset[j]==true)
			{
				subset[j+arr[i]]=true;
			}
		}
	}

cout<<subset[sum];	

	for(int i=0;i< sum+5;i++)
		cout<<subset[i];
}
