#include<iostream>

using namespace std;

int temp[100];
int len=0;
void recur(int arr[],int start, int n,int k)
{
	if(len==k)
	{
		for(int i=0;i<k;i++)
			cout<<temp[i]<<" ";
		cout<<"\n";
		
		return;
	}
	
	for(int i=start;i<n;i++)
	{
		temp[len]=arr[i];
		len++;
		
		recur(arr,i+1,n,k);
		len--;
	}
}

int main()
{
	int n,arr[100],k;
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cin>>k;
	
	recur(arr,0,n,k);
	

}
