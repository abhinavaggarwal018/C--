#include<iostream>
#include<stdio.h>
int k,l,m,temp,num[55],num_max;
#define MAX 1000006
bool dp[MAX][2];

using namespace std;
int main()
{
	cin>>k>>l>>m;
	num_max=-100;
	
	for(int p=0;p<MAX;p++)
	dp[p][0]=false;
	for(int p=0;p < m;p++)
	{
		cin>>num[p];
		if(num[p]>num_max)
		num_max=num[p];
	}
	//cout<<num_max;
	dp[2][0]=true;
	dp[1+k][0]=true;
	dp[1+l][0]=true;
	
	dp[3+k][0]=true;
	dp[3+l][0]=true;
	dp[2+l+k][0]=true;
	
	dp[5+k][0]=true;
	dp[5+l][0]=true;
	dp[4+k+l][0]=true;
	
	dp[8+k+k][0]=true;
	dp[8+k+l][0]=true;
	dp[7+l+k+k][0]=true;
	dp[8+l+l][0]=true;
	dp[7+l+l+k][0]=true;
	dp[6+l+l+k+k][0]=true;
	
	dp[1][0]=false;
	dp[k][0]=false;
	dp[l][0]=false;
	for(int i=1;i<=num_max;i++)
	{
		/*for(int k1=0;k1<20;k1++)
		cout<<dp[k1][0];*/
		if(dp[i][0]==true)
		{
			//cout<<i<<" ";
			dp[i][1]=true;
			for(int j=1;j<=i;j++)
			{
				if(dp[j][0]==true)
				{
					dp[i+j][1]=true;
				//	cout<<i+j<<" ";
				}
			}
			for(int i1=0;i1<=num_max;i1++)
			{
				dp[i1][0]=dp[i1][1];
			}
		}
		
		//getchar();
	}
	for(int i=0;i<m;i++)
	{
		if(dp[num[i]][1]==true)
			cout<<"B";
		else 
			cout<<"A";
	}
	return 0;
}
