#include<bitset>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cassert>

using namespace std;

#define MAX 100000005
#define SIZE 20000005

bitset<MAX> arr;
long long int val[SIZE];
int cnt;

void mark_all(int i)
{
	for(int j=i*i;j<MAX;j=j+i+i)
		arr.set(j,true);
}

int main()
{
	int NUM=sqrt(MAX),n;
	arr.reset();
	arr[0]=1;
	arr[1]=1;
	
	for(int i=4;i<MAX;i+=2)
		arr.set(i,true);
		
	for(int i=9;i<MAX;i+=6)
		arr.set(i,true);		

	
	for(int i=0;i<SIZE;i++)
			val[i]=0;	
		
	val[0]=2;
	
	bool flag=true;
	
	int i;
	
	for(i=5;i<NUM;)
	{
		int k=i/5;
		
		if(!val[k])
			val[k]=val[k-1];
			
		if(!arr.test(i))
		{
			val[k]++;		
			mark_all(i);
		}
		
		if(flag)
		{
			flag=0;
			i+=2;
		}
		
		else
		{
			flag=1;
			i+=4;
		}
	}
	
	for(;i<MAX;)
	{
		int k=i/5;
		if(!val[k])
			val[k]=val[k-1];
			
		if(!arr.test(i))
			val[k]++;		
		
		if(flag)
		{
			flag=0;
			i+=2;
		}
		
		else
		{
			flag=1;
			i+=4;
		}
	}
	
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
			
		float calc=0;
		int num=n/5-1;
		
		if(num>=0)
			calc=val[num];
		
		for(int i=5*(num+1);i<=n;i++)
				if(!arr.test(i))
					calc++;
		
		cout<<calc<<"\n";
		
		printf("%0.1f\n",abs((float)calc - (float)(n/log(n)))/(float)calc *100);
	}
}

