// Let's say you have a list of N+1 integers between 1 and N. 
//You know there's at least one duplicate, but there might be more. 
//For example, if N=3, your list might be 3, 1, 1, 3 or it might be 1, 3, 2, 2. 
//Print out a number that appears in the list more than once. 
//(That is, in the first example, you can print '1' or '3' -- you don't have to print both.)

#include<iostream>
#include<cstdio>
using namespace std;

int bSearch(int l, int h, int arr[])
{
	if(l>h)
		return -1;
		
	if(l==h)
		return arr[l];
		
//	int mid=h-(h-l)/2; 	
	int i,val=h-(h-l)/2,cnt=0;
		
	for(i=l;i<=h;i++)
	{
		if(arr[i]<=val)
			cnt++;
	}
	
	cout<<l<<":"<<h<<":"<<cnt<<":"<<val<<"\n";
	
	if(cnt>=val)
		return bSearch(val+1,h,arr);
	return bSearch(l,val-1,arr);
}

int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[100005];
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		cout<<bSearch(0,n-1,arr);
	}
	
}
