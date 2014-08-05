#include<iostream>
#include<cassert>

using namespace std;

int main()
{
	int arr[]={0,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
	int n=5;
	bool vis[8]={false};
    int graph[][5] = {0, 2, 0, 6, 0,
                  2, 0, 3, 8, 5,
                  0, 3, 0, 0, 7,
                  6, 8, 0, 0, 9,
                  0, 5, 7, 9, 0,
				  };
            
	vis[0]=true;		     
    bool flag=true;
    int i=0;
    while(flag)
    {
	    for(int j=0;j<n;j++)
	    {
	    	if(graph[i][j]!=0&vis[j]==false)
	    		arr[j]=min(arr[j],graph[i][j]);
	    }
		
		for(int j=0;j<n;j++)
			cout<<vis[j]<<":"<<arr[j]<<" ";
		cout<<"\n";
			    
		int min_ind=-1,min_val=INT_MAX;
		for(int j=0;j<n;j++)
	    	if(arr[j]<min_val && !vis[j])
	    	{
	    		min_ind=j;
	    		min_val=arr[j];
	    	}
	    
	    vis[min_ind]=true;
	    
	    flag=false;
	    
	    for(int i=0;i<n;i++)
	    	if(vis[i]==false)
	    		flag=true;
	    
	    i=min_ind;    
	}
	

}
