#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>

using namespace std;

string in[11],out[11];
int n,l,t,ans;

void flip(int pos)
{
	for(int i=0;i<n;i++)
	{
		if(in[i][pos]=='1')
			in[i][pos]='0';
		else
			in[i][pos]='1';
	}
}

void func(int ind, int swap)
{
	if(ind==n)
	{
		std::sort(in,in+n);
		
		bool flag=true;
		
		for(int i=0;i<n;i++)
		{
			if(in[i]!=out[i])
				flag=false;		
		}
		
		if(flag)	
			ans=min(ans,swap);
	
		return;
	}
	
	func(ind+1,swap);
	flip(ind);
	func(ind+1,swap+1);
	flip(ind);
}


int main()
{

//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);

	cin>>t;
	
		
	for(int i1=1;i1<=t;i1++)
	{
		cin>>n>>l;
		
		ans=10000;
		
		for(int i=0;i<n;i++)
			cin>>in[i];
			
		for(int i=0;i<n;i++)
			cin>>out[i];
			
		sort(out,out+n);

		func(0,0);
		
		if(ans!=10000)
			cout<<"Case #"<<i1<<": "<<ans<<"\n";
		else
			cout<<"Case #"<<i1<<": NOT POSSIBLE\n";	
	}
}
