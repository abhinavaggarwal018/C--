#include<iostream>
int main()
{
	long long int fib[100000]={0};
	fib[0]=0;
	fib[1]=1;
	fib[2]=1;
	for(int i=2;i<99;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(int i=fib[92];i<fib[92]+fib[2];i++)
	std::cout<<i<<"th fibonacci number fib["<<i<<"] is"<<i<<"\n";
	int a;
	std::cin>>a;
}
