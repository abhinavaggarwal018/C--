// 2 numbers occur odd number of times

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,arr[100],ans=0,num;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		ans=ans^arr[i];
	}
	num=ans&(-ans);
	
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		if(num&arr[i])
			ans1=ans1^arr[i];
			
		else 
			ans2=ans2^arr[i];
	}
	
	cout<<"\n"<<ans1<<" and "<<ans2;
}
