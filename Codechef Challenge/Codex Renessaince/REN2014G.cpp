#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

struct abc
{
	int x;
	int y;
}tower[1005],village;

struct ammunition
{
	int cost;
	int ind;
	
	ammunition(int a, int b)
	{
		cost=a;
		ind=b;
	}
	
	public:
	bool operator<(const ammunition &o) const
    {
        return cost > o.cost;
    }
}val(0,0);

priority_queue<ammunition> pq;

bool compare1(const abc &p, const abc &q)
{
	if(p.x!=q.x)
		return p.x<q.x;
	
	return p.y<=q.y;
}

bool compare2(const abc &p, const abc &q)
{
	if(p.x!=q.x)
		return p.x>q.x;
	
	return p.y>=q.y;
}

int main()
{
	int n;
	scanf("%d",&n);

	bool vis[1005];
	int	 dist[1005];
	
	for(int i=0;i<n;i++)
		vis[i]=false;

	tower[0].x=0;
	tower[0].y=0;
	
	for(int i=1;i<=n;i++)
		scanf("%d %d",&tower[i].x,&tower[i].y);

	scanf("%d %d",&village.x,&village.y);

	for(int i=0;i<n;i++)
	{
		vis[i]=false;
		dist[i]=INT_MAX;
	}

	while(!pq.empty())
		pq.pop();
	
	pq.push(ammunition(0,0));
	
	vis[0]=true;
	dist[0]=0;
	
	while(!pq.empty())
	{	
		int v1,v2;
		
		val=pq.top();
		pq.pop();
		
		if(val.ind==-1)
			break;
		
			
		for(int i=val.ind+1;i<=n;i++)
		{
			v1=(tower[i].x-tower[val.ind].x);
			v2=(tower[i].y-tower[val.ind].y);
			
			dist[i]=min(dist[i],(val.cost+(v1*v1)+(v2*v2)));
			
			if(!vis[i])
			{
				pq.push(ammunition(val.cost+dist[val.ind],i));
				vis[i]=true;
			}
		}
		
		v1=(village.x-tower[val.ind].x);
		v2=(village.y-tower[val.ind].y);
		
		pq.push(ammunition((val.cost+dist[n],-1));
	}
	
	printf("%d\n",val.cost);	
}
