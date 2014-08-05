#include<iostream>
#include<queue>

using namespace std;

#define SIZE 4

struct node
{
	int x;
	int y;
	
	node(int a, int b)
	{
		x=a;
		y=b;
	}
};

bool vis[SIZE][SIZE];

void bfs(char mat[SIZE][SIZE])
{
	
	queue<struct node> q;
	
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			if(mat[i][j]=='O')
				q.push(node(i,j));
			
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			vis[i][j]=false;		
	
	
	int x_var[]={-1, 0, 0, 1};
	int y_var[]={ 0, 1,-1, 0}	;
				
	while(!q.empty())
	{
		node var=q.front();
		q.pop();
		
		int cnt=0;
		
		vis[var.x][var.y]=true;
		
		for(int i=0;i<SIZE;i++)
		{
			int x=var.x + x_var[i];
			int y=var.y+y_var[i];
			
			if(x<0||y<0 || x>=SIZE || y>=SIZE)
				continue;
				
			if(mat[x][y]=='O')
			{
				mat[x][y]='#';
				cnt++;
			}
			
			
		}
		
		if(cnt==0)
		{
			mat[x][y]='X'
			update(mat,x,y);
		}
	
	}
}

int main()
{
	char mat[SIZE][SIZE]={{'X','X' ,'X','X'},
					      {'X','O' ,'O','X'},
						  {'X','X' ,'O','X'},
						  {'X','O' ,'X','X'}};
				  
	bfs(mat);
	
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
			cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
}
