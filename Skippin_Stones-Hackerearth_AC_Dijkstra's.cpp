#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int n,L,D,d[1005],i;
int flag=0;
float p[1005],prob_max=0;
struct node
{
	
	int dist_travelled;
	int index;
	float prob;
	
	node(int q,int w, float p)
	{
		dist_travelled=q;
		index=w;
		prob=p;
	}
	
};


bool operator<(const node& a, const node& b) 
{
	return a.prob < b.prob;
}

priority_queue <node> pq;

/*
void find_max(int dist_travelled,int index,float prob)
{
//	cout<<"\nDistance"<<dist_travelled<<"Next index"<<index<<"probaility"<<prob;
	if(index==n+1)
		if(prob_max<prob)
			{
				prob_max=prob;
				flag=1;
			}
	while((d[index]-dist_travelled)<=L&&index<n+1)
	{
		index++;
		int dist1=d[index-1];
		if(prob*p[index-1]<prob_max && flag==1)
			continue;
		find_max(dist1,index,prob*p[index-1]);
	}	
}*/



int bfs()
{
	while(!pq.empty())
	{
		node curr=pq.top();
		pq.pop();
		//cout<<"\nDistance"<<curr.dist_travelled<<"Next index"<<curr.index<<"probaility"<<curr.prob;
//		cout<<"Current x:"<<curr.x<<"\tCurrent y: "<<curr.y<<"\tCurrent time: "<<curr.time1<<"\n";		
		if(curr.index==n+1)
		{
				prob_max=curr.prob;
				flag=1;
				return 0;
		}
		
		while((d[curr.index]-curr.dist_travelled)<=L&&curr.index<n+1)
		{
			curr.index++;
			int index1=curr.index;
			int dist1=d[index1-1];
		//	cout<<"\nNextDistance"<<dist1<<"Next index"<<index1<<"probaility"<<curr.prob*p[index1-1];
			pq.push(node(dist1,index1,curr.prob*p[index1-1]));
		}	
	}
}


int main()
{
	scanf("%d %d %d",&n, &L, &D);
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
		p[n]=1;
	for(i=0;i<n;i++)
		scanf("%d",&d[i]);
		d[n]=D-d[n-1];
	if(d[n]>L)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	pq.push(node(0,0,1));
	bfs();
	if(flag==0)
		printf("IMPOSSIBLE");
	else
		printf("%.6f",prob_max);
	return 0;
}
