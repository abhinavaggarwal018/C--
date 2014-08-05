#include<iostream>

using namespace std;

int main()
{
	int n,k,arr[100],maxm;
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cin>>k;
		
	for(int i=0;i<n;i++)
		arr[arr[i]%k]+=k;
		
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		
	for(int i=0;i<n;i++)
		if(arr[i]/k>maxm)
			maxm=arr[i]/k;
	
	cout<<"\n";		
			
	for(int i=0;i<n;i++)
		if(arr[i]/k==maxm)
			cout<<i<<" ";
}
