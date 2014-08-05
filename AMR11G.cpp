#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,flag;
	char str[100];
	cin>>t;
	while(t--)
	{
			flag=0;
			cin>>str;
			for(i=0;str[i]!='\0';i++)
			if(str[i]=='D')
				flag=1;
			if(flag==1)
			cout<<"You shall not pass!\n";
			else
			cout<<"Possible\n";
	}
		return 0;
}
	

