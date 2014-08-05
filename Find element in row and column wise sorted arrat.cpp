#include<iostream>
#include<cstdio>

using namespace std;

void find_num(int *arr[],int n,int m, int val)
{
	int r=0,c=m-1;
	while(1)
	{	
		if(r<n&&c>=0)
		{
			cout<<"No. does not exist\n";
			return;
		}
		if(arr[r][c]==val)
		{
			cout<<"Number exists at row:"<<r<<" column:"<<c;
			return;
		}
		else if(arr[r][c]<val)
			r++;
			
		else if(arr[r][c]>val)
			c--;
	}
}

int main()
{
	int n,m,**arr,val;
	
	while(1)
	{
		cin>>n>>m;
			arr= new int *[m];
		
		for(int i=0;i<n;i++)
			arr[i]= new int[n];
			
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		
		cin>>val;		
		find_num(arr,n,m,val);
	}
}
