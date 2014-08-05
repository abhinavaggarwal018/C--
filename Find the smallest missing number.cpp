/*	
Find the smallest missing number
April 17, 2011

Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

Examples
Input: {0, 1, 2, 6, 9}, n = 5, m = 10
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
Output: 8

*/

#include<iostream>

using namespace std;

void b_search(int arr[],int start,int end)
{
	cout<<"start:"<<start<<" end:"<<end<<"\n";
	if(start>end)
	{
		cout<<"The element is:"<<start<<"\n";
		return;
	}
	
	int mid=start + (end-start)/2;
	
	if(arr[mid]==mid)
		return b_search(arr,mid+1,end);
	else
		return b_search(arr,start,mid-1);
}

int main()
{
	int n,arr[50],m;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>m;
		
		if(arr[0]!=0)
			cout<<"The element is: 0\n";
		
		else
			b_search(arr,0,n-1);
	}
}
