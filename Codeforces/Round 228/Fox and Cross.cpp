#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	int n;
	bool vis[105][105];
	char str[105][105];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("\n%s",&str[i]);
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			vis[i][j]=false;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(str[i][j]=='#' && !vis[i][j])
			{
				if((i+2 >= n || j-1 < 0 || j+1 >= n || str[i+1][j-1]!='#' || str[i+1][j+1]!='#' || str[i+1][j]!='#' || str[i+2][j]!='#') || vis[i+1][j-1] || vis[i+1][j+1] || vis[i+1][j] || vis[i+2][j])
				{
					printf("NO\n");
					return 0;
				}
				else
				{
					vis[i][j]=true;
					vis[i+1][j-1]=true;
					vis[i+1][j+1]=true;
					vis[i+1][j]=true;
					vis[i+2][j]=true;

				}
			}
		}
	}
	
	printf("YES\n");
	return 0;
}
