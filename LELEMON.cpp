#include<cstdio>
#include<iostream>

using namespace std;

int maxm(int arr[105][10005], int n1,int n2)
{
	int ret=0;
	for(int i=0;i<n1;i++)
	{
		ret=max(ret,arr[n2][i]);
	}

	cout<<ret<<":"<<n1<<":"<<n2<<"::::";
	
	for(int i=0;i<n1;i++)
	{
		if(ret==arr[n2][i])
		{
			arr[n2][i]=0;
			break;
		}
	}
	cout<<ret<<"\n";
	return ret;
}

int main()
{
	int t,n,m,p[10005],v[105][10005],c[1000];
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		
		for(int i=0;i<m;i++)
			scanf("%d",&p[i]);
			
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			
			for(int j=0;j<c[i];j++)
			{
				scanf("%d",&v[j][i]);
			}
			
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<c[i];j++)
			{
				printf("%d ",v[j][i]);
			}
			printf("\n");
		}
		
		int ans=0;
		for(int i=0;i<m;i++)
		{
			ans+=maxm(v,p[i],c[p[i]]);
		}
		
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<c[i];j++)
			{
				printf("%d ",v[j][i]);
			}
			printf("\n");
		}
		cout<<"\n";

		
		printf("%d",ans);
	}
	
}
