#include<stdio.h>
using namespace std;
long long int n,t,val[20000005];
long long int max(long long int a,long long int b)
{
	if(a>b)
	return a;
	return b;
}
long long int find(long long int n)
{

	if(n<12)
	return n;
	if(n < 20000000 && val[n]!=0)
	return val[n];
	else if (n<20000000)
	{
		val[n]=max(n,find(n/2)+find(n/3)+find(n/4));
		return val[n];
	}
	return max(n,find(n/2)+find(n/3)+find(n/4));
//	cout<<"find"<<n;
	
}

int main()
{
	for(int i=0;i<20000005;i++)
	val[i]=0;
	val[1]=1;
	val[2]=2;

	while(scanf("%lli",&n)>0)
	{
		printf("%lli\n",find(n));
	}
return 0;
}
