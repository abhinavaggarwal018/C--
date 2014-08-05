#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	
	int c,n,m,t;
	
	scanf("%d",&c);
	
	while(c--)
	{
		scanf("%d %d %d",&n,&m,&t);
		int ans=0;
		ans+=t;
				
		while(n>m)
		{
			ans+=t;
			
			if(m>n)
				break;
			
			n=n-m;
			ans+=t;
			
		}
		
		ans+=t;
		
		printf("%d\n",ans);
	}
}
