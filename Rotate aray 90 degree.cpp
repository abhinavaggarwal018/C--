#include<iostream>

using namespace std;

int main()
{
	int n=5,arr1[10][10];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr1[i][j]=(i+2)*(j+1);
			
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr1[i][j]<<"\t";
		cout<<"\n";
	}
	int x='abcd';
	cout<<x;
	cout<<"\n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr1[n-1-j][i]<<"\t";
		cout<<"\n";
	}
	
	
	
}
