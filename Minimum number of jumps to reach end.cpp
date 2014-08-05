/*

http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

*/

#include<iostream>

using namespace std;

int min_jumps(int arr[],int start, int end,int jumps)
{
	//RECURSIVE SOLUTION

/*	if(start+arr[start]>=end)
		return jumps+1;
		
	int min_jump=10000;
	for(int i=start+1;i<=start+arr[start];i++)
		min_jump=min(min_jump,min_jumps(arr,i,end,jumps+1));
	return min_jump;*/
	
	//GREEDY SOLUTION

/*	int step=-1,ind=-1,i;
	while(i<end)
	{
		cout<<start<<" ";
		for(i=start+1;i<=start+arr[start]&&i<end;i++)
			if(step<(i+arr[i]))
				{
					step=arr[i]+i;
					ind=i;
				}
		if(ind==-1)
		{
			cout<<"Impossible\n";
			return -1;
		}
		else
		{
			jumps++;
			start=ind;
		}
	}
	cout<<i+1<<" ";
	return jumps;*/
	
	//Best way to reach each node from start, then return arr[n-1]
	
	int best[1000];
		
	for(int i=0;i<end;i++)
	best[i]=10000;

	best[0]=0;
		
	for(int i=1;i<end;i++)
	{
		for(int j=0;j<i;j++)
		{	
			for(int k=j;k<=arr[j];k++)
				if((j+arr[k])==i)
					best[i]=min(best[i],best[j]+1);	
		}
	}
	for(int i=0;i<end;i++)
		cout<<best[i]<<" ";
	
	return best[end-1];
}

int main()
{
	int n,arr[1000];
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		cout<<min_jumps(arr,0,n,0);
	}
}
