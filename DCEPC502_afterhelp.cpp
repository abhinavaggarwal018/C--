//be careful about disjoint graphs. so check if  all visited
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int m,n,t,b_count,w_count,max_count,flag; // count of black and white in board
char grid[15][15];
bool global_vis[15][15],temp_arr[15][15];

int temp_x[]={-1,-1, 1, 1,-2,-2, 2, 2},x;
int temp_y[]={-2, 2,-2, 2, 1,-1, 1,-1},y;
void update_temp(char element)
{

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			temp_arr[i][j]=false;


	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			{
				if(grid[i][j]==element)
				{
					for(int i1=0;i1<8;i1++)
					{
						int a=i+temp_x[i1];
						int b=j+temp_y[i1];
//						cout<<"Value of the elements with ("<<a<<","<<b<<") are obtained\n";
						if(a<0||a>=m||b<0||b>=n)
						continue; 
//						cout<<"Making ("<<a<<","<<b<<") true1\n";
						temp_arr[a][b]=true;	
					}
//					cout<<"Making ("<<i<<","<<j<<") true2\n";
					temp_arr[i][j]=true;
				}			
			}
}
void dfs(int a,int b,char element)
{
	char element1;
	flag=0;

	update_temp(element);
/*
	for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<grid[i][j]<<" ";
			cout<<"\n";
		}
		
	for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			if(temp_arr[i][j]==true)
			cout<<"1";
			else
			cout<<"0";
			cout<<"\n";
		}*/
		
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(temp_arr[i][j]==false&&grid[i][j]=='.')
			{
				flag=1;
				global_vis[i][j]=true;
				if(element=='b')
				{
					element1='w';
					w_count++;
					grid[i][j]=element1;
				}
				else
				{
					element1='b';
					b_count++;
					grid[i][j]=element1;
				}
				dfs(i,j,element1);
				grid[i][j]='.';
				if(element=='b')
					w_count--;
				else
					b_count--;
				update_temp(element);
			}	
	if(flag==0)
	{
/*		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<grid[i][j]<<"\t";
			cout<<"\n";
		}*/
		//getchar();
		if(b_count+w_count>max_count)
		max_count=b_count+w_count;
	}
}

int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		b_count=0;
		w_count=0;
		max_count=0;
		cin>>m>>n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>grid[i][j];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				{
					if(global_vis[i][j]==false && grid[i][j]!='#') //If WA then remove visited condition and check for all elements.
					{
						grid[i][j]='b';
						b_count=1;
						global_vis[i][j]=true;
						dfs(i,j,'b');
						grid[i][j]='.';
						global_vis[i][j]=false;
					}
				}
		cout<<max_count<<"\n";
	}
}
