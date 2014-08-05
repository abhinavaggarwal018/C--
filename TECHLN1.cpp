#include<stdio.h>
int main()
{

int t,n,val,l,i1;
bool pos[100005];
long long int group1;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		group1=0;
		for(i1=0;i1<100005;i1++)
			pos[i1]=false;
		scanf("%d",&n);
		for(i1=0;i1<n;i1++)
		{

			scanf("%d",&val);
			if(pos[val]==false)
			{
				pos[val]=true;
				if(pos[val-1]==true&&pos[val+1]==true)
					group1--;
				if(pos[val-1]==false&&pos[val+1]==false)
					group1++;
			}
			else if(pos[val]==true)
			{
				pos[val]=false;
				if(pos[val-1]==true&&pos[val+1]==true)
					group1++;
				if(pos[val-1]==false&&pos[val+1]==false)
					group1--;
			}
			//cout<<pos[10]<<pos[11];
			printf("%lld\n",group1);
		}
			printf("\n");
	}
	printf("ED.LN destroyed");
}


