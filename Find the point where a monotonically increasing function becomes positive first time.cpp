#include<iostream>

using namespace std;

int f(int x) 
{ 
	return (x*x - 10*x - 20); 
}

int b_search(int low, int high)
{
	if(low>=high)
		return low;
		
	int mid=low+(high-low)/2;
	if(f(mid)==0)
		return mid;
	else if(f(mid)>0)
		return b_search(low,mid);
	else
		return b_search(mid+1,high);
}

int main()
{
	int high=1;
	while(f(high)<0)
		high=high*2;
	
	cout<<b_search(high/2,high);
}
