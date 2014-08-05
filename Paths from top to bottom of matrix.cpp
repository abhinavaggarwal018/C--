#include<iostream>

using namespace std;

int main()
{
	int arr[100][100],n;
	cin>>n;
	
	arr[0][0]=1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(j>0)
				arr[i][j]+=arr[i][j-1];
			
			if(i>0)
				arr[i][j]+=arr[i-1][j];
		}
	
	cout<<"\n";
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
			
		cout<<"\n";
	}
}
