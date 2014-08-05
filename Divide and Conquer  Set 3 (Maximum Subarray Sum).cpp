#include<iostream>

using namespace std;

int n,arr[100];

int merge(int start,int mid, int end)
{
	
	    // Include elements on left of mid.
    int sum = 0;
    int left_sum = -1000;
    for (int i = mid; i >= start; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    // Include elements on right of mid
    sum = 0;
    int right_sum = -1000;
    for (int i = mid+1; i <= end; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
    
}

int partition(int start,int end)
{
	int ans=0;
	if(start==end)
		return arr[start];
	if(start<end)
	{
		int mid=start+(end-start)/2;
		ans=max(partition(start,mid),partition(mid+1,end));
		ans=max(ans,merge(start,mid,end));
	}
	return ans;
}

int main()
{

	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cout<<partition(0,n-1);
	}
}
