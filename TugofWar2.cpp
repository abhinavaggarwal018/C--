#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int ans[1000];
int error=INT_MAX;

int find_subset_sum(int arr[],int start, int sum, int curr_sum, int ele[], int cnt, int n)
{
	if(cnt==n/2 && error > abs(sum-curr_sum))
	{
		for(int i=0;i<cnt;i++)
			ans[i]=ele[i];
			
		error=sum-curr_sum;
		return 0;
	}
	
	for(int i=start;i<n;i++)
	{
		curr_sum+=arr[i];
		ele[cnt]=arr[i];
		cnt++;
		find_subset_sum(arr,i+1,sum, curr_sum,ele,cnt,n);
		cnt--;
		curr_sum-=arr[i];
	}
}

int main()
{
	int arr[]={1,2,6,9,7,1000};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ele[1000]={0},sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
		
	find_subset_sum(arr,0,sum/2,0,ele,0,n);
	
	for(int i=0;i<n/2;i++)
		cout<<ans[i]<<" ";
	cout<<"\nError:"<<2*error;
}
