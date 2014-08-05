#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 1000050
#define NUM 100

vector<int> flag(MAX);

int main()
{
	
	int cnt=1;
	
	for(int i=2;i<=100;i++)
	{
		for(int j=i*i*i,k=1;(j*k)<=MAX;k++)
			flag[j*k]=-1;
	}
		
	for(int i=1;i<MAX;i++)
	{
		if(!flag[i])
			flag[i]=cnt++;
	}
	
	int n,t;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		
		if(flag[n]==-1)
		{
			printf("Case %d: Not Cube Free\n",i+1);
			continue;
		}
		else
			printf("Case %d: %d\n",i+1,flag[n]);
	}
}
