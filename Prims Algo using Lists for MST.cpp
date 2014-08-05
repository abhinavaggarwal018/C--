#include<iostream>
#include<list>
#include<climits>

using namespace std;

struct edges{
	int src;
	int dest;
	int weight;
	list<edges> edge;
	
	edges(int a,int b, int c)
	{
		src=a;
		dest=b;
		weight=c;
	}
	
	edges()
	{
		
	}
};

struct graph{
	int V;
	int E;
	edges *node;
	
	graph(int V1,int E1)
	{
		V=V1;
		E=E1;
		node = new edges[V1];
	}
};

find_prim(graph g)
{
	
}

int main()
{
	int E,V;
	E=0;
	V=0;
	
	graph g(V,E);

	g.node[0].edge= insert(edges(0,1,10));	
}
