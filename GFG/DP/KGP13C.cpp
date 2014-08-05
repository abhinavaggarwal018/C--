#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int l[505], h[505],ans;

void conc_rec(int pos, int l_prev, int end, int red, int cost)
{
	
//	cout<<pos<<":"<<l_prev<<":"<<end<<":"<<red<<":"<<cost<<"\n";
	
	if(pos>end)
		return;
	
	if(red==0)
	{
		ans=min(ans,cost);
		return;
	}
	
	conc(pos+1,l_prev+l[pos],end,red-1,cost+(l_prev+l[pos])*h[pos+1]);
	conc(pos+1,0,end,red,cost);
}

void conc_rec(int pos, int l_prev, int end, int red, int cost)
{
	
}

int main()
{
	int n,k,m,w;
	
	scanf("%d",&n);
	
	for(int t=0;t<n;t++)
	{
		ans=INT_MAX;
		scanf("%d %d %d",&k,&m,&w);
		
		for(int i=0;i<k;i++)
		{
			scanf("%d %d",&l[i],&h[i]);
		}
		
		
		conc(0,0,k-1,k-m,0);
		printf("Case %d: %d\n",t+1,ans*w);
	
	}
	
	
}
