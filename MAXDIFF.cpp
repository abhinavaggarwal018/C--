#include<iostream>
#include<stdlib.h>
using namespace std;
int t,n,k,pivot,temp,arr[100005],sum_child,sum_father;
int a;
void quicksort(int start,int end)
{
//	cout<<"Start: "<<start<<"End: "<<end<<"\n";
	if(start>=end)
	return;
	
	pivot=start;
//	cout<<"Pivot: "<<pivot<<"Value: "<<arr[pivot]<<"\n"; 
	for(int i=start;i<=end;i++)
	{
		if(arr[i]<arr[pivot])
		{
			temp=arr[i];
			arr[i]=arr[pivot+1];
			arr[pivot+1]=arr[pivot];
			arr[pivot]=temp;
			pivot++;
		}
/*		for(int j=0;j<n;j++)
		cout<<arr[j]<<"\t";
		cout<<"\n";*/
	}
//	cin>>a;
	quicksort(start,pivot-1);
	quicksort(pivot+1,end);
}
//3 5 8 2 5 7 1 9 4 2 7 3


//0 1 2 3 4 5 6 7 8 9 10 11
int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		
		sum_child=0,sum_father=0;
		cin>>n>>k;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		quicksort(0,n-1);
		
		for(int i=0;i<k;i++)
			sum_child+=arr[i];
		
		for(int i=k;i<n;i++)
			sum_father+=arr[i];
		
		cout<<sum_father-sum_child<<"\n";
	}
}
