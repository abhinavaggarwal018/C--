#include<iostream>
#include<cstdio>
using namespace std;


#define MOD 109546051211LL

long long mult(long long a,long long b)
{
	
	if(b==0)
		return 0;

	long long int ans=a;
	
	long long int num=b%10;
	return (( ( ( a*num ) % MOD) + mult( ( a*10 ) % MOD, b/10) ) % MOD);
}

int main()
{
	long long int n,ans=1,prev=1;
	
	scanf("%lld",&n);
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	if(n>=587119)
	{
		cout<<0;
		return 0;	
	}
	
	for(int i=2;i<=n;i++)
	{
		prev=mult(prev,i);
		ans=mult(ans,prev);
	}
	
	cout<<ans;	
	
}

