#include<iostream>

using namespace std;

int n,arr[100];

int find_lis(int arr[],int end,int &max1)
{
	cout<<"find_lis(int arr[],int end:"<<end<<")\n";
	if(end==1)
		return 1;
	
	int curr_max=1,curr;	
		
	for(int i=1;i<end;i++)
	{
			curr=find_lis(arr,i,max1);
			if((curr+1)>curr_max && (arr[end-1]>arr[i-1]))
				curr_max=curr+1;
	}
	
	if(max1<curr_max)
		max1=curr_max;
		
	return curr_max;
}

int lis_dp(int arr[],int end)
{
	if(end==1)
		return 1;
		
	int *lis=new int[end];
		
	for(int i=0;i<end;i++)
		lis[i]=1;
		
	int curr_max=1,curr;
	
	for(int i=0;i<end;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i]&&((lis[j]+1)>lis[i]))
				lis[i]=lis[j]+1;
		}
	}
	int ans=-10000;
	for(int i=0;i<end;i++)
		ans=max(ans,lis[i]);
	delete lis;
	return ans;
}

int main()
{
	int ans,max1=0;
	while(1)
	{
		max1=1;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		find_lis(arr,n,max1);
		cout<<max1;
		cout<<lis_dp(arr,n);
	}
}
