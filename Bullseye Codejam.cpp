#include<iostream>
using namespace std;
long long int testcases,t,r;
int main()
{
	cin>>testcases;
	for(int l=0;l<testcases;l++)
	{
		cin>>r>>t;
		int ans=0;
		for(int i=r+1; ;i=i+2)
		{

			//cout<<t<<"\t";
			t=t-((i*i)-((i-1)*(i-1)));
			//cout<<t<<"\n";
			if(t<0)
			break;
			ans++;
		}
		cout<<"Case #"<<l+1<<": "<<ans<<"\n";
	}
}
