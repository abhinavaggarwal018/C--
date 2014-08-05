#include<iostream>
#include<cassert>

using namespace std;

struct edge
{
	int src;
	int dest;
	int weight;
	
/*	edge(int a,int b,int c)
	{
		src=a;
		dest=b;
		weight=c;
	}*/
};
/*
struct edge* create_edge(int a,int b,int c)
{
	struct edge *node=new struct edge(a,b,c);
	return node;
}*/

struct graph
{
	int E;
	int V;
	struct edge* edge;
	
};

struct graph* create_graph(int E,int V)
{
	struct graph *g=new struct graph;	
	
	g->E=E;
	g->V=V;
	
	g->edge=new edge[E];
}

void bellman_ford(graph *g)
{
	int *arr = new int[g->V];
	
	for(int i=0;i<g->V;i++)
		arr[i]=INT_MAX-1000;
		
	arr[0]=0;
	
	for(int i=0;i<g->V;i++)
	{
		for(int j=0;j<g->E;j++)
		{
			if(arr[g->edge[j].dest]>arr[g->edge[j].src]+g->edge[j].weight)
				arr[g->edge[j].dest]=arr[g->edge[j].src]+g->edge[j].weight;
		}
	}
	
	for(int i=0;i<g->V;i++)
	{
		for(int j=0;j<g->E;j++)
		{
			if(arr[g->edge[j].dest]>arr[g->edge[j].src]+g->edge[j].weight)
			{
				cout<<"Negetive cycle present";
			}
		}
	}

	for(int i=0;i<g->V;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	graph *graph=create_graph(8,5);
	
	graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    bellman_ford(graph);
 
    return 0;
	
}
