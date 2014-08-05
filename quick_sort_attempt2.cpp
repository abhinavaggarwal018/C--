#include<iostream>
#include<cstdio>

using namespace std;
int n;
int partition(int arr[],int start,int end)
{
	int val=arr[start],start1=start;
	cout<<"pivot:"<<val<<"\n";
	
		cout<<"Partition:"<<start<<" "<<end<<"\n";
		getchar();

		while(start<=end-1)
		{
			while(arr[start]<=val)
				start++;
				
			while(arr[end]>val)
				end--;
				
			if(start<end)
			{
				int temp=arr[start];
				arr[start]=arr[end];
				arr[end]=temp;
				start++;
				end--;
			}
		}
	
		arr[start1]=arr[end];
		arr[end]=val;
	for(int i=0;i<n;i++)
		cout<<arr[i];
		
	return end;
}


void q_sort(int arr[],int start,int end)
{
	cout<<"void q_sort(int arr[],int start,int end)\n"<<start<<" "<<end<<"\n";
	if(start>=end)
		return;
		
	int index=partition(arr,start,end);
	cout<<"index:"<<index<<"\n";
	
	q_sort(arr,start,index-1);
	q_sort(arr,index+1,end);
}

int main()
{
	int arr[1000];
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		q_sort(arr,0,n-1);
		
		for(int i=0;i<n;i++)
			cout<<arr[i];
	}
}
