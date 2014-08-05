#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int count1[26];
int main()
{
	char str[1000];
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	str[i]=tolower(str[i]);
	cout<<str;
	for(int i=0;str[i]!='\0';i++)	
	{
		for(int j=0;j<26;j++)
		if(str[i]==char('a'+j))
		count1[j]++;
	}
	for(int i=0;i<26;i++)
	{
		cout<<char('a'+i)<<":"<<count1[i]<<"\n";
	}
}
