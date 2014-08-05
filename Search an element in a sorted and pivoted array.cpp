/*	
Search an element in a sorted and pivoted array
August 15, 2009

Question:
An element in a sorted array can be found in O(log n) time via binary search. 
But suppose I rotate the sorted array at some pivot unknown to you beforehand. 
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
Devise a way to find an element in the rotated array in O(log n) time.
*/

#include<iostream>

using namespace std;

void b_search(int arr[],int start,int end,int num)
{
	cout<<start<<" "<<end<<"\n";
	if(start>end)
	{
		cout<<"Number does not exist\n";
		return;
	}
	
	int mid=start+(end-start)/2;
	
	if(arr[start]==num)
	{
		cout<<"Number exists at index:"<<start<<"\n";
		return;
	}
	
	if(arr[mid]==num)
	{
		cout<<"Number existsat index:"<<mid<<"\n";
		return;
	}
		
	if(arr[end]>arr[start])
	{
		if(num<arr[mid])
			return b_search(arr,start,mid-1,num);		
		else if(num>arr[mid])
			return b_search(arr,mid+1,end,num);
	}
	
	else if(arr[mid]>=arr[start])
	{
		if(num<arr[mid]&&num>arr[start])
			return b_search(arr,start,mid-1,num);		

		else if(num<arr[mid]&&num<arr[start])
			return b_search(arr,mid+1,end,num);

		else if(num>arr[mid])
			return b_search(arr,mid+1,end,num);
	}	
	
	else if(arr[mid]<arr[start])
	{
		if(num<arr[start])	
		{
			if(num<arr[mid])
				return b_search(arr,start,mid-1,num);		

			else if(num>arr[mid])
				return b_search(arr,mid+1,end,num);
		}
		
		else if(num>arr[start])
			return b_search(arr,start,mid-1,num);
	}
}

void binary_search(int arr[],int start,int end,int num)
{
	if(start>end)
	{
		cout<<"Not found\n";
		return;
	}
	
	if(start==end && arr[start]==num)
	{
		cout<<"Found at index:"<<start;
		return;
	}
	
	if(start==end)
	{
		cout<<"Not found\n";
		return;
	}
	
	int mid=start+(end-start)/2;
	
	if(arr[mid]==num)
	{
		cout<<"Found at index:"<<mid;
		return;
	}
	
	if(arr[mid]>num)
		return b_search(arr,start,mid-1,num);
		
	else
		return b_search(arr,mid+1,end,num);
}

int find_pivot(int arr[],int start,int end)
{
	cout<<"\n"<<start<<"\t"<<end<<"\n";


	if(arr[start]<arr[end])
		return start;

	if(end-start==1)
	{
		if(arr[start]>arr[end])
			return start;
		return end;
	}

	int mid=start+(end-start)/2;

	if(start==end)
		return start;

	if(arr[mid]>arr[mid+1])
		return mid;

	if(arr[mid]>arr[start])
		return find_pivot(arr,mid+1,end);
		
	else
		return find_pivot(arr,start,mid-1);

}

void b_search_wrapper(int arr[],int end,int num)
{
	int pivot=find_pivot(arr,0,end);
	cout<<"pivot: "<<pivot<<"\n";
	if(num==arr[0])
	{
		cout<<"No. found at index: 0\n";
		return;
	}
	
	if(num==arr[pivot])
	{
		cout<<"No. found at index: "<<pivot<<"\n";
		return;
	}
	
	if(num==arr[pivot+1])
	{
		cout<<"No. found at index: "<<pivot+1<<"\n";
		return;
	}
	
	if(num==arr[end])
	{
		cout<<"No. found at index: "<<end<<"\n";
		return;
	}
	
	if(num>arr[0]&&num<arr[pivot])
		return binary_search(arr,0,pivot,num);
	else
		return binary_search(arr,pivot+1,end,num);
}

int main()
{
	int n,arr[100],num,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>num;
		b_search_wrapper(arr,n-1,num);
	}
}
