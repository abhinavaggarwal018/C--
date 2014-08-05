#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int n,cnt;
	scanf("%d",&n);
	vector<int> arr(n+10);
	
	cnt=0;
			
	for(int i=1;i<=sqrt(n);i+=1)
	{
		for(int j=1;j<=n;j+=i)
			++cnt;
	}
	
	cout<<cnt;
	
}
