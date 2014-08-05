#include<iostream>
#include<cstdio>

using namespace std;
// recursive
int knapSack(int W, int wt[], int val[], int n)
{
	if(W<=0 || n<=0)
		return 0;
		
	if(W-wt[n-1]<0)
		return knapSack(W,wt,val,n-1);
		
	return max(knapSack(W-wt[n-1],wt,val,n-1)+val[n-1],knapSack(W,wt,val,n-1));
}

int knapSackDP(int W, int wt[], int val[], int n)
{
	int arr[W+2];
	
	for(int i=0;i<W+2;i++)
	{	
		arr[i]=0;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=W-wt[i];j>=0;j--)
		{
			if(arr[j]|| !j)
				arr[j+wt[i]]=max(arr[j+wt[i]],arr[j]+val[i]);
		}
	}

	int maxm=0;
	for(int i=0;i<=W;i++)
	{
//		cout<<i<<":"<<arr[i]<<"\n";
		maxm=max(maxm,arr[i]);
	}
	return maxm;
}

int knapSack2D_DP(int W, int wt[], int val[], int n)
{
	int value[n][W+1];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			value[i][j]=0;
		}
	}

	for(int i=0;i<n;i++)
	{
		if(wt[i]>=W)
		{
			for(int j=0;j<=W;j++)
				value[i][j]=value[i-1][j];
	
			continue;
		}
			
		value[i][wt[i]]=val[i];
		
		if(i==0)
			continue;
		
		for(int j=0;j<=W;j++)
		{
			if(value[i-1][j]&&(j+wt[i])<=W)
				value[i][j+wt[i]]=max(value[i-1][j],value[i-1][j]+val[i]);
			else
				value[i][j]=max(value[i][j],value[i-1][j]);
		}
	}

	int maxm=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			cout<<value[i][j]<<" ";
		}
		cout<<"\n";
	}

	for(int i=0;i<=W;i++)
	{
//		cout<<i<<":"<<arr[i]<<"\n";
		maxm=max(maxm,value[n-1][i]);
	}
	
	return maxm;
}

int main()
{
    int val[] = {60, 100, 1200};
    int wt[] = {10, 20, 300};
    int  W = 50;
/*	int wt[] = {2,3,4,5};
	int val[] = {3,4,5,6};
	int W = 5;*/
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack2D_DP(W, wt, val, n));
    return 0;
}
