#include<iostream>

using namespace std;

int find_coins(int perm[][105],int arr[],int n,int sum)
{
	if(n<=0 && sum>=1)
		return 0;
		
	if(sum<0)
		return 0;

	if(sum==0)
		return 1;
		
	return find_coins(perm,arr,n,sum-arr[n-1])+find_coins(perm,arr,n-1,sum);

}

int find_coins_dp(int perm[][105],int arr[],int n,int sum)
{

	if(n<=0 && sum>=1)
		return 0;
		
	if(sum<0)
		return 0;

	if(sum==0)
		return 1;

	if(perm[n][sum]!=-1)
		return perm[n][sum];
				
	perm[n][sum-arr[n-1]]=find_coins(perm,arr,n,sum-arr[n-1]);	
	perm[n-1][sum]=find_coins(perm,arr,n-1,sum);
	
	return perm[n][sum-arr[n-1]]+perm[n-1][sum];
	
}

int main()
{
	int n=5;
	int coins[]={1,5,10,25,50};
	int perm[105];
	
	for(int i=0;i<105;i++)
		perm[i]=0;
		
	perm[0]=1;	
	
	int sum=100;
	
	for(int i=0;i<n;i++)
	{
		for(int j=coins[i];j<=sum;j++)
		{
			if((j-coins[i])>=0)
				perm[j]+=perm[j-coins[i]];
		}
	}
	
	for(int i=0;i<101;i++)
		cout<<i<<":"<<perm[i]<<"\n";
}
