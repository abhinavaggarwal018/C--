#include<iostream>

using namespace std;

int m,n;
char arr[70][70];
int x_var[]={-1,-1,-1, 0, 0, 1, 1, 1};
int y_var[]={ 0, 1,-1, 1,-1, 0, 1,-1};
bool vis[70][70];

void dfs(int x_pos,int y_pos,char c,int *cnt)
{
		int x,y;
		
		for(int i=0;i<8;i++)
		{
			x=x_pos+x_var[i];
			y=y_pos+y_var[i];
			
			if(x<0 ||y<0 ||x>=m || y>=n || arr[x][y]!=c || vis[x][y])
				continue;
				
			vis[x][y]=true;
			*cnt=max(*cnt,c-65+1);
			dfs(x,y,c+1,cnt);
			//vis[a][b]=false;
		}
}

int main()
{
	int t=0;
	while(1)
	{
		t++;
		cin>>m>>n;
		if(m==0&&n==0)
			return 0;
			
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				vis[i][j]=false;
				
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
				
		int cnt=0,ans=0;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]=='A')
				{
					cnt=1;
					dfs(i,j,'B',&cnt);
					ans=max(ans,cnt);
				}
			}

		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
}
