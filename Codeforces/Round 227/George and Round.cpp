#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,a[3005],b[3005];
	
	scanf("%d %d",&n ,&m);
	
	for(int i=0;i<n;i++) //min
		scanf("%d",&a[i]);
	
	for(int i=0;i<m;i++)//prep
		scanf("%d",&b[i]);
	
	int j=m-1;	
	int cnt=0;

	if(m==0)
	{
		printf("%d\n",n);
		return 0;
	}

	if(n==0)
	{
		printf("0\n",n);
		return 0;
	}
		
	for(int i=n-1;i>=0;i--)
	{
//		cout<<1;
		
		if(b[j]>=a[i])
			j--;
		else
		{
			for(;i>=0;i--)
			{
				if(b[j]>=a[i])
					break;
				else
					cnt++;
					
//				cout<<cnt;
			}

		}

		if(i<=0)
		{
			printf("%d\n",cnt);
			return 0;
		}

		if(j<=0)
		{	
			printf("%d\n",i+cnt);
			return 0;
		}

	}
}
