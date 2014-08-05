#include<iostream>

using namespace std;

#define MAX 100010
#define NUM 320


bitset<NUM> arr;
vector<int> primes;

int main()
{
	arr.reset();
	primes.push_back(2);
	primes.push_back(3);

	bool flag=true;

	for(int i=5;i<NUM;)
	{
		if(!arr.test(i))
		{
			primes.push_back(i);
		
			for(int j=i*i,k=i<<1;j<MAX;j+=k)
				arr[j]=true;
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
			primes.push_back(i);
		
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&a,&b);
		
		Do LAter
	}
	
}
