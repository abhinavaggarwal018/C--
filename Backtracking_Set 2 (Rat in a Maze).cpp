#include<iostream>

using namespace std;

#define size 4

bool path[size][size]= {{1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {1, 1, 1, 1}};
                
bool ans[size][size];

int x_pos[]={ 0, 1};
int y_pos[]={ 1, 0};

void find_path(int a, int b)
{
	if(a==size-1 && b==size-1)
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
	
	for(int i=0;i<2;i++)
	{
		int x=a+x_pos[i];
		int y=b+y_pos[i];
		
		if(x<0 || y<0 || x>=size || y>=size || path[x][y]==false)
			continue;
		
		ans[x][y]=true;
		
		find_path(x,y);
		
		ans[x][y]=false;
	}
}
int main()
{
	ans[0][0]=true;
	find_path(0,0);
}
