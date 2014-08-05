#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int arr[100000]={0};

int main()
{
	long long int t,x,y;
	scanf("%lld",&t);

	for(int i=0;i<t;i++)
	{
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",(y-x+1)*(y-x)/2);

	}
}
