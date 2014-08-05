#include<iostream>
//can be done... exiting

using namespace std;

int main()
{
	while(1)
	{
 	cin>>m>>n;

		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		
		int p=0,q=0;
		
		while(p<m&&q<n)
		{
			for( ;q<n; q++)
				cout<<arr[p][q];
			q--;// for neglecting exit condition for 'for loop'	
			p++;
			
			for(;p<m;p++)
				cout<<arr[p][q];
			
			p--;	
			q--;
			
			for(;q>=0;q--)
				cout<<arr[p][q];
				
			for(;p)
		}
	}
}
