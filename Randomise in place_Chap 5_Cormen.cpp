#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int main()
{
	int arr[50],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n-1;i++)
		swap(arr[i],arr[(rand()%(n-i))+i]);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" " ;
}

