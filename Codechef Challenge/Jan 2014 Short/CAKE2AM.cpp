#include<iostream>
#include<cstdio>

using namespace std;

int matrix[10001][10001];

int main()
{
	long long int cnt=0;
	int t,x1,x2,x3,x4,y1,y2,y3,y4;

	scanf("%d",&t);

	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<1001;j++)
		{
			matrix[i][j]=0;
		}
	}	

	int xMin=0,yMin=0,xMax=0,yMax=0;
	
	while(t--)
	{
		cnt=0;
		
		for(int i=0;i<1001;i++)
		{
			for(int j=0;j<1001;j++)
			{
				matrix[i][j]=0;
			}
		}
		
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
		
		xMin=min(x1,x3);
		xMax=max(x2,x4);
		yMin=min(y1,y3);
		yMax=max(y2,y4);
				
		for(int i=x1;i<x2;i++)
		{
			for(int j=y1;j<y2;j++)
			{
				matrix[i][j]=1;
			}
		}
		
		for(int i=x3;i<x4;i++)
		{
			for(int j=y3;j<y4;j++)
			{
				matrix[i][j]=1;
			}
		}
		
		for(int i=xMin;i<xMax;i++)
		{
			for(int j=yMin;j<yMax;j++)
			{
				if(matrix[i][j]==1)
				{
					cnt++;
					matrix[i][j]=0;
				}
			}
		}
		
		printf("%lld\n",cnt);
		
	}

	return 0;
}
