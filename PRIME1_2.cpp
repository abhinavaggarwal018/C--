#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

#define MAX 1000000005
#define SIZE 100005
#define NUM 32000

vector<bool> arr(NUM);
vector<bool> temp(SIZE);

int main()
{
	
//	for(int i=4;i<=NUM;i+=2)
//		arr[i]=true;
		
//	for(int i=9;i<=NUM;i+=6)
//		arr[i]=true;
		
	bool flag=true;
		
	for(int i=5;i<=NUM;)
	{
		if(!arr[i])
			for(int j=i*i;j<=NUM;j+=(i<<1))
				arr[j]=true;
				
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}
	
	
	int t,m,n,var;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d", &m, &n);
		
		if(m==1)
			m=2;
			
		for(int i=0;i<n-m+2;i++)
			temp[i]=0;
			
		if((m&1)==1)
			var=m+1;
		else 
			var=m;
			
		for(int i=var;i<=n;i+=2)
			temp[i-m]=1;	
		
		if((m%3)==0) 
			var = m; 
		else 
			var=(3*(m/3))+3;
		
		if((var&1)==0)
			var+=3;	
				
		for(int i=var;i<=n;i+=6)
			temp[i-m]=1;
		
		if(m%5==0)
			var=m;
		else
			var=(5*(m/5))+5;
					
		bool flag=true;
		
		for(int i=5;i<=sqrt(n);i++)
		{
			if(!arr[i])
			{
				int num1=i*i;
				if(m<=num1)
					var=num1;
				else
				{
					int num2=(2*i)*((m-num1)/(2*i));
					
					if((m-num1)==(num2))
						var=m;
					else
						var=num2+num1+2*i;
				}
				for(int j=var;j<=n;j+=(i<<1))
					temp[j-m]=true;
			}
			
			
			if(flag)
				i+=2;
			else
				i+=4;
				
			flag^=true;	
		}
		
		if(m<=2&& n>=2)
				printf("2\n");

		if(m<=3&& n>=3)
				printf("3\n");

		for(int i=0;i<=n-m;i++)
		{
			if(!temp[i])
				printf("%d\n",i+m);
		}
		printf("\n");
	}
}
