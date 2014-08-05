#include<iostream>

using namespace std;

int find_candidate(int arr[],int n)
{
	int cnt=1,val=arr[0];
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]==val)
			cnt++;
		else if(arr[i]!=val)
			cnt--;
			
		if(cnt<0)
		{
			cnt=1;
			val=arr[i];
		}
	}
	
	if(cnt>0)
	{	
		cnt=0;
		for(int i=0;i<n;i++)
			if(val==arr[i])
				cnt++;
				
		if(cnt>n/2)
			return val;
		return -1000;	
	}
}

int main()
{
	int n,arr[100];
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cout<<find_candidate(arr,n);
}
