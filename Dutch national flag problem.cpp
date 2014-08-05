#include<iostream>

using namespace std;

int main()
{
	int n;
//	int arr[100];
/*	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
*/

	n=12;
	int arr[]={0,1,1,0,1, 2, 1, 2, 0, 0, 0, 1}	;
	int start=0,mid=0,end=n-1,ind=0;
	
	while(mid<=end)
	{
		if(arr[mid]==0)
		{
			arr[mid]=arr[start];
			arr[start]=0;
				
			start++;
			mid++;
		}
		
		if(arr[mid]==1)
			mid++;
			
		if(arr[mid]==2)
		{
			arr[mid]=arr[end];
			arr[end]=2;
			
			end--;
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<arr[i];
	
}
