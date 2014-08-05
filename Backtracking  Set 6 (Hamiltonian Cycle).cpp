#include<iostream>

using namespace std;

int n=5;
bool arr[100][100]= {{0, 1, 0, 1, 0},
	      {1, 0, 1, 1, 1},
	      {0, 1, 0, 0, 1},
	      {1, 1, 0, 0, 1},
	      {0, 1, 1, 1, 0},
	     },vis[100];
	
int check_hamilton(int val)
{
	for(int i=0;i<n;i++)
		cout<<vis[i];
	cout<<":";
	if(vis[val]==false)
	{
		vis[val]=true;
		for(int i=0;i<n;i++)
			cout<<vis[i];
		cout<<"\n";

		bool a=0;
		for(int i=0;i<n;i++)
			if(vis[i]==false)
				a=1;
				
		if(a==0&&arr[0][val])
		{
			
			cout<<val;
			return true;
		}	

		for(int i=1;i<n;i++)
		{
			if(arr[val][i]==true)
			{
				if(vis[i]==false)
				{
					if(check_hamilton(i))
					{
						cout<<"->"<<val;
						return true;
					}
				}
			}
		}
		vis[val]=false;
	}
	cout<<"\n";
	return false;
}

int main()
{
	/*
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	*/
	
	cout<<"->END\nAns:"<<check_hamilton(0);
	
}
