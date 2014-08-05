#include<iostream>

using namespace std;

#define size 4

bool path[size][size]=	{{1, 0, 0, 0},
			            {1, 1, 0, 1},
			            {0, 1, 0, 0},
			            {1, 1, 1, 1}};
			            
bool ans[size][size];

int x_pos[]={-1,-1,-1, 0, 0, 1, 1, 1};
int y_pos[]={ 1, 0,-1, 1,-1, 1, 0,-1};

void mark_all(int x, int y)
{
	for(int i=0;i<size;i++)
	{
		ans[i][size]=false;
		ans[size][i]=false;
	}
	
	int i=x,j=y;
	while(i>=0 && j<size)
		ans[i++][j++]=true;
		
	while(i<size && j<size)
		ans[i--][j++]=true;
}

void unmark_all(int x, int y)
{
	int k=y;
	
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			ans[i][j]=true;
	
	for(int y=0;y<k;y++)
	{
		for(int i=0;i<size;i++)
		{
			ans[i][size]=false;
			ans[size][i]=false;
		}
		
		int i=x,j=y;
		while(i>=0 && j<size)
			ans[i++][j++]=true;
			
		while(i<size && j<size)
			ans[i--][j++]=true;
	}
}

void find_path(int column)
{
	if(column==size)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
				cout<<ans[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n\n";
		return;
	
	}	
	
	for(int i=0;i<size;i++)
	{
		if(ans[i][column]!=true)
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
			ans[i][j]=true;

	find_path(0);
}
