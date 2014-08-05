#include<iostream>

using namespace std;
#define INF 10000

int main()
{
	
	int arr[][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
    int n=4;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
					
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<"\t";
		cout<<"\n";
	}
}
