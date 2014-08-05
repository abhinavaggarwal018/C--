#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	long long int n, t,ans,val,n1;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		n1=n;
		ans=0;
		while(n1--)
		{
			cin>>val;
			ans+=val;
			ans=ans-n*(ans/n);
		}
		
		if(ans%n)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	
}
