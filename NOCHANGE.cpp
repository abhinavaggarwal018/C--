#include<iostream>
using namespace std;
#define MAX 1000005
bool dp[MAX];
int x,k,v[5];
int main()
{
	dp[0]=true;
	cin>>x;
	cin>>k;
	for(int i=0;i<k;i++)
		{
			cin>>v[i];
		}
	dp[v[0]]==true;
	//no of coins of v1>=v2>=v3>=v4>=v5
	if(k>=1)
	{
		for(int i=0;i<MAX;i++)
		{
				if(dp[i]==true)
					if(i+v[0]<MAX)
						dp[i+v[0]]=true;
					else 
						break;
		}
	}
	if(k>=2)
	{
		for(int i=0;i<MAX;i++)
		{
				if(dp[i]==true)
					if(i+v[0]+v[1]<MAX)
						dp[i+v[0]+v[1]]=true;
					else 
						break;
		}
	}
	if(k>=3)
	{
			for(int i=0;i<MAX;i++)
		{
				if(dp[i]==true)
					if(i+v[0]+v[1]+v[2]<MAX)
						dp[i+v[0]+v[1]+v[2]]=true;
					else 
						break;
		}
	}
	if(k>=4)
	{
		for(int i=0;i<MAX;i++)
		{
				if(dp[i]==true)
					if(i+v[0]+v[1]+v[2]+v[3]<MAX)
						dp[i+v[0]+v[1]+v[2]+v[3]]=true;
					else 
						break;
		}
	}
	if(k==5)
	{
		for(int i=0;i<MAX;i++)
		{
				if(dp[i]==true)
					if((i+v[0]+v[1]+v[2]+v[3]+v[4])<MAX)
						dp[i+v[0]+v[1]+v[2]+v[3]+v[4]]=true;
					else 
						break;
		}
	}
	//for(int i=0;i<20;i++)
/*	if(dp[i]==true)
		cout<<"i("<<i<<"):1  ";
	else
		cout<<"i("<<i<<"):0";*/
	if(dp[x]==true)
	cout<<"YES";
	else
	cout<<"NO";
return 0;
}
