#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	b=a<<1;
//obtaining product by left shift operator
	cout<< b <<endl;// multiply by 2
	b=a<<1;
	b=b+a;
	cout<< b <<endl;// multiply by 3
	b=a<<2;
	cout<<b<<endl;// multiply by 4
	b=a<<2;
	b=b+a;
	cout<<b<<endl;// multiply by 5
	b=(a<<2);
	b=b+(a<<1);
	cout<<b<<endl;// multiply by 6
	b=(a<<2);
	b=b+(a<<1);
	b=b+a;
	cout<<b<<endl;// multiply by 7
	b=a<<3;;
	cout<<b<<endl;// multiply by 8
	b=a<<3;
	b=b+a;
	cout<<b<<endl;// multiply by 9
}
