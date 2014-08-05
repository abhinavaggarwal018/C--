#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 200005

struct node
{
	int data;
	vector<int> next;
	int flag;
	node()
	{
		data=0;
		flag=0;
		next.clear();		
	}
}arr[MAX];

vector<int> flags;

void add(int val, int x)
{
	int num=arr[x].flag+val;
	arr[x].data+=num;
	
	for(int i=0;i<arr[x].next.size();i++)
		add(-num,arr[x].next[i]);
	
	arr[x].flag=0;
}

void add_flag(int val, int x)
{
	arr[x].flag+=val;
	flags.push_back(x);
}

int main()
{
	int n,m,v1,v2,x,type,val;
	
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i].data);
		
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1].next.push_back(v2);
	}	
	
	for(int i=0;i<m;i++)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d %d",&x,&val);
			add_flag(val,x);
		}
		else if(type==2)
		{
			for(int i=0;i<flags.size();i++)	
				add(0,x);
			
			scanf("%d",&x);
			printf("%d\n",arr[x].data);
		}
	}
	
	
}
