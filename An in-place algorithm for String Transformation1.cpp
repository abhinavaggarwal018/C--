#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

//	string str="e1r2t3y4u5i6o7p8l9k1j2h3g4f5d6s7a8z9x1c2v3b4n5m6l7f8s9";
	string str ="a1b2c3d4e5f6g7"; 

void run_script(int start,int len)
{
	int ind1=-100,ind2=-100,shift;
	char prev=str[start];
	if(start>len)
		shift=start-len;
	else
		shift=start;
	
	while(ind1!=start)
	{
	
		if(ind1==-100)
			ind1=shift;
		
		cout<<ind1<<"\t"<<prev;
		
		if(ind1%2==0)
			ind2=ind1/2;
		else
			ind2=len/2+ind1/2;
		
		char curr=str[shift+ind2];
		str[shift+ind2]=prev;
		prev=curr;
		
		cout<<"\t"<<ind2<<"\t"<<curr<<"\n";
		ind1=ind2;
		getchar();
	}
	//str[start]=prev;
}
int main()
{

	int temp,len[15],len_max,len_remain=100;;
	while(1)
	{
		//cin>>str;
		
		len[0]=str.length();
		len_remain=len[0];
		len[1]=pow(3,int(double(log(len_remain-1))/double(log(3))))+1;
		len_remain-=len[1];
		cout<<len[0]<<"\n";
		int i=1;
		while(len[i]!=1)
		{
			cout<<len[i]<<"\n";
			len[++i]=pow(3,int(double(log(len_remain-1))/double(log(3))))+1;
			len_remain=len_remain-len[i];
		}
		len_max=i;
		cout<<len_max;
		temp=0;
		for(int i=1;i<len_max;i++)
		{
			for(int k=0;temp+pow(3,k)<len[i];k++)
			{
				run_script(temp+pow(3,k),len[i]);
			}
			cout<<str<<"\n";
			temp+=len[i];
		}
		cout<<str;
		
		
	}
}
