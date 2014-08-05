#include<iostream>

using namespace std;

int arr[100][100],r,c;
bool vis[100][100];

int temp_x[]={-1,-1,-1, 0, 0, 1, 1, 1};
int temp_y[]={-1, 0, 1, 1,-1,-1, 0, 1};

void dfs(int i,int j)
{
	int x,y;
	
	for(int p=0;p<8;p++)
	{
		x=i+temp_x[p];
		y=j+temp_y[p];
		
		if(x<0)
			x=r+x;
		if(y<0)
			y=c+y;
		if(x>=r)
			x=x-r;
		if(y>=c)
			y=y-c;
			
		
	/*	if((x<0)||(y<0)||(x>=r)||(y>=c))
			continue;
	*/		
		if(arr[x][y]==true&&vis[x][y]!=true)
		{
			vis[x][y]=true;
			dfs(x,y);
			
			cout<<"Here x:"<<x<<"y:"<<y<<"\n";
		}
	}
}

int main()
{
	int cnt;
	while(1)
	{
		cin>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>arr[i][j];
				
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				vis[i][j]=false;
				
		cnt=0;
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]==true&&vis[i][j]==false)
				{
					cout<<"Main x:"<<i<<"y:"<<j<<"\n";
					vis[i][j]=true;
					dfs(i,j);
					cnt++;
				}
			}
			
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				cout<<vis[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\nAns:"<<cnt<<"\n";
	}
}
