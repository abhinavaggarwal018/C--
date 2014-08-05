#include<iostream>
#include<stdio.h>
using namespace std;
bool value[20005];
int t,n,m,arr[21];
int main()
{
	scanf("%d",&t);
	while(t--)	
	{
		for(int i=0;i<20005;i++)
		{
			value[i]=false;
		}
		value[0]=true;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=19001;j>=0;j--)
			{
				if(value[j]==true)
					value[j+arr[i]]=true;
			}
		}
		if(value[m]==true)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
