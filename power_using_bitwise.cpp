#include<iostream>
#include<stdio.h>
int main()
{
	using namespace std;
	int a,b,prod=1;
	// we calculate a^b using bitwise and binary representation
	cin>>a>>b;
	while(b>0)
	{
		cout<<"1&b"<<(1&b)<<"b&1"<<(b&1)<<endl;
		if((1&b)==1)
		{
			cout<<"354"<<endl;
			prod=prod*a;
		}
	//	else
		a=a+a;
		prod=prod<<1;
		cout<<"1212"<<endl;
		b=b>>1;
		cout<<"b:"<<b<<endl;
	}
	//cout<<4;
	cout<<prod;
}
