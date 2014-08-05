#include<iostream>

using namespace std;

int pow(int a,int b, int &ans)
{
	if(b==0)
		return ans;
		
	if(b%2==0)
	{
		ans=ans*ans;
		b=b/2;
		return pow(a,b,ans);
	}
	
	if(b%2==1)
	{
		ans=ans*ans*a;
		b=b/2;
		return pow(a,b,ans);
	}
}

int main()
{
	int ans=1;
	pow(2,4,ans);
	
	cout<<ans;
}
