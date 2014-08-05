#include<iostream>

using namespace std;

int main()
{
	int n,arr[100];
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		int min_sum=10000,temp=0,ind=0;
		
		for(int i=0;i<n;i++)
		{
			temp+=arr[i];
			min_sum=min(temp,min(arr[i],min_sum));
			if((min_sum==arr[i]||min_sum==temp)&&min_sum<0)
				ind=i+1;
	
			if(temp>0)
				temp=0;
		}
		
		if(ind==n)
			ind=0;
		
		//cout<<ind;
		
		int sum=-10000;temp=0;
		
		for(int i=ind;i<n;i++)
		{
			temp+=arr[i];
			sum=max(temp,max(sum,arr[i]));
						
			if(temp<0)
				temp=0;
		}
		for(int i=0;i<ind;i++)
		{
			temp+=arr[i];
			sum=max(temp,max(sum,arr[i]));
			
			if(temp<0)
				temp=0;
		}
		
		cout<<sum;
	}
}
