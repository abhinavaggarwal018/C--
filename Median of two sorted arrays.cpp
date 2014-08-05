#include<iostream>

using namespace std;


int median(int arr[],int low,int high)
{
	
	int mid=low+(high-low)/2;
	if((high-low)%2==0)
		return (arr[mid-1]+arr[mid])/2;
	else
		return arr[mid];
}

int find_median(int arr1[],int arr2[],int low1,int high1,int low2, int high2)
{
	
	cout<<high1-low1<<"\t"<<high2-low2<<"\n";
	
	int m1=median(arr1,low1,high1);
	int m2=median(arr2,low2,high2);
	
	cout<<"\nint find_median(int arr1[],int arr2[],int low1 "<<low1<<" ,int high1, "<<high1<<" int low2, "<<low2<<" int high2"<<high2<<") Median1: "<<m1<<" Median2: "<<m2;
	int l;
	cin>>l;

	if(high1==low1 || high2==low2)
		return (m1+m2)/2;
	
	if(high1-low1<=1 || high2-low2<=1)
		return (arr1[low1]+arr2[low2])/2;
	
	int n=min(high1-low1,high2-low2)/2;
	if(m1==m2)
		return m1;
		
	if(m1>m2)
		return find_median(arr1,arr2,low1,high1-n,low2+n,high2);
		
	if(m2>m1)
		return find_median(arr1,arr2,low1+n,high1,low2,high2-n);
}

void find_median_wrapper(int arr1[],int arr2[],int n)
{
	cout<<find_median(arr1,arr2,0,n,0,n);
}

int main()
{
	int n,arr1[100],arr2[100];
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr1[i];
		
	for(int i=0;i<n;i++)
		cin>>arr2[i];
		
	find_median_wrapper(arr1,arr2,n);
}
