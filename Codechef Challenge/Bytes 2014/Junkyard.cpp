#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>

using namespace std;
long long int ans=-1,l;

bool f(long long int n)
{
	if(((n+5)*(n-1))<=l)
	{
		ans=max(ans,n);
		return true;
	}
	
	return false;
}

void bSearch(long long int start, long long int end)
{
	if(start>end)
		return;
	
	long long int mid=start+(end-start)/2;
	
	if(f(mid))
		bSearch(mid+1,end);
	else
		bSearch(start,mid-1);
}

int main()
{
	int t;
	
	scanf("%d",&t);
	
	if(t>1000000)
		assert(0);
	
	while(t--)
	{
		scanf("%lld",&l);
		
		if(l>(long long)pow(10,18)|| l<1)
			assert(0);
			
		if(l<7)
			printf("-1\n");
		
		bSearch(0,l);
		
		printf("%lld\n",ans);
	}
}
