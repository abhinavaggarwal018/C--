#include<iostream>
#include<queue>
using namespace std;
int a,b,c,p,q,r,time1[205][205];
char grid1[205][205];
bool vis[205][205];
int final_time=0;
struct node
{
	int x;
	int y;
	int time1;
	node(int q,int w, int e)
	{
		x=q;
		y=w;
		time1=e;
	}
	
};

bool operator<(const node& a, const node& b) 
	{
  		return a.time1 > b.time1;
	}

priority_queue <node> pq;
int temp_x[]={-1, 1, 0, 0},x;
int temp_y[]={ 0, 0, 1,-1},y;
int bfs()
{
	while(!pq.empty())
	{
		node curr=pq.top();
		pq.pop();

//		cout<<"Current x:"<<curr.x<<"\tCurrent y: "<<curr.y<<"\tCurrent time: "<<curr.time1<<"\n";		
		if(curr.x==p&&curr.y==q)
		{
			while(!pq.empty())
			pq.pop();
			return curr.time1;
		}
		
		for(int i=0;i<4;i++)
		{

			x=curr.x+temp_x[i];
			y=curr.y+temp_y[i];
					
			if(x<0||y<0||x>=r||y>=c || vis[x][y]==true)
				continue;

//			cout<<"x: "<<x<<"\ty: "<<y<<"\t"<<"time1: "<<time1[x][y]<<"\tcurr.time"<<curr.time1<<"\n";
			final_time=curr.time1+1;
			if(grid1[x][y]=='#')
			{
				if(time1[x][y]>curr.time1)
					final_time=time1[x][y];
				//cout<<"curr.time"<<curr.time1;
			}


			vis[x][y]=true;
				pq.push(node(x,y,final_time));
		}
	}
}


int main()
{
	int t;
	cin>>t;
	for(int m=0;m<t;m++)
	{
		final_time=0;
		cin>>r>>c;
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin>>grid1[i][j];
			vis[i][j]=false;
		}
		for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		cin>>time1[i][j];
		
		cin>>a>>b;
		cin>>p>>q;

		vis[a][b]=true;
		pq.push(node(a,b,0));
		cout<<bfs()<<"\n";  
	}
}
