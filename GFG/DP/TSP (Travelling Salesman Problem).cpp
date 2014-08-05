#include<iostream>
#include<queue>
using namespace std;

int adj[100][100];

struct data
{
	int city[100]; // Assuming total 100 cities
	int cost;
	
	data()
	{
		for(int i=0;i<100;i++)
			city[i]=0;
			
		cost=0;
	}
	
	bool operator<(const data &a) const
	{
		return cost<a.cost;
	}
};

void recur()
{
	priority_queue<data> q;
	
	data node = new data();
	node.city[0]=true;
	
	q.push(node);
	
	while(!q.empty())
	{
		data val = q.top();
		delete 
	}
	
}	

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>adj[i][j];
		}
	}
	
	recur();

}
