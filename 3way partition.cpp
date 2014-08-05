
#include<iostream>

using namespace std;

int mid=0,high=100,n;

void swap(int arr[],int start,int end)
{
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
}

void partition(int arr[],int start,int end)
{
	mid=start;
	high=end;
	while(mid<=high)
	{
		cout<<"\n";
		cout<<"mid:"<<mid<<" high:"<<high<<"\n";
		
		if(arr[mid]==0)
		{
			swap(arr,mid,start);
			start++;
			mid++;
		}
		
		else if(arr[mid]==1)
			mid++;
		
		else if(arr[mid]==2)
		{
			swap(arr,mid,high);
			high--;
		}
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		
		
	}
}

int main()
{
	while(1)
	{
		int arr[1000];
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		partition(arr,0,n-1);
	
		for(int i=0;i<n;i++)
			cout<<arr[i];
			
		cout<<high<<" "<<mid<<"\n";
	}
}
