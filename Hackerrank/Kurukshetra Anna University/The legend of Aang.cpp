#include<iostream>
#include<cstdio>
#include<list>

using namespace std;

int x_move[]={0,1,0,-1};
int y_move[]={1,0,-1,0};
char str[1000][1000];
int x2,y2,x1,y1,t,m,n;
bool vis[1000][1000];

bool dfs(int x, int y)
{
	/*cout<<"("<<x<<","<<y<<") to ("<<x2<<","<<y2<<")\n";
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<str[i][j]<<" ";
		}
		cout<<"\n";
	}	

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<vis[i][j]<<" ";
		}
		cout<<"\n";
	}


	cout<<"\n";
	*/
	if(x==x2 && y==y2)
		return true;

	if(str[x][y]=='B'||str[x][y]=='G')
	{
		for(int i=0;i<4;i++)
		{
			int x_new=x_move[i]+x;
			int y_new=y_move[i]+y;			

			if(x_new<0 || y_new<0 || x_new>=m || y_new>=n ||vis[x_new][y_new])
				continue;
				
			vis[x_new][y_new]=true;
			
			if(dfs(x_new,y_new))
				return true;
		}
	}
	
	if(str[x][y]=='R')
	{
		str[x][y]='B';
		vis[x][y]=false;
		return false;
	}
	
	return false;
}

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d %d %d %d %d",&m,&n,&x1,&y1,&x2,&y2);
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				vis[i][j]=false;
		
/*		fflush(stdin);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%c",&str[i][j]);
			}
			fflush(stdin);
		}
*/

		for(int i=0;i<m;i++)
			cin>>str[i];
			
		x1--;
		x2--;
		y1--;
		y2--;

		vis[x1][y1]=true;			

		if(dfs(x1,y1))
			printf("Yes\n");
		else
			printf("No\n");
			
/*		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<vis[i][j]<<" ";
			}
			cout<<"\n";
		}
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<str[i][j]<<" ";
			}
			cout<<"\n";
		}*/
	}
}
