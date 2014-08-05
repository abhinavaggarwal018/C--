#include<stdio.h>
int valid[1000],ans;
int value[10],t,n,i,trash,j;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		if(n>=10)
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			scanf("%d",&trash);
			continue;
		}
		for(i=0;i<1000;i++)
		{
			valid[i]=0;
		}
		for(i=0;i<n;i++)
			scanf("%d",&value[i]);
		valid[0]=1;
		for(j=0;j<n;j++)
		{
			for(i=1000;i>=0;i--)
			{
				if(valid[i]==1)
					{
						if(valid[i+value[j]]==1)
						{
							ans=1;
							break;
						}
						valid[i+value[j]]=1;
					}
			}
			if(ans==1)
					break;
		}
		if(ans==1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;	
}

