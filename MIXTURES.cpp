#include<iostream>
#include<stdio.h>
using namespace std;
int n,orig_color[105],color[105],a,b;
long long int smoke,dp[105];
long long int find_back(int a)
{
	
}
int main()
{
	while(scanf("%d",&n)>0)
	{
		smoke=0;
		for(int i=0;i<n;i++)
			{
				cin>>orig_color[i];
				color[i]=orig_color[i];
			}
		if(n==1)
			{
				cout<<"0\n";
				continue;
			}
		if(n==2)
			{
				cout<<orig_color[0]*orig_color[1]<<"\n";
				continue;
			}
		dp[0]=0;
		dp[1]=orig_color[0]*orig_color[1];
		color[0]=(orig_color[0]+orig_color[1])%100;
		color[1]=(orig_color[0]+orig_color[1])%100;
		
		for(int i=2;i<n;i++)
		{	
			a=color[i-1]*color[i]+dp[i-1];
			b=orig_color[i-1]*orig_color[i]+find_back(i);
			
			if(a<=b)
			{
				dp[i]=a;
				color[i-1]=color[i-1]*orig_color[i];
				color[i]=color[i-1];
			}
			
			else
			{
				color[i-1]=orig_color[i-1]*orig_color[i];
				color[i]=color[i-1];
				dp[i]=b;
			}
			
		}
		cout<<dp[n-1]<<"\n";
	}
}
