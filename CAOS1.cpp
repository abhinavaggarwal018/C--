#include<stdio.h>
#include<iostream>

#define si(t) scanf("%d",&t)
#define ss(t) scanf("%s",&t)
using namespace std;

int main()
{
	int t,r,c,i,j,pos[55][4],cnt;
	char grid[55][55];
	si(t);
	
	while(t--)
	{
		si(r);
		si(c);
		
		for(i=0;i<r;i++)
			ss(grid[i]);
			
		for(i=0;i<r;i++)
		{
			cnt=0;
			for(j=0;j<c;j++)
			{
				
				if(grid[i][j]=='^')
					cnt++;
				else
					cnt=0;	
				
				if(cnt==2)
				{
					pos[i][0]=j;
					break;
				}
			}
			
			if(cnt<2)	
				pos[i][0]=100;
		}
		
		for(i=0;i<r;i++)
		{
			cnt=0;
			for(j=c-1;j>=0;j--)
			{
				
				if(grid[i][j]=='^')
					cnt++;
				else
					cnt=0;
				
				if(cnt==2)
				{
					pos[i][1]=j;
					break;
				}
			}
			
			if(cnt<2)	
				pos[i][1]=-100;
		}
		
		for(i=0;i<c;i++)
		{
			cnt=0;
			for(j=0;j<r;j++)
			{
				
				if(grid[j][i]=='^')
					cnt++;
				else
					cnt=0;
									
				if(cnt==2)
				{
					pos[i][2]=j;
					break;
				}
		
			}
			
			if(cnt<2)	
				pos[i][2]=100;
		}
		
		for(i=0;i<c;i++)
		{
			cnt=0;
			for(j=r-1;j>=0;j--)
			{

				if(grid[j][i]=='^')
					cnt++;
				else
					cnt=0;
		
				if(cnt==2)
				{
					pos[i][3]=j;
					break;
				}
			}
			
			if(cnt<2)	
				pos[i][3]=-100;
		}			
		
		int ans=0;
		
		for(i=2;i<r-2;i++)
			for(int j=2;j<c-2;j++)
			{
				if(j>pos[i][0] && j<pos[i][1] && i>pos[j][2] && i<pos[j][3])
				{
					ans++;
				}
			}
		
	//	for(int i=0;i<max(r,c);i++)
	//		cout<<"\ni:\tRowmin:"<<pos[i][0]<<"   RowMax:"<<pos[i][1]<<"  ColMin:"<<pos[i][2]<<"  ColMax"<<pos[i][3]<<"\n";
		
		printf("%d\n",ans);
		
	}
}
