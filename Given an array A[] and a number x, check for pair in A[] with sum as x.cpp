#include<iostream>

using namespace std;


void merge(int arr[], int start, int mid, int end)
{
	int a=start,b=mid+1,c[10000],ind=0;
	while(a <= mid && b <= end)
	{
		if(arr[a]<=arr[b])
		{
			c[ind]=arr[a];
			ind++;
			a++;
		}
		
		else
		{
			c[ind]=arr[b];
			ind++;
			b++;
		}
	}
	
	while(a <= mid)
	{
			c[ind]=arr[a];
			ind++;
			a++;
	}
	
	while( b <= end)
	{
			c[ind]=arr[b];
			ind++;
			b++;
	}
	
	for(int i=0;i<ind;i++)
	{
		arr[start+i]=c[i];
	}

}

void merge_sort(int arr[],int start,int end)
{
	if(start==end)
		return;
	
	int mid=start+(end-start)/2;

	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,mid,end);

}

void find_same_sum(int arr[], int n,int k)
{
	int start=0,end=n-1,sum;
	while(start!=end&&start<end)
	{
		sum=(arr[start]+arr[end]);
		if(sum==k)
		{
			cout<<"\n"<<arr[start]<<" and "<<arr[end];
			start++;
			end--;
		}
		
		else if(sum<k)
			start++;
			
		else
			end--;
	}
}

void nlogn_method(int arr[],int n,int sum)
{
	merge_sort(arr,0,n-1);
	find_same_sum(arr,n,sum);
}
int main()
{
	int arr[50],n,sum;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>sum;		
	
	nlogn_method(arr,n,sum);	
	
	
}


