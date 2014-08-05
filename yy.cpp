#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int a=1,b=2,c;

	while(1)
	{
		c=a+b;
		b=a;
		
		getch();
		
		cout<<c<<" "<<b<<"\n";
	}

	return 0;
}
