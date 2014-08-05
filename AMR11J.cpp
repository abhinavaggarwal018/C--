#include<iostream>
#include<queue>
#include<vector>
using namespace std;
char grid1[505][505];
char matrix1[505][505];
bool vis[505][505];
char civilisation[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int r,c;

struct node
{
	int x;
	int y;
	char val;
	node(int a, int b, char c)
	{
		x=a;
		y=b;
		val=c;
	}
};
queue<node> q;
bool exit_flag;
int temp_x[]={-1, 0, 0, 1},index;
int temp_y[]={ 0, 1,-1, 0};

void bfs()
{
while(!q.empty())
{
	while(!q.empty())
	{
		node curr=q.front();
		//cout<<"\n1Current Node x="<<curr.x<<" y="<<curr.y<<" value="<<grid1[curr.x][curr.y];
		q.pop();
		for(int q=0;q<4;q++)
		{
			exit_flag=false;
			int x=temp_x[q]+curr.x;
			int y=temp_y[q]+curr.y;
			if(x<0 || y<0 || x>=r || y>=c || grid1[x][y]=='#'||vis[x][y]==true || grid1[x][y]=='*')
			continue;
			for(int l=0;l<26;l++)
			{
				if(grid1[x][y]==civilisation[l])  //checking if enclosing block is a civilisation
				exit_flag=true;
			}
			if(exit_flag==true)
			continue;
		//cout<<"\nModifying matrix1 for x="<<x<<" y="<<y;				
		if(matrix1[x][y]==' ')
		matrix1[x][y]=curr.val;
		else if(matrix1[x][y]!=curr.val)
		matrix1[x][y]='*';
		/*cout<<"\n";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			cout<<matrix1[i][j];
			cout<<"\n";
		}*/
		}
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(matrix1[i][j]!=' ')
			{
				grid1[i][j]=matrix1[i][j];
				
				if(matrix1[i][j]!='*')
				{
		//			cout<<"\n2Pushing x="<<i<<" y="<<j<<" value="<<grid1[i][j];
					q.push(node(i,j,grid1[i][j]));
					vis[i][j]=true;
				}
				matrix1[i][j]=' ';
			}	
		}
	}
}
		//cout<<"\n";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			cout<<grid1[i][j];
			cout<<"\n";
		}}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>r>>c;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			vis[i][j]=false;
			matrix1[i][j]=' ';
			cin>>grid1[i][j];
			if(grid1[i][j]!='#'&&grid1[i][j]!='.')
			{
		//		cout<<"\nPushing x="<<i<<" y="<<j<<" value="<<grid1[i][j];
				vis[i][j]=true;
				q.push(node(i,j,grid1[i][j]));
			}
		}
		bfs();
		cout<<"\n";
	}
	
	
}
