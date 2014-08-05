#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

struct abc
{
	long long int a,b,c;
}arr[100005];

bool compare(abc a1,abc b1)
{
	if(a1.a!=b1.a)
		return a1.a<b1.a;
	
	if(a1.b!=b1.b)
		return a1.b<b1.b;
		
	return a1.c<=b1.c;
}

int main()
{
	int t,n;

//	scanf("%d",&t)
	t=1;	
	while(t--)
	{
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("%lld %lld %lld",&arr[i].a,&arr[i].b,&arr[i].c);
		
		for(int i=0;i<n;i++)
		{
			long long int minm=min(min(arr[i].a,arr[i].b),arr[i].c);
			long long int maxm=max(max(arr[i].a,arr[i].b),arr[i].c);
			long long int mid=arr[i].a-minm+arr[i].b-maxm+arr[i].c;
			
			arr[i].a=minm;
			arr[i].b=mid;
			arr[i].c=maxm;
		}
		
			
		std::sort(arr,arr+n,compare);
		
		int cnt=0;
		
		for(int i=1;i<n;i++)
		{
			
			if(i<n-1 && (arr[i].a!=arr[i-1].a &&  arr[i].a!=arr[i+1].a )||( arr[i].b!=arr[i-1].b && arr[i].b!=arr[i+1].b )|| (arr[i].c!=arr[i-1].c && arr[i].c!=arr[i+1].c ))
				cnt++;
			else if(i==n-1 && (arr[i].a!=arr[i-1].a||arr[i].b!=arr[i-1].b||arr[i].c!=arr[i-1].c))
				cnt++;
		}
		
		printf("%d",cnt);
	}
}
