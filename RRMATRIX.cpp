#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		if(n==1 && m==1)
			printf("1\n");
		
		else if(n!=1 && m!=1)
			printf("2\n");
		
		else if(n==1)
			printf("%d\n",m);
		
		else
			printf("%d\n",n);
	}
}
