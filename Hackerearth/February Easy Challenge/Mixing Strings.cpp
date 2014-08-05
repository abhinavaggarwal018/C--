#include<iostream>
#include<cstdio>

using namespace std;

int len=1000,n,vis[20];
string str[20];

string find_match1(string str1,int i)
{
	int j=0;
	string stra=str[i];
	for(int i=str1.length()-1;i>=0;i--)
	{	
		if(stra[j]=='\0')
			return str1;
			
		if(stra[i]==str1[j])
			j++;
			
		if(stra[i]!=str1[j])
			break;
	}

	for(int j=0;j<=str1.length();j++)	
		stra=stra+str1[j];
		
	return stra;
}

int dfs(string str1)
{
//	cout<<str1<<"\n";
	bool flag=false;
	
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{

			string str2= string(str1);

			vis[i]=true;
	
			flag=true;
	
			dfs(find_match1(str2,i));
			
			vis[i]=false;
		}
	}
	
	if(!flag)
		if(len>str2.length())
			len=str2.length();
			
}

int main()
{
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		vis[i]=false;
	
	for(int i=0;i<n;i++)
		cin>>str[i];
		
	dfs("");
		
	cout<<len-1<<"\n";
}
