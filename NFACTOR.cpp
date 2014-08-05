#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

#define MAX 1000010
//#define NUM 1000

vector<int> div(MAX);

int arr[11][MAX];

int main()
{
	div[1]=0;
	
	for(int i=2;i<MAX;i+=2)
		++div[i];
		
	for(int i=3;i<MAX;i+=3)
		++div[i];
		
	bool incr=true;
	int i;	
	
	for(i=5;i<MAX;)
	{
		if(!div[i])
			for(int j=i;j<MAX;j+=i)
				++div[j];
				
		if(incr)
			i+=2;
		else
			i+=4;
	}
	
	for(int i=0;i<11;i++)
	{
		for(int j=1;j<MAX;j++)
		{
			if(div[j]==i)
				arr[i][j]=arr[i][j-1]+1;
			else
				arr[i][j]=arr[i][j-1];
		}
	}
	
	int t,a,b,n;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d %d",&a, &b, &n);
		printf("%d\n",arr[n][b]-arr[n][a-1]);
	}
}
