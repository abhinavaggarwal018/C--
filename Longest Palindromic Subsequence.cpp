#include<abhinav.h>

int main()
{
	int arr[100][100];
	string str;
	
	cin>>str;
	int m=str.length();

	cout<<str;
	
	int n=m;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=-1;
		
	for(int i=0;i<m;i++)
		arr[i][i]=1;
	
	for(int k=1;k<m;k++)
		for(int i=0;i+k<n;i++)
		{
			int j=i+k;
			if(str[i]==str[j] && arr[i+1][j-1]==true)
				arr[i][j]=1;
			else
				arr[i][j]=0;
		}
		
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
