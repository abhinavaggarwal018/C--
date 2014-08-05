#include<iostream>
#include<cstdio>

int main()
{

int t,n,cnt;


		scanf("%d",&n);
		cnt=0;
		
		if(n%2==1)
		{
			cnt=((n/2)+1)*((n/2)+1)+((n/2)*(n/2));
		}
		
		else
		{
			cnt=n*n/2;
		}

		printf("%d\n",cnt);
		
		if(n%2==1)
		{
			bool flag=true;
					
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(flag)
					{
						printf("C");
					}
					else
						printf(".");
					
					flag^=1;
				}
				
				flag!=flag;
				
				printf("\n");
			}
		}
		
		else
		{
			bool flag=true;
					
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(flag)
					{
						printf("C");
					}
					else
						printf(".");
					
					flag^=1;
				}
				
				flag^=1;
//				flag!=flag;
				
				printf("\n");
			}
			
		}
}
