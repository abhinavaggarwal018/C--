#include<iostream>

using namespace std;

int sum=0,n=0,arr[1000];

int find(int start,int end,int sum)
{
	if(start>end)
		return sum;
		
	if(arr[start]<sum)
		return min(find(start+1,end,sum-arr[0]),find(start+1,end,sum));
		
	if(arr[start]>sum)
		return find(start+1,end,sum);
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	
	cout<<"Ans is:"<<min(find(1,n-1,sum-arr[0]),find(1,n-1,sum))<<"This\n";
}
