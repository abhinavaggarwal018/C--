/*	
Find the Missing Number
June 22, 2009

You are given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in list. 
One of the integers is missing in the list. 
Write an efficient code to find the missing integer.

*/

#include<iostream>

using namespace std;

int main()
{
	int ans=0,n,num;
	cin>>n;
	
	for(int i=0;i<=n;i++)
		ans=ans^i;
		
	for(int i=0;i<n;i++)
	{
		cin>>num;
		ans=ans^num;
	}
	
	cout<<ans;
}
