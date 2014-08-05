#include<iostream>

using namespace std;

int main()
{
	int n, ans=0, div=5, val=1;
	cin>>n;
	
	while(val!=0)
	{
		val=n/div;
		ans+=val;
		div=div*5;
	}
	
	cout<<ans;
}
