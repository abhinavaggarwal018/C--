#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 1000050
#define NUM 1005

vector<int> flag(MAX);

int main()
{
	
	for(int j=2;j<MAX;j+=2)
		flag[j]=2;
		
	for(int j=3;j<MAX;j+=6)
		flag[j]=3;
		
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
			
		inc^=true;
	}
	
	for(;i<MAX;)
	{
		if(!flag[i])
		{
			if(!flag[i])
				flag[i]=i;
		}							
		
		if(inc)
			i+=2;
		else
			i+=4;
			
		inc^=true;
	}

	
	int t,n;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		int max_cnt=0;
		int cnt=0;
		
		max_cnt=0;
		cnt=0;
		
		if(flag[n]==n)
			printf("1\n");
			
		else
		{
			while(n!=1)
			{
				int val=flag[n];
				
				while(flag[n]==val)
				{
					cnt++;
					n=n/flag[n];
				}
				
//				cout<<val<<" "<<cnt<<"\n";
				
				if(max_cnt<cnt)
					max_cnt=cnt;
					
				cnt=0;
			}
		
			printf("%d\n",max_cnt);
		}
		
	}
}
