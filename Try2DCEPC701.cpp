#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

struct node
{
	int x_pos;
	int y_pos;
	int time1;
	
	node(int a,int b,int c)
	{
		x_pos=a;
		y_pos=b;
		time1=c;
	}
};

int a,b,p,q,total_time=0,arr[205][205],m,n;

bool mat[205][205]={false};

int x_var[]={-1, 0, 0, 1};
int y_var[]={ 0, 1,-1, 0};

bool operator < (const node &a,const node &b)
{
	return a.time1 > b.time1;
}



int bfs(struct node n1)
{
	priority_queue<struct node> pq;
	
	pq.push(n1);
	int x,y;
	
	while(!pq.empty())
	{
//		cout<<1;
		struct node node1=pq.top();
		
//		cout<<"x:"<<node1.x_pos<<"\t"<<"y:"<<node1.y_pos<<"\t"<<"node1.time1:"<<node1.time1<<"\n";
		
		pq.pop();

		if(node1.x_pos==p && node1.y_pos==q)
			return node1.time1;
		
		for(int i=0;i<4;i++)
		{
			x=node1.x_pos+x_var[i];
		
			y=node1.y_pos+y_var[i];
			
		//	cout<<x<<":"<<y<<"\n";
			if(x<0 || y<0 ||x >= m||y >= n || mat[x][y]==true)
				continue;
			
//			cout<<"Entered"<<"  x:"<<x<<"\t"<<"y:"<<y<<"\t"<<"node1.time1+1:"<<node1.time1+1<<"\t"<<"arr[x][y]:"<<arr[x][y]<<"\n";
			
			mat[x][y]=true;
			pq.push(node(x,y,max(node1.time1+1,arr[x][y])));
		}
	}
}

int main()
{
	char c;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m>>n;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				mat[i][j]=false;
	
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>c;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
				
		cin>>a>>b;
		cin>>p>>q;
		
		mat[0][0]=true;
		cout<<bfs(node(a,b,0))<<"\n";
	}
}
