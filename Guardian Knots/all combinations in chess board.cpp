#include<iostream>

using namespace std;

int arr[8][8]={0};
long long int cnt=0;

void func(int x, int y, int val)
{
	if(val==9)
	{
		cnt++;
/*
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		
		cout<<"\n";
	}
	
	int val1;
	cin>>val1;
*/	
		return;
	}

	for(int i=0;i<8;i++)
	{
		if(arr[x][i]==0)
		{
		
			for(int j=0;j<8;j++)
			{
				if(arr[x][j]==0)
					arr[x][j]=val;
			}
			
			for(int j=0;j<8;j++)
			{
				if(arr[j][i]==0)
					arr[j][i]=val;
			}
			
			func(x+1,y,val+1);

			for(int j=0;j<8;j++)
			{
				if(arr[x][j]==val)
					arr[x][j]=0;
			}
			
			for(int j=0;j<8;j++)
			{
				if(arr[j][i]==val)
					arr[j][i]=0;
			}
		}
	}
}


int main()
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)	
			arr[i][j]=0;
			
	arr[0][0]=-1;
	arr[0][7]=-1;
	arr[7][0]=-1;
	arr[7][7]=-1;
	
	func(0,0,1);
	
	cout<<cnt;
}
