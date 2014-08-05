#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void process(int n, long long int k, char c)
{
	if(k==1)
	{
		if(c=='M')
			printf("Male\n");
		else
			printf("Female\n");
			
		return;
	}


	int val=log2(k);
	
	if(val>n-1)
	{
		if(c=='M')
			return process(n-1,k-pow(2,n-1),'F');
			
		else if(c=='F')
			return process(n-1,k-pow(2,n-1),'M');
	}
		
	else
		return process(n-1,k,c);	
}
/*	int val=pow(2,n-1);
	
	if(k>val)
	{
		if(c=='M')
			return process(n-1,k-val,'F');
		else if(c=='F')
			return process(n-1,k-val,'M');
	}
		
	else
		return process(n-1,k,c);
}
*/

bool process(int n, long long int k)
{
	if(k==1 || n==1)
		return 1;
		
	if(k&1) 
		return process(n-1,(k+1)/2);
	
	return !process(n-1,(k+1)/2);
}

int main()
{
	int t,n;
	long long int k;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld",&n,&k);
		if(process(n,k))
			printf("Male\n");
		else
			printf("Female\n");
	}
}
