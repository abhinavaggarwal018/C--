#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	char str[105];

	while(scanf("%s",&str)>0)
	{
		int flag=0,flag1=0;;
		int	n=strlen(str);
		for(int i=0;i<n;i++)
		if(str[i]!=tolower(str[i]))
		flag1=1;
		if(str[0]!=tolower(str[0]))
		cout<<"Error!";
		else if(str[0]=='_')
		cout<<"Error!";
		else if(str[n-1]=='_')
		cout<<"Error!";
		else
		{
			
			if(flag1==0)
			{
				for(int i=0;i<n;i++)
				{
					if(str[i]=='_')
					continue;
					if(str[i-1]!='_')
					cout<<str[i];
					else
					cout<<char(str[i]+'A'-'a');
				}
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(str[i]=='_')
					{
						flag=1;
						break;
					}
				}
				
				if(flag==1)
				cout<<"Error!";
				else
				{
					for(int i=0;i<n;i++)
					if(str[i]==tolower(str[i]))
						cout<<str[i];
					else
						cout<<"_"<<char(tolower(str[i]));
				}
				
			}
		}
		cout<<"\n";
		
	}
}
