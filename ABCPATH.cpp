#include<iostream>
//#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int h,w,n,max1=64;
char matrix[55][55];
bool vis[55][55];
struct node
{
	int x_pos;
	int y_pos;
	node(int a,int b)
	{
		x_pos=a ;
		y_pos=b ;
	}
};

queue <node> q;

int bfs()
{
	int x,y,x_var,y_var;
	int temp_x[]={-1,-1,-1, 0, 0, 1, 1, 1};
	int temp_y[]={-1, 0, 1, 1,-1,-1, 0, 1};
	while(!q.empty())
	{
		node curr=q.front();
		q.pop();
		x_var=curr.x_pos;
		y_var=curr.y_pos;
	
		for(int i=0;i<8;i++)
		{
			x=x_var+temp_x[i];
			y=y_var+temp_y[i];
			if(x < 0 || x>=h || y <0 || y>= w)
			continue;
			if((vis[x][y]==false)&&(matrix[x][y]==matrix[x_var][y_var]+1))  // If next character is greater than ASCII of first by one
			{
				vis[x][y]=true;
				q.push(node(x,y));
				if(matrix[x][y]>max1)
					max1=matrix[x][y];
			}
			
		}
	}
}
int main()
{
	int count=0;
	//vector<bool> vis[n];
	//vis=vector<bool>(n,false);
	while(1)
	{
		count++;
		cin>>h>>w;
		//scanf("%d %d",&h,&w);
		//printf("%d %d",h,w);
		n=h*w;
		max1=64;
		if(n==0)
		return 0;
	/*	for(int i=0;i<h;i++)
			scanf("%s",matrix[i]);*/
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				cin>>matrix[i][j];
				vis[i][j]=false;
			}
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				if(matrix[i][j]=='A')
				{	
					vis[i][j]=true;
					q.push(node(i,j));
					max1='A';
				}
			}
			bfs();
			//printf("Case %d: %d\n",count,max1-int('A')+1);
			cout<<"Case "<<count<<": "<<max1-int('A')+1<<"\n";
	}
	return 0;
}
