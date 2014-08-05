#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,sum,i;
	scanf("%d",&t);
	while(t--)
	{
		i=1;
		sum=0;
		scanf("%d",&n);
		while(n)
		{
			sum=sum+(n&1)*pow(5,i);
			i++;
			n=n>>1;
		}
		printf("%d\n",sum);
	}
}
