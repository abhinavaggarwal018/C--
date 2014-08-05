#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int t,n,k,m,cnt,val,v1,v2,ans,maxm=-1000;
	int hash1[100005],hash2[100005];
//	scanf("%d",&t);
//	while(t--)
	{
		cnt=0;
		scanf("%d", &n);
		
		if(n%2==0)
			val=n/2;
		else
			val=n/2+1;	
		
		for(int i=0;i<n;i++)
		{
			hash1[i]=0;
			hash2[i]=0;
		}

		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&v1, &v2);
			hash1[v1]++;
			hash2[v2]++;
			maxm=max(max(v1,v2),maxm);
		}
		
		ans=1000000;
		
		for(int i=0;i<=maxm;i++)
		{
			if((hash1[i]+hash2[i])>=val)
			{
				if(hash1[i]>=val)
				{
					printf("0\n");
					return 0;
				}
				else
				{
					ans=min(ans,val-hash1[i]);
				}
			}
		}
		
		if(ans==1000000)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
			
		return 0;

	}
}
