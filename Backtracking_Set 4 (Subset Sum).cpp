#include<iostream>

using namespace std;

void find_subset(int arr[], int start, int sum, int curr_sum, int ele[], int cnt, int n)
{
	if(curr_sum==sum)
	{
		for(int i=0;i<cnt;i++)
			cout<<ele[i]<<" ";
		cout<<"\n\n";
		return;
	}
	
	if(curr_sum>sum)
		return;
		
	for(int i=start;i<n;i++)
	{
		curr_sum=curr_sum+arr[i];
		ele[cnt]=arr[i];
		cnt++;
		
		find_subset(arr,i+1,sum,curr_sum,ele,cnt,n);
		
		cnt--;
		curr_sum-=arr[i];
	}
}

int main()
{
	int arr[]={15, 22, 14, 26, 32, 9, 16, 8};
	int sum=53;
	int ele[1000]={0};
	int n=(sizeof(arr))/(sizeof(arr[0]));
	find_subset(arr, 0, sum, 0, ele, 0,n);
}
