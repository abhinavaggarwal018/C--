#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string str;

int main()
{
	while(1)
	{
		cin>>str;
		int len=str.length(),len1=int(double(log(len-1))/double(log(3))),len2=int(double(log(len-len1-1))/double(log(3)));

		
		
		cout<<str;
	}
}
