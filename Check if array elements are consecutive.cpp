#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,arr[100],start,min_no=1000;
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]<min_no)
				min_no=arr[i];
		}
		for(int i=0;i<n;i++)
			arr[abs(arr[i])-min_no]=-arr[abs(arr[i])-min_no];
		
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
				
		cout<<true;
		
	}
}
