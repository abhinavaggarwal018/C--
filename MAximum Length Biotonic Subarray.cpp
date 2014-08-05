/*	
Maximum Length Bitonic Subarray
December 14, 2011

Given an array A[0 ... n-1] containing n positive integers, a subarray A[i ... j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] ... <= A[k] >= A[k + 1] >= .. A[j - 1] > = A[j]. Write a function that takes an array as argument and returns the length of the maximum length bitonic subarray.
Expected time complexity of the solution is O(n)

Simple Examples
1) A[] = {12, 4, 78, 90, 45, 23}, the maximum length bitonic subarray is {4, 78, 90, 45, 23} which is of length 5.

2) A[] = {20, 4, 1, 2, 3, 4, 2, 10}, the maximum length bitonic subarray is {1, 2, 3, 4, 2} which is of length 5.

Extreme Examples
1) A[] = {10}, the single element is bitnoic, so output is 1.

2) A[] = {10, 20, 30, 40}, the complete array itself is bitonic, so output is 4.

3) A[] = {40, 30, 20, 10}, the complete array itself is bitonic, so output is 4.
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n, *arr,*left,*right,ans=0;
	while(1)
	{
		cin>>n;
		ans=0;
		arr   = new int[n+1];
		left  = new int[n+1];
		right = new int[n+1];
		
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		
		left[0]=1;
		right[n]=1;
		for(int i=1;i<=n;i++)
		{
			left[i]=arr[i]>=arr[i-1]?(left[i-1]+1):1;
			right[n-i]=arr[n-i]>=arr[n-i+1]?(right[n-i+1]+1):1;
		}
		
		for(int i=1;i<=n;i++)
			cout<<left[i]<<" ";
		
		cout<<"\n";
		
		for(int i=1;i<=n;i++)
			cout<<right[i]<<" ";
			
		for(int i=1;i<=n;i++)
			ans=max(ans,left[i]+right[i]-1);
		
		cout<<ans;
		
		delete arr;
		delete left;
		delete right;
		
		
	}
}
