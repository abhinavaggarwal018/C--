#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,c,arr[500],ans;
	
	scanf("%d %d",&n,&c);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	ans=0;
	for(int i=0;i<n-1;i++)
		ans=max(ans,arr[i]-arr[i+1]-c);
		
	printf("%d\n",max(ans,0));
} 
