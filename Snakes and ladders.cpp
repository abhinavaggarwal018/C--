#include<cstdio>
int main()
{
	int t,x,y,m,n,r,arr[105],val;
	
	scanf("%d",&t);
	
	while(t--)
	{

		scanf("%d %d %d",&n,&m,&r);
		
		for(int i=0;i<105;i++)
				arr[i]=-1;
		
		while(m--)
		{
			scanf("%d %d",&x, &y);
			
			arr[x]=y;
		}
		
		int won=0;
		bool pos=false;
		
		won=0;
		pos=false;

		x=1;
		y=1;

		while(r>0)
		{
			r--;
			scanf("%d",&val);
			
			if(!won)
			{
				int sum=val;
				while(val==6 && r>0)
				{
					scanf("%d",&val);
					r--;
					sum+=val;
				}
				
				if(!pos)
				{
					if((x+sum)==n)
					{
						won=1;
						x=n;
					}
					if((x+sum)<n)
					{
						x=x+sum;
						if(arr[x]!=-1)
							x=arr[x];
					}
				}
								
				else if(pos)
				{
					if((y+sum)==n)
					{
						won=2;
						y=n;
					}
					if((y+sum)<n)
					{
						y=y+sum;
						if(arr[y]!=-1)
							y=arr[y];
					}				
				}
				
				if(x==y && (!pos))
					y=1;					

				if(x==y && (pos))
					x=1;
				
				pos=!pos;

				printf("%d %d %d\n",won,x,y);

			}
		}
		printf("%d %d %d\n",won,x,y);
	}
}
