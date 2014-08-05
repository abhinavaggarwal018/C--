#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

int n,m;

struct graph
{
	int x;
	int y;
}g[100005];

bool compare(graph a,graph b)
{
	if(a.x < b.x || (a.x == b.x && a.y <= b.y))
		return true;
		
	return false;
}

int main()
{
	scanf("%d %d",&n,&m);
	


	
	for(int i=0;i<m;i++)
		scanf("%d %d",&g[i].x,&g[i].y);
		
	std::sort(g,g+m,compare);
	
	int min_x=1,min_y=1,max_x=n,max_y=n;
	
	for(int i=0;i<m;i++)
	{
		if()
	}

}
