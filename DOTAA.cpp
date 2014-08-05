#include<stdio.h>
int main()
{
	int i1,i,n,m,d,t,energy,cnt=0;
	scanf("%d",&t);
	for(i1=0;i1<t;i1++)
	{
		cnt=0;
		scanf("%d %d %d",&n,&m,&d);
		for(i=0;i<n;i++)
		{
			scanf("%d",&energy);
			energy=energy-d;
			while(energy>0)
			{
//				printf("%d\n",energy);
				cnt++;
				energy=energy-d;
			}
		}
		if(cnt>=m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
