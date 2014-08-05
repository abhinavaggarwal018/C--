#include<iostream>
#include<stack>

using namespace std;

int n,arr[100];

struct node{
	int start;
	int end;
	
	node(int a, int b)
	{
		start=a;
		end=b;
	}
};

stack<node> s;

void quick_sort()
{
	while(!s.empty())
	{
		struct node node1=s.top();
		s.pop();
		int start=node1.start;
		int end=node1.end;
		
		int pivot=arr[start];
		int low=start,high=end;
		
		while(low<high)
		{
			while(pivot>=arr[low]&& low<=high)
				low++;
			
			while(pivot<arr[high]&&high>=low)
				high--;
				
			if(low<high)
			{
				int temp=arr[low];
				arr[low]=arr[high];
				arr[high]=temp;
			}
		}
		
		cout<<"Pivot: "<<pivot<<"\n";
		cout<<"Low: "<<low<<" and High: "<<high<<"\n";
		
		arr[start]=arr[high];
		arr[high]=pivot;
		
		for(int p=0;p<n;p++)
			cout<<arr[p]<<" ";
		cout<<"\n";
		
		if(start<high-1)
			s.push(node(start,high-1));
		
		if(high+1<end)
			s.push(node(high+1,end));
	}
}

int main()
{
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		s.push(node(0,n-1));
		
		quick_sort();
	}
}
