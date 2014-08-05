#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t,n,val,cnt,prev;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		cnt=0;
		prev=1000000005;
		
		while(n--)
		{
			scanf("%d",&val);
			
			if(val<prev)
			{
				cnt++;
				prev=val;
			}
		}
		
		printf("%d\n",cnt);
	}
}
