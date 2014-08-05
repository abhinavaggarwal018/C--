#include<stdio.h>
#include<string.h>
#include<iostream>
char str[5005];
long long int dp[5005],m;
using namespace std;
int main()
{
	while(1)
	{
		scanf("%s",&str);
		if(str[0]=='0')
		break;
		m=strlen(str);

		dp[0]=1;
		if((str[0]=='1' || (str[0]=='2'&&str[1]<='6' ))&&str[1]!='0'&&str[2]!='0')
		dp[1]=2;
		else
		{
			dp[0]=1;
			dp[1]=1;
		}
		for(int i=2;i<m;i++)
		{
			//cout<<"123";
			if((str[i-1]=='1'||(str[i-1]=='2')&&str[i]<='6')&&str[i]!='0'&&str[i+1]!='0')
			dp[i]=dp[i-1]+dp[i-2];// if number is 1111 then ans=111(last 1=a) ka ans + 11(last 11=j) ka ans
			else if((str[i-1]=='1'||str[i-1]=='2')&&str[i]!='0')
			dp[i]=dp[i-1];
			else
			dp[i]=dp[i-1];
		}
		/*for(int i=0;i<m;i++)
		{
			cout<<dp[i]<<" ";
		}*/
		printf("%lld\n",dp[m-1]);
	}
}
