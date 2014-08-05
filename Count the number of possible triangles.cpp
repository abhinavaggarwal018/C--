#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000];

void find_count(int[] ,int);

void insertion_sort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			arr[j]=key;			
			j--;
		}
		
	}
}

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		insertion_sort(arr,n);
				
		if(n<3)
			cout<<"Not possible\n";
		else	
			find_count(arr,n);
	}
}

void find_count(int arr[],int n)
{
	int i=0,j=1,k=2,ans=0;
	
	for(int i=0;i<n-2;i++)
	{
		k=i+2;
		for(int j=i+1;j<n-1;j++)
		{
			while(k<n&&arr[k]<(arr[i]+arr[j]))
				k++;
			
			ans+=k-j-1;
		}
	}
	cout<<ans;
			
}
