#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;
#define MOD 1000000007

int main()
{
	ofstream input,output;
  	input.open ("input.txt");
  	output.open ("output.txt");

	long long int n,k,val;
	int num=1000000;
	
	for(int i=1;i<=500;i++)
	{
			k=rand();
			k=k-((k/num)*num);
			input<<k<<"\n";
			n=2*k;
			val=1;	
			val=n;
			for(int r=1;r<k;r++)
			{
				val=((val*(n-r))/(r+1));
				val=val-MOD*(val/MOD);
			}
			
			output<<val<<"\n";
			num++;
	}
	return 0;
}
