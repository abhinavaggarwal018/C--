#include<iostream>

using namespace std;

int data[100];

void display(int arr[],int ind, int r, int n)
{
	if(ind==r)
	{
		for(int i=0;i<r;i++)
			cout<<data[i];
		cout<<"\n";
		return;
	}
	for(int i=ind;i<ind+r;i++)
	{
		data[ind]=arr[i];
//		swap(arr[ind],arr[i]);
		display(arr,ind+1,r,n);
//		swap(arr[ind],arr[i]);*/
	}
}

int main()
{
	int r=3;
	int arr[]={1,2,3,4,5};
	int n=5;
	
	display(arr,0,r,n);
}
