#include<iostream>
#include<cstdio>

using namespace std;

int lis(int arr[], int n)
{
	if(n==0)
		return;
	
	
	
	int ans[n],ans2[n];
	
	for(int i=0;i<n;i++)
	{
		ans[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>=arr[j])
			{
				ans[i]=max(ans[i],ans[j]+1);
				ans2[]
			}	
			
			
		}
	}
	
	return ans[n-1];
}

int main()
{
  int arr[] =  { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", lis( arr, n ));

  return 0;
  
  	
}
