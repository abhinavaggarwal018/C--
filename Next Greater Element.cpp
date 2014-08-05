/*
	
Next Greater Element
March 17, 2011

Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
*/
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n,*arr,*ans;
	while(1)
	{
		cin>>n;
		
		arr=new int[n];
		ans= new int[n];
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		int val;
		stack<int> mystack;
		for(int i=n-1;i>=0;i--)
		{
			while(!mystack.empty())
			{
				val=mystack.top();
		
				if(val>arr[i])
				{
					ans[i]=val;
					break;
				}
				else
					mystack.pop();
			}
			if(mystack.empty())
				ans[i]=-1;
			mystack.push(arr[i]);
		
		}
		
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		
		cout<<"\n";
		delete arr;
	}
}
