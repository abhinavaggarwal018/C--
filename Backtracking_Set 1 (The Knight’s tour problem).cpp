#include<iostream>

using namespace std;

#define size 8

int cnt=0;
bool vis[size][size];
int x_pos[]={  2, 1, -1, -2, -2, -1,  1,  2 };
int y_pos[]={  1, 2,  2,  1, -1, -2, -2, -1 };
int arr[100];

bool find_moves(int a, int b)
{
	if(cnt == 64)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
				cout<<arr[8*j+ i]<<" ";
			cout<<"\n";
		}
		cout<<"\n\n";
		return true;
	}
	for(int i=0;i<8;i++)
	{
		int x=a+x_pos[i];
		int y=b+y_pos[i];
		
		if(x<0 || y< 0 || x>=8 || y>=8 || vis[x][y]==true)
			continue;
			
		vis[x][y]=true;
		arr[cnt]=(size*y)+x;
		
		cnt++;
		if(find_moves(x,y))
			return true;
		cnt--;
		
		vis[x][y]=false;
	}
}

int main()
{

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			vis[i][j]=false;
			
	vis[0][0]=true;
	cnt = 1;	
	arr[cnt-1]=0;
	find_moves(0,0);

}
