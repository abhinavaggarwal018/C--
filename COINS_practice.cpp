#include<cstdio>

long long int max(long long int a, long long int b)
{
	if(a>b)
		return a;
	return b;
}
#define MAX 33000005

long long int arr[MAX];

long long int find_max(long long int n)
{
	if(n<12)
		return n;
		
	if(n<MAX && arr[n])
		return arr[n];
		
	if(n<MAX)
	{
		arr[n]=max(n,find_max(n/2)+find_max(n/3)+find_max(n/4));
		return arr[n];
	}
	
	return max(n,find_max(n/2)+find_max(n/3)+find_max(n/4));
	
}

int main()
{
	int t;
	long long int n;
	
	while(scanf("%lld",&n) != EOF)
		printf("%lld\n",find_max(n));
	return 0;
}
