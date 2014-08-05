//be careful about disjoint graphs. so check if  all visited
#include<iostream>
#include<queue>
using namespace std;

int m,n,t,b_count,w_count; // count of black and white in board
char grid[15][15];
bool vis[15][15];
struct node
{
	int x;
	int y;
	node(int a,int b)
	{
		x=a;
		y=b;
	}
};

int temp_x[]={-1,-1, 1, 1,-2,-2, 2, 2},x;
int temp_y[]={-2, 2,-2, 2, 1,-1, 1,-1},y;
queue<node> qb,qw;


void bfs()
{
	while(!qb.empty()||!qw.empty())
	{
		if(b_count<w_count) // if white>black, I place black then white
		{
			if(!qb.empty())
			{
				node curr=qb.front();
				qb.pop();
				for(int i=0;i<8;i++)
				{
					x=curr.x+temp_x[i];
					y=curr.y+temp_y[i];
					if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
						continue;
					if(grid[curr.x][curr.y]=='w')
						continue;
					
					grid[x][y]=grid[curr.x][curr.y];
					vis[x][y]=true;
					qb.push(node(x,y));
					b_count++;	
				}
			}
			if(!qw.empty())
			{
				node curr=qw.front();
				qw.pop();
				for(int i=0;i<8;i++)
				{
					x=curr.x+temp_x[i];
					y=curr.y+temp_y[i];
					if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
						continue;
					if(grid[curr.x][curr.y]=='b')
						continue;
					
					grid[x][y]=grid[curr.x][curr.y];
					vis[x][y]=true;
					qw.push(node(x,y));
					w_count++;	
				}
			}
		}
		else
		{
			if(!qw.empty())
			{
				node curr=qw.front();
				qw.pop();
				for(int i=0;i<8;i++)
				{
					x=curr.x+temp_x[i];
					y=curr.y+temp_y[i];
					if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
						continue;
					if(grid[curr.x][curr.y]=='b')
						continue;
					grid[x][y]=grid[curr.x][curr.y];
					vis[x][y]=true;
					qw.push(node(x,y));
					w_count++;	
				}
			}
			
			if(!qb.empty())
			{
				node curr=qb.front();
				qb.pop();
				for(int i=0;i<8;i++)
				{
					x=curr.x+temp_x[i];
					y=curr.y+temp_y[i];
					if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
						continue;
					if(grid[curr.x][curr.y]=='w')
						continue;
					
					grid[x][y]=grid[curr.x][curr.y];
					vis[x][y]=true;
					qb.push(node(x,y));
					b_count++;	
				}
			}
			
		}
	}
}/*
bwb
*b*
wbw*/
/*void bfs()
{
	while(!q.empty())
	{
		node curr=q.front();
		q.pop();
		//cout<<"Current X:"<<curr.x<<"\tCurrent Y:"<<curr.y;
		for(int i=0;i<8;i++)
		{
			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
		//	cout<<"\nX:"<<x<<"\tY:"<<y;			
			if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
				continue;
			vis[x][y]=true;
			grid[x][y]=grid[curr.x][curr.y];
			q.push(node(x,y)); 
		}

	}
}
*/

/*
b...
..b.
bb..
.b.b
*/
/*int x_var,y_var;
void dfs(int x,int y,char val)
{
	
	for(int i=0;i<8;i++)
		{
			x_var=x+temp_x[i];
			y_var=y+temp_y[i];
		//	cout<<"\nX:"<<x<<"\tY:"<<y;			
			if(x<0||y<0||x>=m||y>=n||vis[x][y]==true)
				continue;
			vis[x][y]=true;
			grid[x][y]=grid[curr.x][curr.y];
			q.push(node(x,y)); 
		}
}*/
int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		bool b_push=false,w_push=false;
		b_count=0;
		w_count=0;
		cin>>m>>n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				{
					cin>>grid[i][j];
					vis[i][j]=false;
					if(grid[i][j]=='#')
						vis[i][j]=true;
				}

		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(vis[i][j]!=true)
					{
						if(b_push==false)
						{
							grid[i][j]='b';
							qb.push(node(i,j));
							cout<<"Pushing("<<i<<","<<j<<") as black";
							b_push=true;
						}
						else if(w_push==false)
						{
							grid[i][j]='w';
							qw.push(node(i,j));
							cout<<"Pushing("<<i<<","<<j<<") as white";
							w_push=true;
						}
						if(b_push==true && w_push==true)
						bfs();
					}
					cout<<"\n\n";
		for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<grid[i][j]<<"\t";
				}
				cout<<"\n";
			}
		cout<<b_count+w_count<<"\n";
	}
	
}
