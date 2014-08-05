#include<iostream>
using namespace std;
int t,n,val[105][105],arr[105][105];
int max(int a, int b)
{
	if(a>b)
	return a;
	return b;
}
int find_val()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			arr[i][j]=max(arr[i-1][j],arr[i-1][j-1])+val[i][j];
		}
	}
	int max=0;
	for(int i=0;i<=n;i++)
	{
		if(arr[n][i]>max)
		max=arr[n][i];
	}
	return max;
}
int main()
{
	cin>>t;

	for(int l=0;l<t;l++)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			val[i][j]=0;
			arr[i][j]=0;
		}

		for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		cin>>val[i][j];
		cout<<find_val()<<"\n";
	}
	
}
