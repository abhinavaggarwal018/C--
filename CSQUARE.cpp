#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

long long int find_pow(long long int a, char b[], long long int m)
{
	int i=strlen(b)-1;
	long long int res=1;
	
	while(i>=0)
	{
		if((b[i]-'0')==1)
		{
			long long int temp=res*a;
			res=temp - m*(temp/m);
		}
		
		else if((b[i]-'0')==2)
		{
			long long int temp=res*a;
			temp=temp - m*(temp/m);
			temp=(temp*a);
			res=temp - m*(temp/m);
		}
		
		long long int c=a*a;
		c=c-m*(c/m);
		a=a*c;
		a=a-m*(a/m);
		i--;
	}
	
	return res;
}

int main()
{
	long long int t,a,m;
	char b[255];
	cin>>t;
	
	while(t--)
	{
		//cin>>a>>b>>m;
		scanf("%lld %s %lld", &a, &b, &m);
		
		printf("%lld\n",find_pow(a,b,m));
	}
	
	return 0;
}
