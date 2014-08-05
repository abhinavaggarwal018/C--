#include<iostream>
using namespace std;
int arr[]={1,2,3,11,22,101,111,121,202,212};

int main()
{
	for(int i=0;i<9;i++)
	{
		arr[i]=arr[i]*arr[i];
	}	
	int t,a,b;
	cin>>t;
	for(int l=0;l<t;l++)
	{
		int count=0;
		cin>>a>>b;	
	for(int i=0;i<9;i++)
	{
		if(arr[i]>=a && arr[i]<=b)
		count++;
	}
	cout<<"Case #"<<l+1<<": "<<count<<"\n";
	}
}//1,3,11,22,101,111,121,202,212,
