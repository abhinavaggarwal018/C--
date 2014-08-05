/*
	
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
December 6, 2010

Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
*/

#include<iostream>

using namespace std;

int main()
{
	int n,arr[100],small,large,min,max;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		for(int i=0;i<n-1;i++)
			if(arr[i]>arr[i+1])
			{
				small=i+1;
				break;
			}
			
		for(int i=n-1;i>0;i--)
			if(arr[i]<arr[i-1])
			{
				large=i;
				break;
			}
		
		cout<<small<<" "<<large;
			
		min=10000;max=-10000;
		
		for(int i=small;i<=large;i++)
			if(arr[i]<min)
				min=arr[i];
		
		for(int i=0;i<small;i++)
			if(arr[i]>min)
			{
				small=i;
				cout<<"SMALL:"<<small;
				//break;
			}

		for(int i=small;i<=large;i++)
			if(arr[i]>max)
				max=arr[i];
						
		for(int i=n-1;i>=large;i--)
			if(arr[i]<max)
			{
				large=i;
				cout<<"LARGE:"<<large;
				//break;
			}
			
		cout<<small<<" "<<large;
	}
}
