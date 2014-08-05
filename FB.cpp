#include<iostream>
#include<cstdio>

using namespace std;

int g[11][11],s[11],score[11],n,k,q,c,num=0;

bool find()
{
	int val=0;

	for(int i=0;i<q;i++)
	{
		val=0;
		for(int j=0;j<k;j++)
		{
			if(s[j]==g[i][j])
				val++;
		}
//		cout<<val<<score[i]<<"\n";

		if(val!=score[i])
			return false;
	}
	
	return true;
}

bool possible(int cnt)
{
	if(cnt==k)
		return find();

	for(int i=1;i<=n;i++)
	{
		s[cnt]=i;
		if(possible(cnt+1))
			return true;
	}
	
	return false;
}

int main()
{
	cin>>c;
	while(c--)
	{
		scanf("%d %d %d",&n,&k,&q);
		for(int i=0;i<q;i++)
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&g[i][j]);
			}
			scanf("%d",&score[i]);
		}
		
		if(possible(0))
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}
