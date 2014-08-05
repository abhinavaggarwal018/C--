#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,w;
	while(1)
	{
		cin>>n;
		vector<int> val(n,-1),weight(n,0);
		
		for(int i=0;i<n;i++)
			cin>>val[i];
		for(int i=0;i<n;i++)
			cin>>weight[i];
		
		cin>>w;
		
		vector< vector<int> > arr((n+1),vector<int> (w+1));
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<w;j++)
				arr[i][j]=-1;
		
		//For infinite number of items of each value
		
		/*
		vector<int> arr(w+1,-1);
		arr[0]=0;
		
		for(int i=1;i<=w;i++)
		{
			arr[i]=arr[i-1];
		
			for(int j=0;j<n;j++)
			{
				if((i-weight[j])>=0&&arr[i-weight[j]]>=0&&(arr[i-weight[j]]+val[j])>arr[i])
					arr[i]=arr[i-weight[j]]+val[j];
			}
		}
		*/
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<=w;j++)
			{
				if(i==0||j==0)
					arr[i][j]=0;
					
				else if(weight[i-1]<=j)
					arr[i][j]=max(arr[i-1][j],arr[i-1][j-weight[i-1]]+val[i-1]);
					
				else
					arr[i][j]=arr[i-1][j];
			}
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<=w;j++)
				cout<<arr[i][j]<<" ";
	}
}
