#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

	int r,c;
	char arr1[4][8]={"***^***","***|***","***|***","***|***"};
	char arr[100][100];

	while(1)
	{
		r=4;c=7;
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				arr[j][r-i-1]=arr1[i][j];
		
		
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<r;j++)
				cout<<arr[i][j]<<" ";
			
			cout<<"\n";
		}
		getchar();
	}
}
