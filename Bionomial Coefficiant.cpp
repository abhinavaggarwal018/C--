#include<iostream>
#include<vector>

using namespace std;

int coeff(int n,int k)
{
	vector< vector<int> > arr((n+1),vector<int> (k+1));
	
	for(int i=0;i<=k;i++)
		arr[0][i]=1;

	for(int i=0;i<=n;i++)
		arr[i][0]=1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=min(i,k);j++)
			if(i==j)
				arr[i][j]=1;
			else
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	
	return arr[n][k];
}

int main()
{
	int n,k;
	while(1)
	{
		cin>>n>>k;
		cout<<coeff(n,k);
	}
}
