#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int t;
	long long int n,k,m,cnt;
	
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%lld %lld %lld", &n, &k, &m);
		cnt=((double)log(m/n)/(double)log(k));
		if((n*pow(k,cnt+1))<=m)
			printf("%lld\n",cnt+1);
		else
			printf("%lld\n",cnt);
	}
}
