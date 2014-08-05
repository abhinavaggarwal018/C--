/*
Floor and Ceiling in a sorted array
May 11, 2010

Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. 
Assume than the array is sorted in non-decreasing order. 
Write efficient functions to find floor and ceiling of x.
*/

#include<iostream>
#include<cstdio>

using namespace std;

int arr[100];

int b_search(int start,int end,int num)
{
	cout<<"int b_search(int start:"<<start<<" ,int end:"<<end<<" ,int num:"<<num<<" )\n";
	getchar();
	if(start>=end)
		return start;
		
	int mid=start+(end-start)/2;
	
	cout<<mid<<" "<<num<<" "<<arr[mid]<<"\n";
	
	if(arr[mid]==num)
		return mid;
		
	if(arr[mid]>num)
		return b_search(start,mid-1,num);
		
	else
		return b_search(mid+1,end,num);
}

int main()
{
	int n,num,ans;
	
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>num;
		ans=b_search(0,n-1,num);
	
		if(arr[ans]<num && ans==n-1)
			cout<<"Floor is:"<<arr[n-1]<<" and ceil does not exist\n";
			
		else if(ans<=0)
			cout<<"Floor does not exist and ceil is:"<<arr[0]<<"\n";
			
		else if(arr[ans]!=num)
			cout<<"Floor is:"<<arr[ans-1]<<" and ceil is: "<<arr[ans];
		else
			cout<<"Floor is:"<<arr[ans]<<" and ceil is: "<<arr[ans];
	}
}
