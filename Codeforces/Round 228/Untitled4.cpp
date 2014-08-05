#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	int n,arr[100],min_diff;
	
	scanf("%d",&n);
	
	bool hash[10004];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<10004;i++)
		hash[i]^=hash[i];
		
	hash[0]=1;
	
	for(int i=0;i<n;i++)
	{
		hash[arr[i]]=true;
	}
	
	int prev=-100000;
	min_diff=10000000;
	for(int i=0;i<10004;i++)
	{
		if(hash[i])
		{
			min_diff=std::min(abs(i-prev),min_diff);
			prev=i;
		}
	}
	
	printf("%d\n",min_diff*n);
}
