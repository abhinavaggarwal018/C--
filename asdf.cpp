#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;
char arr1[3005],arr2[3005];
int len1,len2,arr[3005][3005]={INT_MAX};
int printstr1(int start,char c)
{
	int i;
	for(i=start;arr1[i]!=c;i++)
	cout<<arr1[i];
//	cout<<" "<<i ;
	return i;
}

int printstr2(int start,char c)
{
	int i;
	for(i=start;arr2[i]!=c;i++)
	cout<<arr2[i];
//	cout<<" "<<i; ;
	return i;
}

void lcs_new()
{
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
			{
					//cout<<"Here";
					arr[i][j]=min(min(arr[i-1][j-1],arr[i][j-1]),arr[i-1][j])+1;
			}
}

int main()
{
	for(int i=0;i<3005;i++)
	{
		arr[i][0]=0;
		arr[0][i]=0;
	}
	int l,t;
	cin>>t;
	for(l=0;l<t;l++)
	{
		cin>>arr1;
		cin>>arr2;
		len1=strlen(arr1);
		len2=strlen(arr2);
		lcs_new();
	/*	for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{ 
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		cout<<arr[len1][len2]<<"\n";
	}
}
/*
	a n a n a s
  0 0 0 0 0 0 0
b 0	0 0 0 0 0 0
a 0	1 1 1 1 1 1
n 0	1 2 2 2 2 2
a 0	1 1
n 0
a 0
*/

