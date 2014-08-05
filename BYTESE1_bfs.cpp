//be careful with indexing as it is from one not zero
#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int x;
	int y;
	int time;
	node(int a1,int b1,int time_var)
	{
		x=a1;
		y=b1;
		time=time_var;
	}

};
	bool operator<(const node& a, const node& b) 
	{
  		return a.time > b.time;
	}
priority_queue<node> q;
int k,arr[101][101],m,n,a,b,T,min_time,x,y,x_var,y_var;
bool vis[101][101];
int	temp_x[]={-1, 0, 1, 0};
int	temp_y[]={ 0, 1, 0,-1};
int flag=0;
void bfs()
{
	while(!q.empty())
	{
		node src=q.top();
		q.pop();
		x_var=src.x;
		y_var=src.y;
		if(x_var==a && y_var==b)
		{
			min_time=src.time;
			//cout<<"Source time:"<<src.time<<"\n";
			//cout<<"Minimum Time: "<<min_time<<"\n";
			flag=1;
			while(!q.empty())
			q.pop();
			return;
		}

		//cout<<"Function started x:"<<src.x <<" y:"<<src.y <<"time:"<<src.time<<"\n";
	
		for(int i=0;i<4;i++)
		{
			x=x_var+temp_x[i];
			y=y_var+temp_y[i];
			if(x<1||x>m||y<1||y>n||vis[x][y]==true)
			continue;
			node val=node(x,y,src.time+arr[x][y]);
		//	cout<<"Pushing values for postions x:"<<x <<" y:"<<y <<"time:"<<val.time<<"\n";
			vis[x][y]=true;
			q.push(val);
		}
	}
}


int main()
{
	cin>>k;
	for (int l=0;l<k;l++)
	{
		flag=0;
		cin>>m;
		cin>>n;
		for(int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				cin>>arr[i][j];

		for(int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				vis[i][j]=false;
		cin>>a;
		cin>>b;
		cin>>T;			
		min_time=T;
//		cout<<"Input Array is:\n";
/*		for(int i=1;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
			{
				cout<<arr[i][j]<<" ";
			}
//			cout<<"\n";
		}*/
		if(a==1&&b==1)
		{
			if(T>=arr[1][1])
			{
				cout<<"YES\n";
				cout<<T-arr[1][1]<<"\n";
			}
			else
			cout<<"NO\n";
			continue;
		}
		node source=node(1,1,arr[1][1]);
		q.push(source);
		vis[1][1]=true;
		bfs();
		//cout<<"min time"<<min_time;
		int save_time=T-min_time;
		if(save_time>=0 && flag==1)
		{
			cout<<"YES\n";
			cout<<save_time<<"\n";
		}
		else if(flag==0)
			cout<<"NO\n";
	}
	
}
