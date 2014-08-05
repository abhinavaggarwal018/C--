/*
http://stackoverflow.com/questions/5534063/zero-sum-subarray
*/

#include<iostream>

using namespace std;

int main()
{
	int n, arr[100],temp[100];
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		temp[0]=arr[0];
		for(int i=0;i<n;i++)
			temp[i]=temp[i-1]+arr[i];
		
		int max_ele=arr[0],min_ele=arr[0];
		for(int i=1;i<n;i++)
		{
			max_ele=max(max_ele,temp[i]);
			min_ele=min(min_ele,temp[i]);
		}
		
		int *hash=new int[max_ele-min_ele+1];
		
		for(int i=0;i<max_ele-min_ele+1;i++)
			hash[i]=-1;
		
		for(int i=0;i<n;i++)
		{
			if(hash[temp[i]-min_ele]!=-1)
				cout<<"Pair "<<i<<" and "<<hash[temp[i]-min_ele]<<"\n";
			else
				hash[temp[i]-min_ele]=i;
		}
	}
}
