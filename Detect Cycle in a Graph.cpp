#include<iostream>
#include<list>

using namespace std;

bool vis[100],stack[100];
int v,n,a,b;
	
struct graph
{
	int v;
	list<int> *adj;
	graph(int v)
	{
		this->v=v;
		adj= new list<int> [v]; 
	}
	
	void add_edge(int a,int b)
	{
		adj[a].push_back(b);
	}
	
	bool detect_cycle();
	bool detect_cycle_main(int n);	
};

bool graph::detect_cycle_main(int i)
{
	if(vis[i]==false)
	{
		vis[i]=true;
		stack[i]=true;
		
		list<int>::iterator it;
		for(it = adj[i].begin();it!=adj[i].end();it++)
		{
			detect_cycle_main(*it);
		}
		
		stack[i]=false;
	}
	
	else
	{
		if(stack[i]==true)
		{
			cout<<"Contains a cycle\n";
			return true;
		}
	}
	return false;	
}

bool graph::detect_cycle()
{

	for(int i=0;i<v;i++)
	{
		vis[i]=false;
		stack[i]=false;
	}
	
	for(int i=0;i<v;i++)
		if(!detect_cycle_main(i))
			return false;
			
	return true;
	
}


int main()
{

	while(1)
	{
		cin>>v;
		graph g=graph(v);
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			g.add_edge(a,b);
		}
		cout<<"dsfsf";
		cout<<g.detect_cycle();	
	}
}
