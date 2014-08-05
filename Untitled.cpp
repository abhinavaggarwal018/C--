#include<iostream>
#include<cassert>

using namespace std;

#define set(x)  (arr[x>>6]|=(1<<((x>>1)&31)))
#define test(x)	(arr[x>>6]&(1<<((x>>1)&31)))

int arr[1],x;

int main()
{
	while(1)
	{
		cout<<arr[0]<<"\n";
		cin>>x;
		cout<<"\n";
		cout<<test(x);
		set(x);
	}
}


