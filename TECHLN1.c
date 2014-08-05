#include<stdio.h>
int main()
{
int t,n,val,l,i1;
int pos[100005];
long long int group1;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		group1=0;
		for(i1=0;i1<100004;i1++)
			pos[i1]=0;
		scanf("%d",&n);
		for(i1=0;i1<n;i1++)
		{

			scanf("%d",&val);
			if(pos[val]==0)
			{
				pos[val]=1;
				if(val>1&&val<100000)
				{
				
					if(pos[val-1]==1&&pos[val+1]==1)
						group1--;
					if(pos[val-1]==0&&pos[val+1]==0)
						group1++;
				}
				else if(val==1)
				{
					if(pos[2]==1)
						group1--;
					else if(pos[2]==0)
						group1++;
				}
				else if(val==100000)
				{
					if(pos[9999]==1)
						group1--;
					else if(pos[9999]==0)
						group1++;
				}
			}
			else if(pos[val]==1)
			{
				pos[val]=0;

				if(val>1&&val<100000)
				{
					if(pos[val-1]==1&&pos[val+1]==1)
						group1++;
					if(pos[val-1]==0&&pos[val+1]==0)
						group1--;
				}
				else if(val==1)
				{
					if(pos[2]==1)
						group1++;
					else if(pos[2]==0)
						group1--;
				}
				else if(val==100000)
				{
					if(pos[9999]==1)
						group1++;
					else if(pos[9999]==0)
						group1--;
				}
			}
		//	printf("%d %d\n",pos[10],pos[11]);
			//cout<<pos[10]<<pos[11];
			printf("%lld\n",group1);
		}
			printf("\n");
	}
	printf("ED.LN destroyed\n");
	return 0;
}



