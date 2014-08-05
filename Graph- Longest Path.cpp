#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class AdjNode
{
	int V;
	int Weight;
	
	public:
		
		AdjNode(int v, int w)
		{
			this->V=v;
			this->Weight=w;
		}
		
		int getV()
		{
			return V;
		}
		
		int getWeight()
		{
			return Weight;
		}
};

class Graph
{
	int Node;
	vector<AdjNode> *AdjList;
	
	Graph(int V)
	{
		this->Node=V;
		this->AdjList=new vector<AdjNode>[V];
	}
	
	public:
		
		int getNode()
		{
			return Node;
		}
		
		int addEdge(int u, int v, int w)
		{
			AdjList[u].push_back(AdjNode(v,w));
		}
		
		int DFS(int node);
};

int DFS(int node)
{
	for(Graph::AdjList[i] iterator it)
}
