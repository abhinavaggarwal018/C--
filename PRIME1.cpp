#include<iostream>
#include<cmath>
#include<cstdio>
#include<bitset>

using namespace std;

#define MAX 1000000005
#define NUM 32000

bitset<NUM> arr;
int n,m,cnt;

int main()
{
	int t;

	arr.reset();
	
	for(int i=4;i<NUM;i+=2)
		arr.set(i,true);
		
	for(int i=9;i<NUM;i+=6)
		arr.set(i,true);
	
	bool flag=true;
	
	for(int i=5;i<NUM;)
	{
		if(!arr.test(i))
			for(int j=i*i,k=(i<<1);j<NUM;j+=k)
				arr.set(j,true);
			
		if(flag)
			i+=2;
		else
			i+=4;
		
		flag^=true;
	}
	
	bitset<100005> ans;
	
	cin>>t;
	
	while(t--)
	{	
	
		ans.reset();
		cin>>m>>n;

		if(m<=1 && n<=1)
			continue;

		if(m<=1)	
			m=2;
			
		int val=sqrt(n);
		int m1=m;
		
		for(int i=2;i<val;i++)
		{
			if(!arr.test(i))
			{
				for(int j=m+1;)
			}
		}
		
		/*if(m&1)
			m1=m+1;
			
		for(int i=m1;i<=n;i+=2)
			ans.set(i-m,true);
		
		m1=((m%3==0)?m:((m%3==1)?m+2:m+1));
		
		if(!(m&1))
			m1=m+3;
		
		for(int i=m1;i<=n;i+=6)
			ans.set(i-m,true);
		
		for(int i=3;i<val;i+=2)
		{
			if(!arr.test(i))
			{
				for(int j=m;j<=n;j++)
					ans.set(j-m,true);
			}
		}
		
		if(m==2)
			cout<<"2\n";
		*/	
		for(int i=0;i<=n-m;i++)
			if(!ans.test(i))
				cout<<i+m<<"\n";

		cout<<"\n";
	}
}
