#include<abhinav.h>

int main()
{
	int arr[3][4]={{1,2,4,5},
				{2,5,6,8},
				{3,6,8,9}};
	int n=sizeof(arr[0])/sizeof(arr[0][0]);
	int m=sizeof(arr)/n;
	m=3;n=4;
	
	while(arr[0][0]!=INT_MAX)
	{
		cout<<arr[0][0]<<" ";
		arr[0][0]=INT_MAX;
		
		int i=0,j=0;
		
		int minm=min(arr[i+1][j],arr[i][j+1]);
		
		while(arr[i][j]>minm)
		{
			int temp=arr[i][j];
			
			if(i<m-1 && arr[i+1][j]==minm)
			{
				arr[i][j]=arr[i+1][j];
				arr[i+1][j]=temp;
				i=i+1;
			}
			
			else if(j<n-1 && minm==arr[i][j+1])
			{
				arr[i][j]=arr[i][j+1];
				arr[i][j+1]=temp;
				j=j+1;
			}
			
			if(i<m-1 && j<n-1)
				minm=min(arr[i+1][j],arr[i][j+1]);
				
			else if(i<m-1)
				minm=arr[i+1][j];
				
			else if(j<n-1)
				minm=arr[i][j+1];
				
			else
				minm=INT_MAX;
		}
		
	}
}
