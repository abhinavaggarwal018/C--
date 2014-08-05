#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int find_lcs_recursive(string str1,string str2,int start1, int start2,int len1,int len2)
{
	if(start1==len1||start2==len2)
		return 0;
	int ans=0;
	for(int i=start1;i<len1;i++)
	{
		for(int j=start2;j<len2;j++)
		{
			if(str1[i]==str2[j])
				ans=max(ans,find_lcs_recursive(str1,str2,i+1,j+1,len1,len2)+1)	;
		}
	}
	
	return ans;
}

int lcs_dp(string str1,string str2)
{
	int len1=str1.length();
	int len2=str2.length();
	
	cout<<len1<<len2;

	vector<vector<int> > arr(len1,vector<int>(len2));
	vector<int>::iterator it;
	
	if(str1[0]==str2[0])
		arr[0][0]=1;
	else
		arr[0][0]=0;

	for(int i=1;i<len1;i++)
		if(str1[i]==str2[0])
			arr[0][i]=1;
		else
			arr[0][i]=arr[0][i-1];

	for(int j=1;j<len2;j++)
		if(str1[0]==str2[j])
			arr[j][0]=1;
		else
			arr[j][0]=arr[j-1][0];
			
	for(int j=1;j<len1;j++)
		for(int i=1;i<len2;i++)
			if(str1[i]==str2[j])
				arr[i][j]=arr[i-1][j-1]+1;
			else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);

	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
			cout<<arr[j][i]<<" ";
		cout<<"\n";
	}
	cout<<"jsadjsak";
	int temp=arr[len2-1][len1-1];
	cout<<"AAAAAAAAA";

/*
	int **arr=new int * [len1];
	for(int i=1;i<len2;i++)
		arr[i] = new int[len1];

	if(str1[0]==str2[0])
		arr[0][0]=1;
	else
		arr[0][0]=0;

	for(int i=1;i<len1;i++)
		if(str1[i]==str2[0])
			arr[0][i]=1;
		else
			arr[0][i]=arr[0][i-1];

	for(int j=1;j<len2;j++)
		if(str1[0]==str2[j])
			arr[j][0]=1;
		else
			arr[j][0]=arr[j-1][0];
			
	for(int j=1;j<len1;j++)
		for(int i=1;i<len2;i++)
			if(str1[i]==str2[j])
				arr[i][j]=arr[i-1][j-1]+1;
			else
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);

	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
			cout<<arr[j][i]<<" ";
		cout<<"\n";
	}
	cout<<"jsadjsak";
	int temp=arr[len2-1][len1-1];
	cout<<"AAAAAAAAA";
	
	delete arr;
*/	
	return temp;
}
/*
	a	b	c	d	e
b	0   1	1	1	1
c	0    
a	t
e	1
*/

int main()
{
	string str1,str2;
	while(1)
	{
		cin>>str1;
		cin>>str2;
		
		//cout<<find_lcs_recursive(str1,str2,0,0,str1.length(),str2.length());
		
		cout<<lcs_dp(str1,str2);
	}
}
