#include<stdio.h>
long long int t,n,m,collection,min1,min2,a[10005],bag,l,i;
int main()
{
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			//printf("%d",a[i]);
		}
		collection=0;
		min1=0;
		min2=0;
		bag=0;
		for(i=1;i<m;i++)
		{
			{
				int num=a[i]-a[i-1];
				if(a[i]!=a[i-1])
					{
			//			printf("a[i]:%d a[i-1]:%d bag:%d collection:%d\n",a[i],a[i-1],bag,collection);
						collection=collection+num;
						bag=bag-num;
					}
				else
					collection--;
			}
			
			if(collection<min1)
				min1=collection;
			if(bag<min2)
				min2=bag;
			//printf("collection:%d,bag:%d,min1:%d,min2:%d\n",collection,bag,min1,min2);
		}
		min1--;
		min1=-min1;
		min2=-min2;
		if(n-min2>=min1)
			printf("%lld\n",min1);
		else
			printf("-1\n");
	}
return 0;
}
