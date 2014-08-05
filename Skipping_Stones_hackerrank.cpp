#include<stdio.h>
int n,L,D,d[1005],i;
int flag=0,dist_travelled=0;
float p[1005],prob_max=0;
void find_max(int dist_travelled,int index,float prob)
{
//	cout<<"\nDistance"<<dist_travelled<<"Next index"<<index<<"probaility"<<prob;
	if(index==n+1)
	{
		if(prob_max<prob)
			{
				prob_max=prob;
				flag=1;
			}
	}
	while((d[index]-dist_travelled)<=L&&index<n+1)
	{
		index++;
		int dist1=d[index-1];
		if(prob*p[index-1]<prob_max && flag==1)
			continue;
		find_max(dist1,index,prob*p[index-1]);
	}	
}
int main()
{
	scanf("%d %d %d",&n, &L, &D);
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
		p[n]=1;
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
		d[n]=D-d[n-1];
	if(d[n]>L)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	find_max(0,0,1);
	if(flag==0)
		printf("IMPOSSIBLE");
	else
		printf("%.6f",prob_max);
		return 0;
}
