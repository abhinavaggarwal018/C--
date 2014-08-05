//#include<iostream>
#include<stdio.h>
//using namespace std;
#define MAX 100050

//long long int sum;
long long int max1(long long int a,long long int b)
{
	if(a>=b)
	return a;
	return b;
}
int main()
{
	int i,l;
	int t,n;
	long long int dp[MAX],val[MAX];
//	cin>>t;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		//sum=0;
		for(i=0;i<MAX;i++)
		{
			dp[i]=0;
			val[i]=0;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&val[i]);
		}
/*		for(int i=0;i<n-12;i=i+12)
		{
			sum+=max((val[i]+val[i+1]+val[i+2]+val[i+6]+val[i+7]+val[i+8]),max((val[i]+val[i+1]+val[i+4]+val[i+5]+val[i+8]+val[i+9]),(val[i]+val[i+3]+val[i+5]+val[i+7]+val[i+9]+val[i+11])));
		}*/
		for(i=n-1;i>=0;i--)
		{
			dp[i]=max1((val[i]+dp[i+2]),max1((val[i]+val[i+1]+dp[i+4]),(val[i]+val[i+1]+val[i+2]+dp[i+6])));
		}
		//cout<<dp[0]<<"\n";
		printf("%lld\n",dp[0]);
	}
	return 0;
}
