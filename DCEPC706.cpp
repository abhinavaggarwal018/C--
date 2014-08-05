// Indexing for original grid will start from 215
//I am using * to denote 1 and 2 can meet at a point and @ to denote 1 and 3 can
//meet at a point and & to denote 2 and 3 can meet at a point.
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
char grid[202][202];
int t,m,n,vis1[202][202],vis2[202][202],vis3[202][202],arr[202][2],flag=0,num_value;
#define NUM 1
/*
void delete1(int x,int y)
{
	for(int i=0;i<num_value;i++)
		{
			if(arr[i][0]==x && arr[i][1]==y)
			{
				arr[i][0]=arr[num_value-1][0];
				arr[i][1]=arr[num_value-1][1];
			}
			num_value--;
			break;
		}
}

bool insert1(int x,int y)
{
	for(int i=0;i<num_value;i++)
		if(arr[i][0]==x && arr[i][1]==y)
			return false;
	arr[num_value][0]=x;
	arr[num_value][1]=y;
	num_value++;
	return true;
} 
*/
struct node
{
	int x;
	int y;
	int cnt;
	char c;
	node(int a,int b,int num,char ch)
	{
		x=a;
		y=b;
		cnt=num;
		c=ch;
	}
};
queue<node> q;
int x,y,temp_x[]={-1, 1, 0, 0},temp_y[]={ 0, 0, 1,-1};
int bfs()
{
	while(!q.empty())
	{
		node curr=q.front();
		q.pop();
		while(curr.c!=grid[curr.x][curr.y])
		{
			q.pop();
			curr=q.front();
		}
		//delete1(curr.x,curr.y);
		cout<<"Current x:"<<curr.x<<"\tCurrent y:"<<curr.y<<"\tCurrent count:"<<curr.cnt<<"\tCurrent element:"<<grid[curr.x][curr.y]<<"\n";
		for(int i=0;i<4;i++)
		{
			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
			if(x<0||x>m+1||y<0||y>n+1||grid[x][y]=='#')
				continue;
			if((vis1[x][y]==true && grid[curr.x][curr.y]=='1')||(vis2[x][y]==true && grid[curr.x][curr.y]=='2')||(vis3[x][y]==true && grid[curr.x][curr.y]=='3')||((vis1[x][y]==true && vis2[x][y]==true) && grid[curr.x][curr.y]=='*')||((vis2[x][y]==true && vis3[x][y]==true) && grid[curr.x][curr.y]=='&')||((vis3[x][y]==true && vis1[x][y]==true) && grid[curr.x][curr.y]=='@'))
			continue;
			
			cout<<"x:"<<x<<"\ty:"<<y<<"\tGrid:"<<grid[x][y]<<"\n";
			
			for(int i=0;i<=m+1;i++)
			{
				for(int j=0;j<=n+1;j++)
				{
					cout<<grid[i][j]<<" ";
				}
				cout<<"\n";
			}
getchar();
			if(grid[x][y]=='.')
			{
				grid[x][y]=grid[curr.x][curr.y];
				if(grid[curr.x][curr.y]=='1' ||grid[curr.x][curr.y]=='*' ||grid[curr.x][curr.y]=='@')
					vis1[x][y]=true;
				if(grid[curr.x][curr.y]=='2'||grid[curr.x][curr.y]=='*' ||grid[curr.x][curr.y]=='&' )
					vis2[x][y]=true;
				if(grid[curr.x][curr.y]=='3' || grid[curr.x][curr.y]=='@' ||grid[curr.x][curr.y]=='&' )
					vis3[x][y]=true;				
			}
			else if(grid[x][y]=='1')
			{
				if(grid[curr.x][curr.y]=='2' || grid[curr.x][curr.y]=='*')
					{
						grid[x][y]='*';
						vis2[x][y]=true;
					}
				else if(grid[curr.x][curr.y]=='3' || grid[curr.x][curr.y]=='@')
					{
						grid[x][y]='@';
						vis3[x][y]=true;
					}
				else if(grid[curr.x][curr.y]=='&')
					return curr.cnt;
			}
			else if(grid[x][y]=='2')
			{
				if(grid[curr.x][curr.y]=='1' || grid[curr.x][curr.y]=='*')
					{
						grid[x][y]='*';
						vis1[x][y]=true;
					}
				else if(grid[curr.x][curr.y]=='3' || grid[curr.x][curr.y]=='&')
					{
						grid[x][y]='&';
						vis3[x][y]=true;
					}
				else if (grid[curr.x][curr.y]=='@')
					return curr.cnt;
			}
			else if(grid[x][y]=='3')
			{
				if(grid[curr.x][curr.y]=='1' || grid[curr.x][curr.y]=='@')
					{
						grid[x][y]='@';
						vis1[x][y]=true;
					}
				else if(grid[curr.x][curr.y]=='2' || grid[curr.x][curr.y]=='&')
					{
						grid[x][y]='&';
						vis2[x][y]=true;
					}
				else if(grid[curr.x][curr.y]=='*')
					return curr.cnt;
			}
			else if(grid[x][y]=='*')
			{
				grid[x][y]=grid[curr.x][curr.y];
				if(grid[curr.x][curr.y]=='3'||grid[curr.x][curr.y]=='@'||grid[curr.x][curr.y]=='&')
					return curr.cnt;
			}
			else if(grid[x][y]=='@')
			{
				grid[x][y]=grid[curr.x][curr.y];
				if(grid[curr.x][curr.y]=='2'||grid[curr.x][curr.y]=='&'||grid[curr.x][curr.y]=='*')
					return curr.cnt;
			}
			else if(grid[x][y]=='&')
			{
				grid[x][y]=grid[curr.x][curr.y];
				if(grid[curr.x][curr.y]=='1'||grid[curr.x][curr.y]=='@'||grid[curr.x][curr.y]=='*')
					return curr.cnt;
			}
			//printf("%d %d %c %d\n",x,y,grid[x][y],curr.cnt+1);
			for(int i=0;i<num_value;i++)
			{
				cout<<arr[i][0]<<"\t"<<arr[i][1]<<"\n";
			}
			
			//if(insert1(x,y)==true)
			q.push(node(x,y,curr.cnt+1,grid[x][y]));
		}
	}
}
int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		num_value=0;
		cin>>m>>n;
		while(!q.empty())
		q.pop();
		for(int i=0;i<202;i++)
			for(int j=0;j<202;j++)
				{
					grid[i][j]='.';
					vis1[i][j]=false;
					vis2[i][j]=false;
					vis3[i][j]=false;
				}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>grid[NUM+i][NUM+j];
				if(grid[NUM+i][NUM+j]=='1'||grid[NUM+i][NUM+j]=='2'||grid[NUM+i][NUM+j]=='3')
				{
					if(grid[NUM+i][NUM+j]=='1')
					vis1[NUM+i][NUM+j]=true;
					if(grid[NUM+i][NUM+j]=='2')
					vis2[NUM+i][NUM+j]=true;
					if(grid[NUM+i][NUM+j]=='3')
					vis3[NUM+i][NUM+j]=true;
					q.push(node(NUM+i,NUM+j,0,grid[NUM+i][NUM+j]));
				}
			}
		cout<<bfs()<<"\n";
	}
}
