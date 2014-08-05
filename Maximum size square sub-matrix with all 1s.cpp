#include<iostream>

using namespace std;

int main()
{
	int arr[100][100],r,c;
	
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>arr[i][j];

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)			
		{
			if(arr[i][j]!=0)
				arr[i][j] = min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
			else
				arr[i][j] = 0;
		}
		
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
}
