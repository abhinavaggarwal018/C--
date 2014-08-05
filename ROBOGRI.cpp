#include<iostream>  // test case generator: ideone.com/4G6X6Q
#include<queue>
using namespace std;
char grid[1005][1005];
long long int dp[1005][1005];
long long int x_new,y_new,temp1_x[]={1,0},temp1_y[]={0,1},temp2_x[]={1,-1,0,0},temp2_y[]={0,0,1,-1},flag=0,n=0;
long long int count1=0;
bool vis[1005][1005]={false};
const long long int prime=(1<<31)-1;

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
queue <node> q;
/*
void dfs2(int x,int y)
{
	   
	if(x==n-1 && y==n-1)
	{
		flag=1;
		return;
	}
	for(int l=0;l<4;l++)
	{
		x_new=x+temp2_x[l];
		y_new=y+temp2_y[l];
		if(x_new<0||y_new<0||x_new>=n||y_new>=n||vis[x_new][y_new]==true||grid[x_new][y_new]=='#')
		continue;
		vis[x_new][y_new]=true;
		dfs2(x_new,y_new);
		if(flag==1)
		return;
		vis[x+temp1_x[l]][y+temp1_y[l]]=false;
	}
}
*/
void bfs2()
{
	while(!q.empty())
	{
		node curr=q.front();
		q.pop();
//		cout<<"Current X="<<curr.x <<"\tY="<<curr.y <<"\n";
		for(int l=0;l<4;l++)
		{	
			x_new=curr.x+temp2_x[l];
			y_new=curr.y+temp2_y[l];
			
//			cout<<"X="<<x_new<<"\tY="<<y_new<<"\n";
			if(x_new<0||y_new<0||x_new>=n||y_new>=n||vis[x_new][y_new]==true||grid[x_new][y_new]=='#')
			continue;
			vis[x_new][y_new]=true;
			if(x_new==n-1&&y_new==n-1)
			{
				flag=1;
				return;
			}
//			cout<<"Pushing x="<<x_new<<"y="<<y_new<<"\n";
/*			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
//					cout<<vis[i][j]<<"\t";
//				cout<<"\n";
			}*/
			q.push(node(x_new,y_new));
		}	
	}
}
void dp1()
{
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
				if(grid[i][j]=='#')
				dp[i][j]=0;
				if(grid[i][j]=='.')
				dp[i][j]=-1;
			}
			int flag12=0,flag13=0;
	for(int i=0;i<n;i++)
	{
		
		if(grid[i][0]=='.' &&flag12==0)
			dp[i][0]=1;
		if(grid[0][i]=='.' &&flag13==0)
			dp[0][i]=1;
		if(grid[i][0]=='#')
			flag12=1;
		if(grid[0][i]=='#')
			flag13=1;
		if(grid[i][0]=='.' &&flag12==1)
			dp[i][0]=0;
		if(grid[0][i]=='.' &&flag13==1)
			dp[0][i]=0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(dp[i][j]==-1)
			dp[i][j]=(dp[i-1][j]%prime+dp[i][j-1]%prime)%prime;
		    /*for(int a=0;a<n;a++)
			{
				for(int b=0;b<n;b++)
				{
					cout<<dp[a][b]<<"\t";
				}
			cout<<"\n";
			}*/
		}
	}
}
/*
void dfs1(int x,int y)
{
	if(x==n-1 && y==n-1)
	{
		::count1++;
//		cout<<"count1: "<<count1<<"\n";
		::count1=::count1%prime;
		return;
	}
	for(int l=0;l<2;l++)
	{
		x_new=x+temp1_x[l];
		y_new=y+temp1_y[l];
		if(x_new<0||y_new<0||x_new>=n||y_new>=n||vis[x_new][y_new]==true||grid[x_new][y_new]=='#')
		continue;
		vis[x_new][y_new]=true;
		cout<<"DFS for x:"<<x_new<<" y:"<<y_new<<"\n";
		/*for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(vis[a][b]==true)
				cout<<1<<"\t";
				else
				cout<<0<<"\t";
			}
			cout<<"\n";
		}
		dfs1(x_new,y_new);
		vis[x+temp1_x[l]][y+temp1_y[l]]=false;
	}
}*/
int main()
{
	//cout<<prime;
	cin>>n;
	if(n==0)
	return 0;
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			vis[a][b]=false;

	
	for(int l=0;l<n;l++)
	{
		cin>>grid[l];
	}
	//dfs1(0,0);
	dp1();
	::count1=dp[n-1][n-1];
	if(::count1>0)
	{
//		cout<<count1;
		cout<<::count1%prime;
		return 0;
	}
	//dfs2(0,0);
	vis[0][0]=true;
	q.push(node(0,0));
	bfs2();
	if(flag==1)
		cout<<"THE GAME IS A LIE";
	else 
		cout<<"INCONCEIVABLE";
	return 0;
}
