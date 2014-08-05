#include<iostream>
#include<cstdio>

using namespace std;

int b_search_small(int arr[],int start,int end,int num)
{
	getchar();
	int mid=start+(end-start)/2;
	cout<<"int b_search_small(int arr[],int start: "<<start<<" ,int end: "<<end<<" ,int num"<<num<<") mid: "<<mid<<" \n";
	
	if(start>=end)
		return start;
		
	if(arr[mid]<num)
		return b_search_small(arr,mid+1,end,num);
	else
		return b_search_small(arr,start,mid,num);
}

int b_search_big(int arr[],int start,int end,int num)
{
	getchar();
	int mid=start+(end-start)/2;
	cout<<"int b_search_big(int arr[],int start: "<<start<<" ,int end: "<<end<<" ,int num"<<num<<") mid: "<<mid<<" \n";

	if(start>=end)
		return start;
	
	if(end-start==1)
	{
		if(arr[end]==num)
			return end;
		return mid;
	}

	if(arr[mid]<=num)
		return b_search_big(arr,mid,end,num);
	else
		return b_search_big(arr,start,mid-1,num);
}

int main()
{
	int n,arr[100],num;
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		num=arr[n/2];
		cout<<"1";
		cout<<"\nb_search_small(arr,0,n,num):"<<b_search_small(arr,0,n/2,num);
		cout<<"\nb_search_big(arr,0,n,num):"<<b_search_big(arr,n/2,n-1,num);
	}
}
