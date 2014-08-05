#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 10000009
#define NUM 3165

vector<int> flag(MAX);

int main()
{
	for(int i=2;i<MAX;i+=2)
		flag[i]=2;
		
	for(int i=3;i<MAX;i+=6)
		flag[i]=3;
		
	bool inc=true;
	
	int i;
	
	for(i=5;i<NUM;)
	{
		if(!flag[i])
		{
			flag[i]=i;
			for(int j=i*i,k=(i<<1);j<MAX;j+=k)
			{
				if(!flag[j])
					flag[j]=i;
			}
		}
		
		if(inc)
			i+=2;
		else
			i+=4;
			
		inc=inc^true;
	}
	
	for(;i<MAX;)
	{
		if(!flag[i])
			flag[i]=i;
		
		if(inc)
			i+=2;
		else
			i+=4;
			
		inc=inc^true;
	}
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("1");
		
		while(n!=1)
		{
			printf(" x %d",flag[n]);
			n/=flag[n];
		}
		printf("\n");
	}
}
