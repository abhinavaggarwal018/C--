#include<bitset>
#include<stdio.h>
#include<vector>

#define MAX 100000000

//std::bitset<MAX> arr;
int cnt;

int arr[MAX>>6];

#define set(x)  (arr[x>>6]|=(1<<((x>>1)&31)))
#define test(x)	(arr[x>>6]&(1<<((x>>1)&31)))

int main()
{
	int NUM=10000,n,cnt,i,num,j,val,k;
		
	printf("2\n");
	cnt=1;
	
	bool flag=true;
	
	for(i=5;i<NUM;)
	{
		if(!test(i))
		{	
			++cnt;
			if(cnt==100)
			{
				printf("%d\n",i);
				cnt=0;
			}
				
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				set(j);
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
		if(!test(i))
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

