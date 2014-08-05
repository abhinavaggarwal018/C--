#include<abhinav.h>
#include<ctime>

using namespace std;

void partition(int arr[],int l, int n,int k)
{

	srand(time(NULL));
	int pivot_ind=(rand()%324+32112)%(n-l);
	
	int temp=arr[l];
	arr[l]=arr[pivot_ind];
	arr[pivot_ind]=temp;
	pivot_ind=l;
	int start=l+1,end=n;
	
	while(start<end)
	{
		if(arr[start]<=arr[pivot_ind])
			start++;
			
		if(arr[start]>arr[pivot_ind])
		{
			int temp=arr[end];
			arr[end]=arr[start];
			arr[start]=temp;
			end--;
		}
		
		for(int i=0;i<16;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
		
	}
	
	for(int i=0;i<16;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	
	temp=arr[pivot_ind];
	
		arr[pivot_ind]=arr[end];
		arr[end]=temp;
		pivot_ind=end;
	
/*	else
	{
		arr[pivot_ind]=arr[start+1];
		arr[start+1]=temp;
		pivot_ind=start+1;
	}
*/	
	cout<<arr[pivot_ind]<<":"<<pivot_ind<<"\n";
	
	for(int i=0;i<16;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	getchar();		
	if(pivot_ind==k-1||pivot_ind==k)
		return;
	if(pivot_ind<k-1)
		return partition(arr,pivot_ind,n,k-pivot_ind-1);
	if(pivot_ind>k)
		return partition(arr,0,pivot_ind,k);
		

}

int main()
{
	int n,k;
	/*
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	*/
	
	n=15;
	int arr[]={5,3,8,1,2,6,7,19,8,42,23,98,5,12,17,27};
	k=7;
	n=sizeof(arr)/sizeof(arr[0]);
	partition(arr,0,n-1,k);
	
	for(int i=0;i<k;i++)
		cout<<arr[i]<<" ";
}
