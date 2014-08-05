#include<iostream>

using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
		
	else
		return gcd(b,a%b);
}

int main()
{
	
	int a,t;
	string b;
	
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		
		if(a==0)
		{
			cout<<b<<"\n";
			continue;
		}
		
		int i=1;
		int temp=b[0]-'0';
		
		while(i<b.length())
		{
			temp=(temp*10 + b[i]-'0')%a;
			i++;
		}
		
		
		cout<< gcd(a,temp)<<"\n";
	}
	
	return 0;
}
