#include<iostream>

using namespace std;

#define size 7

bool path[size][size]=	{{1, 0, 0, 0},
			            {1, 1, 0, 1},
			            {0, 1, 0, 0},
			            {1, 1, 1, 1}};
			            
int ans[size][size];

int x_pos[]={-1,-1,-1, 0, 0, 1, 1, 1};
int y_pos[]={ 1, 0,-1, 1,-1, 1, 0,-1};

void mark_all(int x, int y)
{
	for(int i=0;i<size;i++)
	{
		ans[i][y]=1;
		ans[x][i]=1;
	}
	
	int i=x,j=y;
	while(i>=0 && i<size && j>=0 && j<size)
		ans[i++][j++]=1;
	
	i=x,j=y;
	while(i>=0 && i<size && j>=0 && j<size)
		ans[i--][j++]=1;
		
	ans[x][y]=2;
}

void unmark_all(int x, int y)
{
	int k=y;
	
	for(int i=0;i<size;i++)
		for(int j=y;j<size;j++)
			ans[i][j]=0;
			
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(ans[i][j]==2)
				mark_all(i,j);
		}
	}
}

void display()
{
	for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cout<<ans[i][j]<<" ";
			cout<<"\n";
		}
	cout<<"\n\n";
}

void find_path(int column)
{
	if(column==size)
	{
		display();
		return;
	
	}	
	
	for(int i=0;i<size;i++)
	{
		if(ans[i][column]!=0)
			continue;
			
		mark_all(i,column);
		find_path(column+1);
		unmark_all(i,column);
	}

}
int main()
{
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			ans[i][j]=0;

	find_path(0);
}
