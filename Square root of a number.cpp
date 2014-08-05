#include<iostream>

using namespace std;

int main()
{
	double n,ans,start=0,end;
	cin>>n;
	
	end=n;
	
	int t=200;
	
	if(n==0)
		cout<<0;
	
	else if(n==1)
		cout<<1;
	
	else
		while(t--)
		{
			ans=start+(end-start)/2;
			
			if(ans*ans==n)
				break;
			
			if(ans*ans < n)
				start=ans;
				
			else
				end=ans;	
		}
	
	cout.precision(15);
	cout<<ans;
}
