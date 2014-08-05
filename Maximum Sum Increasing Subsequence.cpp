#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int arr[1000],n;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		int val[100]={0};
		
		for(int i=0;i<n;i++)
			val[i]=arr[i];
		
		int temp=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
				if(arr[i]>arr[j]&&(val[j]+arr[i])>val[i])
					val[i]=val[j]+arr[i];
			temp=max(temp,val[i]);
		}
		
		for(int i=0;i<n;i++)
			cout<<val[i]<<" ";
		cout<<temp;
		
	}
}
