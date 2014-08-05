#include<iostream>

using namespace std;

struct interval
{
	int first;
	int second;
}arr[1000];

int n;
 
void quick_sort(int start,int end)
{
	if(start>=end)
		return;
		
	if(start==end-1)
	{
		if(arr[start].first > arr[end].first)
		{
			swap(arr[start].first,arr[end].first);
			swap(arr[start].second,arr[end].second);
		}
	}
	
	int pivot=start;
	
	int a=start,b=end;
	while(a<b)
	{
		while(arr[pivot].first >= arr[a].first)
			a++;
		while(arr[pivot].first<arr[b].first)
			b--;
		if(a<b)
		{
			swap(arr[a].first,arr[b].first);
			swap(arr[a].second,arr[b].second);
		}
	}
	pivot=b;
	
	swap(arr[pivot].first,arr[start].first);
	swap(arr[pivot].second,arr[start].second);
	
	cout<<arr[pivot].first<<"\n";
	for(int i=0;i<n;i++)
		cout<<arr[i].first<<" ";
	cout<<"\n";
	quick_sort(start,pivot-1);
	quick_sort(pivot+1,end);
	
} 

int main()
{

	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i].first>>arr[i].second;
		
		quick_sort(0,n-1);
			
		for(int i=0;i<n;i++)
			cout<<arr[i].first<<"  "<<arr[i].second<<"\n";
		
		int lis[100]={1};
		int temp=1;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[j].second<arr[i].first&&(1+lis[j])>lis[i])
					lis[i]=1+lis[j];
			}
			temp=max(temp,lis[i]);
		}
		
		cout<<temp;	
	}
	
}
