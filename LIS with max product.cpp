/*
Find the Increasing subsequence of length three with maximum product.
Given a sequence of non-negative integers, find the subsequence of length 3 having maximum product with the numbers of the subsequence being in ascending order.

Examples:

 
Input: 
arr[] = {6, 7, 8, 1, 2, 3, 9, 10} 
Output: 
8 9 10

Input: 
arr[] = {1, 5, 10, 8, 9}
Output: 5 8 9

Since we want to find the maximum product, we need to find following two things for every element in the given sequence:
LSL: The largest smaller element on left of given element
LGR: The largest greater element on right of given element.

Once we find LSL and LGR for an element, we can find the product of element with its LSL and LGR (if they both exist). 
We calculate this product for every element and return maximum of all products.
*/

#include<iostream>
int ans=0,n,ans1,ans2,ans3,left_max[10000],right_max[10000];
using namespace std;

int merge(int arr[],int start,int mid,int end)
{
	cout<<" "<<mid<<" \n";
	int a=start,b=mid+1,c[10000],index=0,lsl=0,lsr=0,num=arr[mid];
	while(a<=mid&&b<=end)
	{
		if(arr[a]<=arr[b])
		{
			if(lsl<arr[a]&&arr[a]<=arr[mid]&&a!=mid)
				lsl=arr[a];
				
			c[index]=arr[a];
			index++;
			a++;
		}
		else
		{
			if(lsr<arr[b] && arr[b]>=arr[mid])
				lsr=arr[b];
				
			c[index]=arr[b];
			index++;
			b++;
		}
	}
	
	while(a<=mid)
	{
		if(lsl<arr[a] && arr[a]<=arr[mid]&&a!=mid)
			lsl=arr[a];
	
		c[index]=arr[a];
		index++;
		a++;
	}
	
	while(b<=end)
	{
		if(lsr<arr[b] && arr[b]>=arr[mid])
			lsr=arr[b];
	
		c[index]=arr[b];
		index++;
		b++;
	}
	
	for(int i=0;i<index;i++)
		arr[start+i]=c[i];
		
	if(start!=0)
		lsl=max(lsl,b_search_floor(num));// get floor val of num
		
	if(end!=n-1)
		lsr=max(lsr,right_max[end]);
	
	if(lsr<arr[mid])
		lsr=0;
	if(ans<(lsl*lsr*num))
		ans=(lsl*lsr*num);
		
	cout<<"ans"<<ans<<"=(lsl"<<lsl<<"*"<<"lsr"<<lsr<<"*num"<<num<<")\n";
	ans1=lsl;ans2=num;ans3=lsr;
}

void merge_sort_modified(int arr[], int start,int end)
{
	int mid=start+(end-start)/2;
	
	if(start<end)
	{
		merge_sort_modified(arr,start,mid);
		merge_sort_modified(arr,mid+1,end);
		merge(arr,start,mid,end);
	}

}

int main()
{
	int arr[1000];
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		left_max[1]=arr[0];
		
		for(int i=2;i<n;i++)
		{
			if(arr[i-1]>left_max[i-1])
				left_max[i]=arr[i-1];
			else
				left_max[i]=left_max[i-1];
		}
				
		right_max[n-1]=0;
		right_max[n-2]=arr[n-1];
		
		for(int i=n-3;i>=0;i--)
		{
			if(arr[i+1]>right_max[i+1])
				right_max[i]=arr[i-1];
			else
				right_max[i]=left_max[i-1];
		}
		
		merge_sort_modified(arr,0,n-1);
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
			
		cout<<ans1<<" "<<ans2<<" "<<ans3;
		cout<<"\n"<<ans;
	}
}

