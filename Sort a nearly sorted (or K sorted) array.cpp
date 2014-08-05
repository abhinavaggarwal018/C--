#include<iostream>

using namespace std;

int ans[100];

void insertion_sort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int key=arr[i];
		int j=i-1,temp;
		while(arr[j]>key&&j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
}

void min_heapify(int arr[],int start,int end)
{
	int left=2*start +1;
	int right=left+1;
	
	if(left>end||right>end)
		return;
	
	if(arr[start]>=arr[left]&& arr[start]>=arr[right])
		return;
	
	else if(arr[left]>=arr[start]&&arr[left]>=arr[start])
	{
		swap(arr[left],arr[start]);
		return min_heapify(arr,left,end);
	}
	
	else
	{
		swap(arr[right],arr[start]);
		return min_heapify(arr,right,end);
	}
}

void heaps(int arr[],int n,int k)
{
	for(int i=k/2;i>=0;i++)
		min_heapify(arr,0,i);  // k+1 elements from 0 to k
	int ind=0;
	ans[ind]=arr[0];
	ind++;
	
	for(int i=k+1;i<n;i++)
	{
		arr[0]=arr[k];
		min_heapify(arr,0,k);
		ans[ind]=k;
		ind++;
	}
	
	for(int i=0;i<k;i++)
	{
		arr[0]=arr[k-i];
		min_heapify(arr,0,k-i);
		ans[ind]=k;
		ind++;
	}
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
}

int main()
{
	int n,arr[1000],k;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>k;
		insertion_sort(arr,n);
	}
}
