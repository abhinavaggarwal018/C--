#include<iostream>
#include<cstdio>

using namespace std;

int n;

void juggling(int arr[],int n,int d)
{
	int i1,temp;
	
	for(int i=0;i<d;i++)
		{
			temp=arr[i];
			i1=i;
			
			while((d+i1)<n)
			{
				arr[i1]=arr[d+i1];
				i1=i1+d;
			}
			
			arr[i1]=temp;
		}
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
}

void reverse(int arr[],int start,int end)
{
	if(start>=end)
		return;
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	return reverse(arr,start+1,end-1);
}

void reverse_algo(int arr[],int n,int d)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
	
	for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
}

void block_swap(int arr[],int start1,int end1,int start2, int end2)
{
	cout<<"void block_swap(int arr[],int start1: "<<start1<<",int end1: "<<end1<<",int start2: "<<start2<<", int end2: "<<end2<<")\n";
	int i=end1-start1+1;
	while(i--)
	{
		int temp=arr[start1];
		arr[start1]=arr[start2];
		arr[start2]=temp;
		start1++;
		start2++;
	}

	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void block_swap_algo(int arr[],int start,int n,int d)
{
	int size=min(d,(n-d+1));
	cout<<"void block_swap_algo(int arr[],int start: "<<start<<",int n: "<<n<<",int d:"<<d<<") size:"<<size<<"\n";
	getchar();
	
	if(start>=n||d==0)
		return;
		
	if(d==(n-d+1))
		 return block_swap(arr,start,start+d-1,start+d,n);

	block_swap(arr,start,start+size-1,n-(size-1),n);
	
	if(d < (n-d+1))  // or A.size<B.size
		return block_swap_algo(arr,start,n-(size),d);
		
	if(d > (n-d+1))  // or B.size<A.size
		return block_swap_algo(arr,start+size,n,d);
}

int main()
{
	int arr[100],d,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		cin>>d;
		
		d=d%n;
		//reverse_algo(arr,n,d);
		block_swap_algo(arr,0,n-1,d);
		
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
	}
	
}
