#include<iostream>

using namespace std;

int n,arr[100][100];

void print_diag()
{
	for(int i=0;i<n;i++)
	{
		int k=i;
	
		for(int j=0;j<=i;j++,k--)
			cout<<arr[k][j]<<" ";
		
		cout<<"\n";
	}
	
	for(int i=1;i<n;i++)
	{
		int k=i;
	
		for(int j=n-1;j>=i;j--,k++)
			cout<<arr[j][k]<<" ";
		
		cout<<"\n";
	}	

}


int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	
	print_diag();
}
