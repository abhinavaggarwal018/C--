#include<iostream>

using namespace std;

int sud[9][9]={0};

bool is_safe(int x, int y, int c)
{
	for(int i=0;i<9;i++)
		if(sud[x][i]==c || sud[i][y]==c)
			return false;
			
	return true;
}

bool fill_sudoku(int cnt)
{
	if(cnt==81)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				cout<<sud[i][j]<<" ";
				
			cout<<"\n";
		}
		return true;
	}
	
	int x=cnt/9;
	int y=cnt%9;
	
	for(int i=1;i<=9;i++)
	{
		if(is_safe(x,y,i))
		{
			sud[x][y]=i;
			if(fill_sudoku(cnt+1))
				return true;
			sud[x][y]=0;
		}
	}
	return false;
}

int main()
{
	fill_sudoku(0);
}

