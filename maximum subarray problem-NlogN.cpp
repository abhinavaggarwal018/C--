//maximum subarray using divide and conquor 0(nlog(n))
#include<iostream>
using namespace std;
int arr[500],max_profit=0;
//10 11 7 10 6
int divide(int start,int end) // end is n-1
{
	if(start==end)
	return 0;
	int mid=start+(end-start)/2;
	int max1=arr[mid];
	int min1=arr[start];
	for(int i=mid+1;i<=end;i++)
	{
		if(arr[i]>max1)
		max1=arr[i];
	}
	for(int i=start;i<=mid;i++)
	{
		if(arr[i]<min1)
		min1=arr[i];
	}
	max_profit=max(max_profit,max1-min1);
	return max(max_profit,max(divide(start,mid),divide(mid+1,end)));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<divide(0,n-1);
}

