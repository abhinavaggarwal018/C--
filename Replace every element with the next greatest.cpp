#include<iostream>

using namespace std;

int main()
{
	int n,arr[100],ans[100],maxm=-1;
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=n-1;i>=0;i--)
	{
		ans[i]=maxm;
		maxm=max(maxm,arr[i]);
	}
	
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
}
