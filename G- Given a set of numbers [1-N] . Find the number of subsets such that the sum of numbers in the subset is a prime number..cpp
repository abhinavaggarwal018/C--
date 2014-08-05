//Given a set of numbers [1-N] . Find the number of subsets such that the sum of numbers in the subset is a prime number. 
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[100],hash[100000]={0},sums[10000];

int main()
{
	int sum=0,n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	for(int i=4;i<sum;i+=2)
		hash[i]=true;

	for(int i=9;i<sum;i+=6)
		hash[i]=true;
		
	bool flag=true;
		
	for(int i=5;i<=sqrt(sum)+1;)
	{
		for(int j=i*i;j<=sum;j++)
			hash[j]=true;
			
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag=flag^1;
	}
	
	for(int j=0;j<n;j++)
	{
		sums[0]=1;
		for(int i=0;i+arr[j]<=sum;i++)
		{
			if(sums[i])
				sums[i+arr[j]]=true;
		}
	}
	
	for(int i=0;i<sum;i++)
		cout<<i<<"\t"<<sums[i]<<"\t"<<hash[i]<<"\n";

}
