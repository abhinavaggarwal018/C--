#include<iostream>
#include<string.h>
using namespace std;
char str1[4005],str2[4005];
long long int dp[4005][4005],a; 
int len1,len2,k;
int main()
{
	cin>>str1;
	cin>>str2;
	cin>>k;
	len1=strlen(str1);
	len2=strlen(str2);
	dp[0][0]=0;
	for(int i=1;i<=len1;i++)
	{
		dp[i][0]=dp[i-1][0]+str1[i-1];
	}	
	for(int i=1;i<=len2;i++)
	{
		dp[0][i]=dp[0][i-1]+str2[i-1];
	}
/*	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{ 
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
}
