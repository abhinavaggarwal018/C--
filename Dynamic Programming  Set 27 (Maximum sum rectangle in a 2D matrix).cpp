#include<iostream>

using namespace std;

int main()
{
	cin>>m>>n;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
			
	for(int i=0;i<m;i++)
	{
		for(int k=0;k<n;k++)
			temp[k]=0;

		for(int j=i;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				temp[k]+=arr[k][j];
			}
			if(kedans(temp,0,n)>ans)
				temp[k]=ans;
		}
	}
	
	if(ans<0)
		ans=0;
}
