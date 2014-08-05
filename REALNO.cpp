#include<stdio.h>

int main()
{
	int t,n,i,found;
	double min_int,max_int,val;
	
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		found=0;
		scanf("%d",&n);

		if(n==0)
		{
			printf("not found\n");
			continue;
		}
		
		scanf("%lf",&val);
		
		if(n==1)
		{
			n--;
			printf("not found\n");
			continue;
		}
		else
		{
			n--;
			min_int=1-val;
			max_int=2-val;
		}	
		
		while(n--)
		{
			scanf("%lf",&val);
			
			if(!found)
			{
				if(val>min_int && val<max_int)
					found=1;
				else
				{
					if(min_int>(1-val));
						min_int=1-val;
						
					if(2-val>max_int)	
						max_int=2-val;
				}
			}
		}
		
//		cout<<min_int<<":"<<max_int;
		
		if(found)
			printf("found\n");
		else
			printf("not found\n");
	}
}
