#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

void fill_lps(int lps[],int m, int n,char patt[])
{
	int len=0,i=1;

	lps[0]=0;
	
	while(i<n)
	{
		if(patt[len]==patt[i])
		{
			len++;
			lps[i]=len;
			i++;
		}
		
		else
		{
			if(len!=0)
				len--;
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	
}

void match_pattern(char str[],char patt[],int m,int n)
{
	int *lps = new int[n];
	fill_lps(lps,m,n,patt);
	
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
	
	cout<<"\n";	
	int i=0,j=0;
	
	while(i<m)
	{
		if(patt[j]==str[i])
		{
			i++;
			j++;
		}
		
		if(j==n-1)
		{
			cout<<i-j<<" is in the pattern\n";
			j=lps[j-1];
		}
		
		else if(patt[j]!=str[i])
		{
			if(j>0)
			{
				j=lps[j-1];
			}
			else
				i++;
		}
	}
		
	delete lps;
}

int main()
{
	while(1)
	{
		
		char str[]="AABAACAADAABAAABAA";
		char patt[100]="AABA";
		//cin>>patt;
		int m=strlen(str);
		int n=strlen(patt);
		match_pattern(str,patt,m,n);
		getchar();
	}
}
