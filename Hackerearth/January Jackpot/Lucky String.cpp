#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int t,len;
	long long int n,cnt;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		
		len=1;
		cnt=2;
		
		while(n>=0)
		{
			n=n-(len*cnt);
			len++;
			cnt*=2;
		}
		
		len--;
		cnt/=2;
		
		n+=(len*cnt);
		
		if(n>len)
			printf("%d\n",len);
		
		else
			printf("%d\n",max(int(n),len-1));
	}
}
