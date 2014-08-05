#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr[100005];
int t, n, a1, m;

int main()
{
	
	long long int k;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d", &n);
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);

		std::sort(arr,arr+n);
		
		scanf("%d", &m);
		
		for(int i=0;i<m;i++)
		{
			scanf("%lld",&k);
			long long int sum=0;
			
			for(a1=0;a1<n;a1++)
			{
				sum+=arr[a1];
				if(sum>=k)
					break;
			}
			
			printf("%lld ",a1);
		}
		
		printf("\n");
	}
}

//Find maximum number of elements in array whose sum is less than k
//n<=10^5
//t=10
//k<10^18
//No. are all int max
//No. are negetive
//No. are zero
//All enteries of array will fit in 32 bit integer.
//Opposite sorted array.

/*
Sample Test case
1
5
1 2 3 4 5
2
7 11

Sample output:
3 4
*/

