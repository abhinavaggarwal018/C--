#include<iostream>

using namespace std;

int main()
{
	long long int n=100,k=95,val;
	k=min(k,n-k);
	if(n>k)
	{
		val=n; // nC1=n;
		for(int r=1;r<k;r++)
		{
			val=(val*(n-r))/(r+1);
		}
		
		cout<<val;
	}
	
	else
		cout<<0;
	
	return 0;
}
