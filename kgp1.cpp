#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>

using namespace std;
int  arr1[105],arr2[105];
int len1,len2,arr[105][105];
void lcs_new()
{
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++)
			{
					//cout<<"Here";
					if(arr1[i-1]!=arr2[j-1])
					arr[i][j]=min(min(arr[i-1][j-1],arr[i][j-1]),arr[i-1][j])+1;
					else
					arr[i][j]=arr[i-1][j-1];
			}
}

int main()
{
	for(int i=0;i<105;i++)
	{
		arr[i][0]=i;
		arr[0][i]=i;
	}
	int l,t;
	cin>>t;
	for(l=0;l<t;l++)
	{
		
		scanf("%d",&len1);
		
		for(int i=0;i<len1;i++)
			scanf("%d",&arr1[i]);

		scanf("%d",&len2);
		
		for(int i=0;i<len2;i++)
			scanf("%d",&arr2[i]);
		
		lcs_new();
/*		for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{ 
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		printf("%d\n",arr[len1][len2]);
	}
}


