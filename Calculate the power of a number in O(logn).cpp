#include<iostream>

using namespace std;
int ans;
long long int power(int a,int b)
{
	if(b==0)
		return 1;
	
	ans=power(a,b/2);
	
	if(b%2==0)
		ans=ans*ans;
	
	else
		ans=ans*ans*a;
		
	b=b/2;
	
	cout<<b<<":"<<ans<<"\n";
	
	return ans;

}

int main()
{
	long long int n,ans,a,b;
	cin>>a>>b;
	int i=3;
int p1=*(int*)i; 
int p2=*(int*)&i;
	cout<<&p1<<&p2;
i=4;  
	cout<<p1<<p2;
	//cout<<power(a,b);
	
}
