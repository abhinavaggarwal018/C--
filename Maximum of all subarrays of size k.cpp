/*http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
*/

#include<iostream>
#include<queue>
using namespace std;

void max_subarrays(int arr[],int n,int k)
{
	deque<int> dq;
	dq.push_front(0);
	
	for(int i=1;i<k;i++)
	{
		while(!dq.empty()&&arr[i]>arr[dq.back()])
			dq.pop_back();
			
		dq.push_back(i);
	}
	
	for(int i=k;i<n;i++)
	{
		cout<<arr[dq.front()]<<" ";
		
		while(!dq.empty()&&dq.front()<=i-k)
			dq.pop_front();
			
		while(!dq.empty()&&arr[i]>arr[dq.back()])
			dq.pop_back();
			
		dq.push_back(i);
	}
	cout<<arr[dq.front()]<<" ";
}

int main()
{
	int n,arr[100],k;
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>k;
		max_subarrays(arr,n,k);
	}	
}
