/* Fibonacci Number using memoization
*/
#include<iostream>

using namespace std;
long long int n, arr[1000];


int fib(int n)
{
	if(arr[n]!=0)
		return arr[n];

	arr[n]=fib(n-1)+fib(n-2);
	return arr[n];
}

int main()
{
	arr[0]=1;arr[1]=1;
	while(1)
	{
		cin>>n;
		cout<<fib(n);
	}
}
