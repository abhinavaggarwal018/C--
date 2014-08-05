#include<iostream>

using namespace std;

int main()
{
	string arr="2222221111111112222212121212121111122200111222";
	int n=arr.length();
	
	n=n-1;
	
	int start=0, mid=0, high=n; // indices which are to be changed
	while(mid<high)
	{
		if(arr[mid]=='0')
		{
			arr[mid]=arr[start];
			arr[start]='0';
			start++;
			mid++;
		}
		
		if(arr[mid]=='1')
			mid++;
			
		if(arr[mid]=='2')
		{
			arr[mid]=arr[high];
			arr[high]='2';
			high--;
		}
	}
	
	cout<<arr;
}
