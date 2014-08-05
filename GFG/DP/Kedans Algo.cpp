#include<iostream>
#include<climits>

using namespace std;

int main()
{
	int arr[]={-2, -3, -4, -1, -2, -1, -5, -3};
   int n = sizeof(arr)/sizeof(arr[0]);;
	
	int max_sum=INT_MIN;
	int curr_sum=0;
	
	for(int i=0;i<n;i++)
	{
		curr_sum+=arr[i];
		if(curr_sum>max_sum)
			max_sum=curr_sum;
			
		curr_sum=max(0,curr_sum);
	}
	
	cout<<max_sum;
}
