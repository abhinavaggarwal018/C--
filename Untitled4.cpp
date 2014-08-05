#include<iostream>
#include<vector>
#include<cstdio>
 
using namespace std;
 
struct node
{
long long int flag;
long long int sum;
};
 
struct node tree[300100];
int t,n,c,p,q,v,option;
 
void update(int node, int start, int end, int p, int q, int v)
{
if(p>q || start>end)
return;
 
tree[node].sum+=(tree[node].flag*(end-start+1));
 
if(start==end)
tree[node].flag=0;
else
{
tree[2*node].flag+=tree[node].flag;
tree[2*node+1].flag+=tree[node].flag;
tree[node].flag=0;
}
 
if(q<start || p>end)
return;
 
if(p<=start && q>=end)
{	
tree[node].sum+=(v*(end-start+1));

if(start==end)	
	return;

tree[2*node].flag+=v;
tree[2*node+1].flag+=v;
return;
}
 
int mid=start+(end-start)/2;
 
update(2*node,start,mid,p,q,v);
update(2*node+1,mid+1,end,p,q,v);
 
tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
}
 
long long int query(int node, int start, int end, int p, int q)
{
if(p>q || start>end)
return 0;
 
tree[node].sum+=(tree[node].flag*(end-start+1));
 
if(start==end)
tree[node].flag=0;
else
{
tree[2*node].flag+=tree[node].flag;
tree[2*node+1].flag+=tree[node].flag;
tree[node].flag=0;
}
 
if(p>end || q<start)
return 0;
 
if(p<=start && q>=end)
return tree[node].sum;
 
int mid=start+(end-start)/2;
 
return query(2*node,start,mid,p,q)+query(2*node+1,mid+1,end,p,q);
}
 
int main()
{
scanf("%d",&t);
 
while(t--)
{
scanf("%d %d",&n ,&c);
 
for(int i=0;i<=3*n;i++)
{
tree[i].flag=0;
tree[i].sum=0;
}
 
while(c--)
{
 
/* for(int i=0;i<17;i++)
printf("%lld %d\n",tree[i].sum,tree[i].flag);
*/	
scanf("%d",&option);
 
if(option==0)
{
scanf("%d %d %d",&p,&q,&v);
update(1,0,n-1,p-1,q-1,v);
}
 
else if(option==1)
{
v=0;
scanf("%d %d",&p,&q);
printf("%lld\n",query(1,0,n-1,p-1,q-1));
}
 
}
 
}
}
