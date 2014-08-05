#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<list>
#include<climits>
using namespace std;

struct data
{
	int road;
	long long int len;

	data(int roadno, long long len1)
	{
		road=roadno;
		len=len1;
	}
	
	public:
	bool operator<(const data &o) const
    {
        return len > o.len;
    }
}val(0,0);

list< data > dist[100005];

priority_queue<data> pq;

int main()
{
	
	bool vis[100005];
	long long int dis[100005];
	int n,x,q,s,d;
	long long int l;
	
	while(1)
	{
		val.road=0;
		val.len=0;
		
		scanf("%d",&n);
		
		if(n==0)
			return 0;
			
		for(int i=1;i<n;i++)
		{
			scanf("%d %lld",&x,&l);
			
			dist[i].push_back(data(x,l));
			dist[x].push_back(data(i,l));
		}
		
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d",&s,&d);		
			
			for(int i=0;i<n;i++)
			{
				vis[i]=false;
				dis[i]=LLONG_MAX;
			}
			
			while(!pq.empty())
				pq.pop();
			
			pq.push(data(s,0));
			
			vis[s]=true;
			dis[s]=0;
			
			while(!pq.empty())
			{	
				val=pq.top();
				pq.pop();
				
				if(val.road==d)
					break;
					
				for(std::list<data>::iterator i=dist[val.road].begin();i!=dist[val.road].end();i++)
				{
					dis[(*i).road]=min(dis[(*i).road],val.len+((*i).len));
					
					if(vis[(*i).road]==false)
					{
						pq.push(data((*i).road,val.len+((*i).len)));
						vis[(*i).road]=true;
					}
				}
			}

			printf("%lld ",val.len);	
		}
		printf("\n");
		
		for(int i=0;i<n;i++)
			dist[i].clear();
	}
}
