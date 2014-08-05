#include<iostream>

int add(int a,int b)
{
	return a+b;
}

int func(int a,int b,int (*function(int ,int)))
{
	return (*function(a,b));
}

int main()
{
	int (*func12)(int,int)=add;
//	*func2=add;
	std::cout<<(2,3,func12);
}
