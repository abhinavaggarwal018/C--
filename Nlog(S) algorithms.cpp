#include<iostream>

/*
You have to paint N boards of length {A0, A1, A2 … AN-1}. 
There are K painters available. 
You have to get this job done as soon as possible under the constraints that 
any painter will only paint continuous sections of board, say board {2, 3, 4} 
or only board {1} or nothing but not board {2, 4, 5}.*/

using namespace std;

int b_search(int arr[],int n,int start,int end,int k)
{
	int mid=start+(end-start)/2,cnt=1,sum=0,ans=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum>mid)
		{
			cnt++;
			ans=max(ans,sum-arr[i]);
			sum=arr[i];
		}
	}
	ans=max(ans,sum);

	if(cnt==k)
		return ans;
	else if(cnt>k)
		return b_search(arr,n,mid,end,k);
	else
		return b_search(arr,n,start,mid,k);
}

int main()
{
	int n,arr[]={100,200,300,400,500,600,700,800,900},maxm=-1000,sum=0,k;
	//cin>>n;
	n=9;
	
	for(int i=0;i<n;i++)
	{
	//	cin>>arr[i];
		
		sum+=arr[i];
		
		if(arr[i]>maxm)
			maxm=arr[i];
	}
	
	cin>>k;

	if(k==1)
		cout<<sum;
	else if(k>=n)
		cout<<maxm;
	else	
		cout<<b_search(arr,n,maxm,sum,k);
	return 0;
}
