#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int gcd(int n1,int n2)
{
	if(n2==0)
		return n1;
	return gcd(n2,n1%n2);
}

int n1,n2,t;

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n1,&n2);
		
		int val=gcd(n1,n2);
		printf("%d %d\n",val,(n1/val)*n2);
	}
}
