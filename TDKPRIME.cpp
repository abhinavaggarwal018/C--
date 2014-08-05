#include<bitset>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<assert.h>
#define MAX 87000000
#define SIZE 5000005

std::bitset<MAX> arr;
std::vector<int> val(SIZE,0);
int cnt;

int main()
{
	int NUM=9327,n,cnt,i,num,j;
	
	arr.set(0,true);
	arr.set(1,true);
	
	for(int i=4;i<MAX;i+=2)
		arr.set(i,true);
		
	for(int i=9;i<MAX;i+=6)
		arr.set(i,true);
		
	val[0]=2;
	val[1]=3;
	cnt=2;
	
	bool flag=true;
	
	for(i=5;i<NUM;)
	{
		if(!arr.test(i))
		{
			val[cnt]=i;		
			cnt++;
			
			for(j=i*i;j<MAX;j=j+(i<<1))
				arr.set(j,true);
		}
		
		if(flag)
			i+=2;
		
		else
			i+=4;

		flag^=true;
	}
	
	for(;i<MAX;)
	{
		if(!arr.test(i))
		{
			val[cnt]=i;		
			cnt++;
		}
		
		if(cnt>=SIZE)
			break;
		
		if(flag)
			i+=2;
		
		else
			i+=4;
		
		flag^=true;
	}

	scanf("%d",&n);

	while(n--)
	{
		scanf("%d",&num);
		printf("%d\n",val[num-1]);
	}
}

