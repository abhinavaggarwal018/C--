// Indexing for original grid will start from 215
//I am using * to denote 1 and 2 can meet at a point and @ to denote 1 and 3 can
//meet at a point and & to denote 2 and 3 can meet at a point.
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
char grid[202][202];
int t,m,n,vis1[202][202],vis2[202][202],vis3[202][202],flag=0,num_value;
#define NUM 1
struct node
{
	int x;
	int y;
	int cnt;
	node(int a,int b,int num)
	{
		x=a;
		y=b;
		cnt=num;
	}
};
queue<node> q1,q2,q3;
int x,y,temp_x[]={-1, 1, 0, 0},temp_y[]={ 0, 0, 1,-1};
int bfs1()
{
	while(!q1.empty())
	{
		node curr=q1.front();
		q1.pop();
		
		//cout<<"Current x:"<<curr.x<<"\tCurrent y:"<<curr.y<<"\tCurrent count:"<<curr.cnt<<"\tCurrent element:"<<grid[curr.x][curr.y]<<"\n";
		
		for(int i=0;i<4;i++)
		{
			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
			if(x<0||x>m+1||y<0||y>n+1||vis1[x][y]>=0)
				continue;
			if(grid[x][y]=='3'||grid[x][y]=='2')
			{
				vis1[x][y]=curr.cnt+1;
				q1.push(node(x,y,curr.cnt+1));
			}
			else if(grid[x][y]=='.')
			{
				vis1[x][y]=curr.cnt+1;
				q1.push(node(x,y,curr.cnt+1));
			}		}
	}
}

int bfs2()
{
	while(!q2.empty())
	{
		node curr=q2.front();
		q2.pop();
		
		//cout<<"Current x:"<<curr.x<<"\tCurrent y:"<<curr.y<<"\tCurrent count:"<<curr.cnt<<"\tCurrent element:"<<grid[curr.x][curr.y]<<"\n";
		
		for(int i=0;i<4;i++)
		{
			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
			if(x<0||x>m+1||y<0||y>n+1||vis2[x][y]>=0)
				continue;
			if(grid[x][y]=='3'||grid[x][y]=='2')
			{
				vis2[x][y]=curr.cnt+1;
				q2.push(node(x,y,curr.cnt+1));
			}
			else if(grid[x][y]=='.')
			{
				vis2[x][y]=curr.cnt+1;
				q2.push(node(x,y,curr.cnt+1));
			}
		}
	}
}

int bfs3()
{
	while(!q3.empty())
	{
		node curr=q3.front();
		q3.pop();
		
		//cout<<"Current x:"<<curr.x<<"\tCurrent y:"<<curr.y<<"\tCurrent count:"<<curr.cnt<<"\tCurrent element:"<<grid[curr.x][curr.y]<<"\n";
		
		for(int i=0;i<4;i++)
		{
			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
			if(x<0||x>m+1||y<0||y>n+1||vis3[x][y]>=0)
				continue;
			if(grid[x][y]=='1'||grid[x][y]=='2')
			{
				vis3[x][y]=curr.cnt+1;
				q3.push(node(x,y,curr.cnt+1));
			}
			else if(grid[x][y]=='.')
			{
				vis3[x][y]=curr.cnt+1;
				q3.push(node(x,y,curr.cnt+1));
			}
		}
	}
}

int ans()
{
	int val=999999,min_val=9999999;
	/*cout<<"vis1[][]\n";
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cout<<vis1[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"vis2[][]\n";
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cout<<vis2[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"vis3[][]\n";
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cout<<vis3[i][j]<<"\t";
		}
		cout<<"\n";
	}*/
	for(int i=0;i<=m+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			if(vis1[i][j]!=-1&&vis2[i][j]!=-1&&vis3[i][j]!=-1)
			val=max(max(vis1[i][j],vis2[i][j]),vis3[i][j]);
			if(min_val>val)
			min_val=val;
		}
	}
	return min_val;
}

int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		num_value=0;
		cin>>m>>n;
		while(!q1.empty())
		q1.pop();
		while(!q2.empty())
		q2.pop();
		while(!q3.empty())
		q3.pop();
		for(int i=0;i<202;i++)
			for(int j=0;j<202;j++)
				{
					grid[i][j]='.';
					vis1[i][j]=-1;
					vis2[i][j]=-1;
					vis3[i][j]=-1;
				}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>grid[NUM+i][NUM+j];
				if(grid[NUM+i][NUM+j]=='1'||grid[NUM+i][NUM+j]=='2'||grid[NUM+i][NUM+j]=='3')
				{
					if(grid[NUM+i][NUM+j]=='1')
					{
						vis1[NUM+i][NUM+j]=0;
						q1.push(node(NUM+i,NUM+j,0));
					}
					if(grid[NUM+i][NUM+j]=='2')
					{
						vis2[NUM+i][NUM+j]=0;
						q2.push(node(NUM+i,NUM+j,0));
					}
					if(grid[NUM+i][NUM+j]=='3')
					{
						vis3[NUM+i][NUM+j]=0;
						q3.push(node(NUM+i,NUM+j,0));
					}
				}
			}
			bfs1();
			bfs2();
			bfs3();
		cout<<ans()<<"\n";
	}
}
