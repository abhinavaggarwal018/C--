#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a,b,ans=0,cnt=0;
	
	cin>>a;
	cin>>b;
	
	while(b)
	{
		if(b&1)
		{
			ans=ans+(a<<cnt);
			printf("\n%d\n",ans);
		}
		
		b=b>>1;
		cnt++;
		printf("\nANS:%d,a: %d,b: %d\n",ans,a,b);
		
	}
	
	
}
