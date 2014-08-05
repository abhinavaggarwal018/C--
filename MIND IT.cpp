#include<iostream>
#include<string.h>
using namespace std;
int t,n;
char str[50];
long long int dp[40];
int main()
{
	//dp[]=1;
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=40;i++)
	{
		dp[i]=2*dp[i-1]+dp[i-2];
	}
	cin>>t;
	for(int l=0;l<t;l++)
	{
		cin>>str;
		n=strlen(str);
		cout<<dp[n]<<"\n";
	}
}

 
