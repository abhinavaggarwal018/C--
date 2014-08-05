/*
	
Largest Sum Contiguous Subarray
June 22, 2009

Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/

#include<iostream>

using namespace std;

int main()
{
	int n,arr[1000],max=-10000,curr_sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		if(arr[i]>max)
			max=arr[i];
			
		curr_sum=curr_sum+arr[i];
		
		if(curr_sum<0)
			curr_sum=0;
		
		if(curr_sum>max)
			max=curr_sum;
	}
	cout<<max;
}
