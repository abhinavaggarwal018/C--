#include<iostream>

using namespace std;

int main()
{
	int n,arr[1000],temp,sum;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cin>>sum;	
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]<arr[i])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		
		for(int i=0;i<n;i++)
		{
			temp=arr[i];
			int a=0,b=n-1;
			while(a<b)
			{
				if(a==i)
					a++;
				else if(b==i)
					b--;
				else if(arr[a]+arr[b]+temp==sum)
				{
					cout<<"The numbers are :"<<temp<<", "<<arr[a]<<" and "<<arr[b]<<"\n";
					a++;b--;
				}
				else if(arr[a]+arr[b]+temp<sum)
					a++;
				else if(arr[a]+arr[b]+temp>sum)
					b--;
			}
		}
	}
}
