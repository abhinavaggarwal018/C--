#include<iostream>
#include<string>
#include<vector>

using namespace std;

int edit_dist(string str1,string str2)
{
	int n=str1.length();
	int m=str2.length();
	
	vector<	vector<int> > arr((n),vector<int> (m)); // n rows m columns
	
	if(str1[0]==str2[0])
		arr[0][0]=0;
	else
		arr[0][0]=1;
	
	for(int i=1;i<n;i++)
		arr[i][0]=1+arr[i-1][0];
	
	for(int j=1;j<m;j++)
		arr[0][j]=1+arr[0][j-1];
		
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(str2[j]==str1[i])
				arr[i][j]=arr[i-1][j-1];
			else
				arr[i][j]=(min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1])+1);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	return arr[n-1][m-1];
}

int main()
{
	string str1,str2;
	
	while(1)
	{
		cin>>str1>>str2;
		cout<<edit_dist(str1,str2);
	}
}
