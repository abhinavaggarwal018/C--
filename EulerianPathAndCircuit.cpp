//http://www.geeksforgeeks.org/eulerian-path-and-circuit/

//Done using adjacency matrix

/*//Uncomment it for adjacency matrix method!
#include<iostream>
#include<stdio.h>

using namespace std;

int odd_max,n,arr[50][50],a,b,t;

int check_degree(int node)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		if(arr[node][i]==1)
			cnt++;
	cout<<"\nnode:"<<node<<"\tcount:"<<cnt;
	if(cnt%2==0)
		return 0;
	return 1;
}

int check_path()
{
	for(int i=0;i<n;i++)
	if(check_degree(i))
	{
		odd_max--;
		if(odd_max<0)
			return 0;
	}
	return 1;
}

int main()
{
	odd_max=2;
	cin>>n; //No. of rows=columns
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=0;
	cin>>t; // No. of undirected graph components
	while(t--)
	{
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	cout<<"Is it eulerian path(1 for yes,0 for no): "<<check_path()<<"\n";	
}



*/


#include<iostream>
#include<list>

using namespace std;

int odd_occ,n,cnt,t,a,b,num;

struct graph{
	int V;
	list<int> *adj;

graph(int V){
	this->V=V;
	adj= new list<int>[V];
}

~graph(){
	delete [] adj;
}

public:

int add_edge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int isEulerian()
{
	odd_occ=0;
	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(list<int>::iterator i1=adj[i].begin();i1!=adj[i].end();i1++)
		cnt++;
		if(cnt%2!=0)
		odd_occ++;
	}
	return odd_occ;
}
};

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		cin>>n;
		graph g1(n);
		cin>>t;
		while(t--)
		{
			cin>>a>>b;
			g1.add_edge(a,b);
		}
		num=g1.isEulerian();
		if(num>2)
			cout<<"Graph is not Eulerian\n";
		if(num==2)
			cout<<"Graph is Euler Path\n";
		if(num==0)
			cout<<"Graph is Euler Cycle\n";
	}
}
