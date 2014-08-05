#include<iostream>
#include<queue>
using namespace std;

bool matrix[10][10]={false};

struct node
{
	int x_pos;
	int y_pos;
	node(int a,int b)
	{
		x_pos=a;
		y_pos=b;
	}
};

queue <node> q;

int bfs()
{
	int x_var,y_var,x,y;
	int temp_x[]={-2,-2,-1,-1, 1, 1, 2, 2};
	int temp_y[]={-1, 1, 2,-2, 2,-2, 1,-1};
	while(!q.empty())
	{
		node curr=q.front();
		x_var=curr.x_pos;
		y_var=curr.y_pos;
		q.pop();
		for(int i=0;i<8;i++)
		{
			x=temp_x[i]+x_var;
			y=temp_y[i]+y_var;
			if(x <0 || y <0 || x >9 || y >9 || matrix[x][y]==false)
			continue;
			matrix[x][y]=false;
			//cout<<"x="<<x<<"y="<<y<<"\n";
			q.push(node(x,y));
		}
	}
}

int main()
{
	int n=0,a,b;
	cin>>n;
	int index=0;
	while(n>0)
	{
		index++;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			matrix[i][j]=false;
		for(int l=0;l<n;l++)
		{
			cin>>a;
			cin>>b;
			for(int i=a;i<b;i++)
			matrix[l][i]=true;
		}
	
		node source=node(0,0);
		q.push(source);
		matrix[0][0]=false;
		bfs();
		int count=0;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				if(matrix[i][j]==true)
				count++;
		if(count==1)
		cout<<"Case "<<index<<", "<<count<<" square can not be reached.\n";
		else
		cout<<"Case "<<index<<", "<<count<<" squares can not be reached.\n";
		cin>>n;	
	}
}
