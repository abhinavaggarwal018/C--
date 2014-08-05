/*
	
Largest subarray with equal number of 0s and 1s
June 26, 2012

Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).

Examples:

Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6 (Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4

*/
#include<iostream>

using namespace std;

int main()
{
	int n,arr[1000],temp[1000];
	while(1)	
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		if(arr[0]==0)
			temp[0]=-1;
		else
			temp[0]=1;
			
		for(int i=1;i<n;i++)
		{
			if(arr[i]==0)
				temp[i]=temp[i-1]-1;
			else
				temp[i]=temp[i-1]+1;
		}
		
		int min_no=1000,max_no=-1000,ans=-100;;
		
		for(int i=0;i<n;i++)
		{
			min_no=min(temp[i],min_no);
			max_no=max(temp[i],max_no);
		}
		
		int *hash= new int[max_no-min_no+1];
		
		for(int i=0;i<max_no-min_no+1;i++)
			hash[i]=-2;
		
		hash[0]=-1;
			
		for(int i=0;i<n;i++)
		{
			if(hash[temp[i-min_no]]==-2)
				hash[temp[i-min_no]]=i;
			else
				ans=max(ans,i-hash[temp[i-min_no]]);
		}
		
		cout<<ans;
		
		delete hash;
	}
}
