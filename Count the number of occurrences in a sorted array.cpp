	/*
Count the number of occurrences in a sorted array
May 3, 2011

Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)

Examples:

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
  Output: 4 // x (or 2) occurs 4 times in arr[]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
  Output: 1 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
  Output: 2 

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
  Output: -1 // 4 doesn't occur in arr[] 
  */
  
#include<iostream>

using namespace std;

int b_search_floor(int arr[],int start,int end, int key)
{
	cout<<"\n"<<start<<" "<<end;
	if(start>=end)
		return start;
	
	if(end-start==1)
	{
		if(arr[start]==key)
			return start;
		return end;
	}
		
	int mid=start+(end-start)/2;
		
	if(arr[mid] >= key )
		b_search_floor(arr,start,mid,key);
		
	else
		b_search_floor(arr,mid+1,end,key);
}

int b_search_ceil(int arr[],int start,int end, int key)
{
	cout<<"\n"<<start<<" "<<end;
	if(start>=end)
		return start;
		
	if(end-start==1)
	{
		if(arr[end]==key)
			return end;
		return start;
	}
		
	int mid=start+(end-start)/2;
		
	if(arr[mid] > key )
		b_search_ceil(arr,start,mid-1,key);
		
	else
		b_search_ceil(arr,mid,end,key);
}

int main()
{
	int n,arr[1000],key;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>key;
		
		cout<<"\nMin:"<<b_search_floor(arr,0,n-1,key);
		cout<<"\nMax:"<<b_search_ceil(arr,0,n-1,key);		
	}
}
