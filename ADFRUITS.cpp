#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;
char arr1[105],arr2[105],subseq[105];
int len1,len2,arr[105][105]={INT_MAX};
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

void lcs()
{
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
			{
				if(arr1[i-1]==arr2[j-1])
					arr[i][j]=arr[i-1][j-1]+1;
				else
					arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
			}
		/*for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}*/

	int count=0;
	int i=len1;
	int j=len2;
		while(i>0 && j>0)
					{
		//				cout<<"i: "<<i<<"j: "<<j;
						if(arr1[i-1]==arr2[j-1])
					//	cout<<"\nSubseq: "<<arr1[i-1]<<" and "<<arr2[j-1]<<count;
						{
		//					cout<<"arr1["<<i<<"-1]: "<<arr1[i-1]<<"arr2["<<j<<"-1]: "<<arr2[j-1];
							subseq[arr[i][j]-1]=arr1[i-1];
							i--;
							j--;
						}
						else if (arr[i][j]==arr[i-1][j])
							i--;
						else if (arr[i][j]==arr[i][j-1])
							j--;
						
					}
}

void namefruits()
{
	int i=0,start1=0,start2=0;
	lcs();
	while(subseq[i]!='\0' || arr1[start1]!='\0' || arr2[start2]!='\0')
	{
	//	cout<<subseq[i]<<" "<<start1<<" "<<start2; 
		if(arr1[start1]!=subseq[i])
		start1=printstr1(start1,subseq[i]);
		if(arr2[start2]!=subseq[i])
		start2=printstr2(start2,subseq[i]);
		else if(arr2[start2]==subseq[i] && arr1[start1]==subseq[i])
		{
			cout<<arr2[start2];
			start1++;
			start2++;
			i++;
		}	
	}
}
int main()
{
	for(int i=0;i<105;i++)
	{
		arr[i][0]=0;
		arr[0][i]=0;
	}

	cin>>arr1;
	cin>>arr2;
//	printstr1(0,'a');
//	printstr2(0,'p');
//	int a;
//	cin>>a;
	//cout<<arr1;
	//cout<<arr2;
	len1=strlen(arr1);
	len2=strlen(arr2);
	namefruits();
//	cout<<arr[len1][len2];
	/*for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{ 
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	//cout<<subseq;
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

