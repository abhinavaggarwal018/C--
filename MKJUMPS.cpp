#include<iostream>
#include<queue>
using namespace std;

int min1=3000;
bool matrix[10][10]={false};
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

void dfs(node src)
{
	int x_var,y_var,x,y,flag=0;
	x_var=src.x_pos;
	y_var=src.y_pos;
	int temp_x[]={-2,-2,-1,-1, 1, 1, 2, 2};
	int temp_y[]={-1, 1, 2,-2, 2,-2, 1,-1};
	for(int i=0;i<8;i++)
	{
		int val;
		x=temp_x[i]+x_var;
		y=temp_y[i]+y_var;
		if(x <0 || y <0 || x >9 || y >9 || matrix[x][y]==false)
		continue;
		matrix[x][y]=false;
		//cout<<"x="<<x<<"y="<<y<<"\n";
		dfs(node(x,y));
		matrix[x][y]=true;
	}
	//if(flag=1)
	//return min1;
	int count=0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(matrix[i][j]==true)
				count++;
		//		cout<<"count:"<<count<<"\n";
	if(min1>count)
	min1=count;	
}

int main()
{
	int n=0,a,b;
	cin>>n;
	int index=0;
	while(n>0)
	{

		min1=3000;
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
		matrix[0][0]=false;
		dfs(source);
		if(min1==1)
		cout<<"Case "<<index<<", "<<min1<<" square can not be reached.\n";
		else
		cout<<"Case "<<index<<", "<<min1<<" squares can not be reached.\n";
		cin>>n;	
	}
}

