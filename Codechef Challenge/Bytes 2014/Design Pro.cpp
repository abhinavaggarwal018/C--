#include<iostream>
#include<cassert>

using namespace std;

int main()
{
	long long int t,n,sum;
	
	cin>>t;

	if(t>1000)
		assert(0);

	while(t--)
	{
		cin>>n;
		if(n>1000000)
			assert(0);
		
		sum+=n;
	}
	
	if(sum>300000000)
		assert(0);
}
