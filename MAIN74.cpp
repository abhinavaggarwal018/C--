#include<iostream>
#include<cstdio>

using namespace std;

struct matrix
{
	long long int a;
	long long int b;
	long long int c;
	long long int d;
	
	matrix()
	{
		a=1;
		b=1;
		c=1;
		d=0;
	}

};

/*
	|a	b| * |a	b|
	|c	d|	 |c	d|

*/

struct matrix mult(struct matrix m1, struct matrix m2)
{
	matrix ans;
	ans.a=((m1.a * m2.a)%1000000007 + (m1.b * m2.c)%1000000007)%1000000007;
	ans.b=((m1.a * m2.b)%1000000007 + (m1.b * m2.d)%1000000007)%1000000007;
	ans.c=ans.b;
	ans.d=((m1.c * m2.b)%1000000007 + (m1.d * m2.d)%1000000007)%1000000007;
	
	return ans;
}

int main()
{
	int t;
	
	scanf("%d",&t);
	
	while(t--)
	{
		matrix m1,ans;
		long long int num;
		
		ans.d=1;
		ans.b=0;
		ans.c=0;
		
		scanf("%lld",&num);
		
		if(num==0)
		{
			printf("0\n");
			continue;
		}

		if(num==1)
		{
			printf("2\n");
			continue;
		}

		else
		{
 
			num+=2;		

			while(num)
			{
				if(num&1)
					ans=mult(m1,ans);
					
				m1=mult(m1,m1);
			
				num=num>>1;
			}
			
			printf("%lld\n",ans.a);
		}
	}
}

