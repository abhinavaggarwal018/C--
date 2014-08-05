#include<iostream>

using namespace std;

int arr[100][100];

void change_reduce(int a, int m,int n,int size)
{
	if(a==size-1)
		return;
	
	for(int i=a;i<size;i++)
	{
		int temp=arr[i][a];
		arr[i][a]=arr[0][i];
		arr[a][i]=temp;
	}
	
	change_reduce(a+1,m,n,size);
}

int main()
{
	int m,n;
	while(1)
	{
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				arr[i][j]=0;
		
		cin>>m>>n;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];

		int size=max(m,n);				
		
		change_reduce(0,m,n,size+1);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
	}
}
