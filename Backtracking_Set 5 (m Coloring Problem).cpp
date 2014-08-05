#include<iostream>

using namespace std;

#define size 4

int color[100]={0};
int pos=1;

bool find_possible(int row, int adj[size][size], int m)
{
	if(row==size)
		return true;
		

	for(int c=1;c<=m;c++)
	{
		int flag=0;
		for(int i=0;i<size;i++)
			if(adj[row][i] && color[i]==c)
				flag=1;
				
		if(flag==1)
			continue;
			
		color[row]=c;
			
		if(find_possible(row+1,adj,m))	
			return true;
			
		color[row]=0;
	}
	return false;
}

int main()
{
	int adj[size][size]={{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
	int m=3;
	
	color[0]=1;
	if(find_possible(1,adj,m))
	{
		for(int i=0;i<size;i++)
			cout<<color[i]<<" ";
	}
}
