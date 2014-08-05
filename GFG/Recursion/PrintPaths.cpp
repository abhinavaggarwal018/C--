#include<iostream>
using namespace std;

void recur(int n, int m, string str)
{
	if(n==0&&m==0)
		cout<<str<<"\n";
		
	if(n>0)
		recur(n-1,m,str+'U');
		
	if(m>0)
		recur(n,m-1,str+'R');
}	

int main()
{
	int n,m;
	cin>>n>>m;
	recur(n,m,"");
}
