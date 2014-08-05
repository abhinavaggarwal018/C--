#include<abhinav.h>

int main()
{
	int arr[100][100];
	string str1,str2;
	
	cin>>str1;
	cin>>str2;
	
	int m=str1.length();
	int n=str2.length();
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=0;
		
	int flag=0;	
	for(int i=0;i<m;i++)
	{
		if(str1[i]==str2[0])
			flag=1;
		
		arr[i][0]=flag;	
	}
	
	for(int j=0;j<n;j++)
	{
		if(str1[0]==str2[j])
			flag=1;
		
		arr[0][j]=flag;	
	}
	
	for(int i=1;i<m;i++)
		for(int j=1;j<n;j++)
		{
			if(str1[i]==str2[j])
				arr[i][j]=max(arr[i-1][j-1]+1,max(arr[i-1][j],arr[i][j-1]));
			
			else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
		}
		
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
