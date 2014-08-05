/*
	
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
May 21, 2011

Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples:

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output: -1 
  
  */
  
#include<iostream>

using namespace std;

int main()
{
	int n,arr[100],left[100],right[100],num1,num2,max_diff;
	
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		left[0]=arr[0];
		for(int i=1;i<n;i++)
			left[i]=min(arr[i],left[i-1]);
			
		right[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--)
			right[i]=max(arr[i],right[i+1]);
			
		max_diff=-100;
		int i=0,j=0;
		while(i<n&&j<n)
		{
			if(right[j]>left[i])
			{
				max_diff=max(max_diff,j-i);
				if(j-i==max_diff)
				{
					num1=i;
					num2=j;
				}
				j++;
			}
			else
				i++;
		}
		cout<<"Left[i]:"<<num1<<"Right[i]:"<<num2<<"Max_Diff[i]:"<<max_diff<<"\n";
	}
}
