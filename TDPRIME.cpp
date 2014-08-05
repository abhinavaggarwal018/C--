#include<bitset>
#include<stdio.h>
#include<vector>

#define MAX 100000000

std::bitset<MAX> arr;
int cnt;

int main()
{
	int NUM=10000,n,cnt,i,num,j,val,k;
		
	printf("2\n");
	cnt=1;
	
	bool flag=true;
	
	for(i=5;i<NUM;)
	{
		if(!arr.test(i))
		{	
			++cnt;
			if(cnt==100)
			{
				printf("%d\n",i);
				cnt=0;
			}
				
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				arr.set(j,true);
		}
		
		if(flag)
			i+=2;
		
		else
			i+=4;

		flag^=true;
	}

//	assert(0);
	
	for(;i<MAX;)
	{
		if(!arr.test(i))
		{
			++cnt;
		
			if(cnt==100)
			{
				printf("%d\n",i);
				cnt=0;
			}
		}
		
		if(flag)
			i+=2;
		
		else
			i+=4;
		
		flag^=true;
	}

}

