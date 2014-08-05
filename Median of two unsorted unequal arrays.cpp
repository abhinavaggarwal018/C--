#include<iostream>

using namespace std;


int median(int arr[],int low,int high)
{
	
	int mid=low+(high-low)/2;
	if((high-low)%2==0)
		return (arr[mid-1]+arr[mid])/2;
	else
		return arr[mid];
}

int find_median(int arr1[],int arr2[],int low1,int high1,int low2, int high2)
{
	
	int m1=median(arr1,low1,high1);
	int m2=median(arr2,low2,high2);
	
	cout<<"\nint find_median(int arr1[],int arr2[],int low1 "<<low1<<" ,int high1, "<<high1<<" int low2, "<<low2<<" int high2"<<high2<<") Median1: "<<m1<<" Median2: "<<m2<<"\n";
	
	if(high1-low1<=1 || high2-low2<=1)
		return (m1+m2)/2;
	
	int n=min(high1-low1,high2-low2)/2;
	
	if(m1==m2)
		return m1;
		
	if(m1>m2)
		return find_median(arr1,arr2,low1,high1-n,low2+n,high2);
		
	if(m2>m1)
		return find_median(arr1,arr2,low1+n,high1,low2,high2-n);
}

int find_pos(int arr[],int num,int start,int high)
{

	if(num<arr[start])
		return start;
		
	if(num>arr[high-1])
		return high-1;
		
	if(num==arr[start+(high-start)/2])
		return high/2;
		
	if(num>arr[start+(high-start)/2])
		return find_pos(arr,num,high/2,high);
	else
		return find_pos(arr,num,start,high/2);
}

int binary_search(int arr1[],int arr2[],int low1,int high1,int low2,int high2)
{
	cout<<"\nint b_search(int arr1[],int arr2[],int low1: "<<low1<<", int high1: "<<high1<<", int low2: "<<low2<<", int high2: "<<high2<<")\n";
	int m1=median(arr1,low1,high1),l1=low1,h1=high1,l2=low2,h2=high2;
	while(low1<high1)
	{
		int p=find_pos(arr2,m1,0,high2)+1;
		cout<<p<<"::";
		cout<<"\nint find_median(int arr1[],int arr2[],int low1 "<<low1<<" ,int high1, "<<high1<<" int low2, "<<low2<<" int high2"<<high2<<") Median1: "<<m1<<" Median 1 position: "<<p<<"\n";
		
		if(p==high2/2)
		{
			if((h2+h1)%2==0)
				return (m1+arr2[p])/2;
			else
				return m1;
		}
		
		else if(p>high2/2)
			 m1=median(arr1,low1,high1/2-1);
		
		else
			m1=median(arr1,high1/2+1,high1);
	}
	
	low1=l1;
	high1=h1;
	low2=l2;
	high2=h2;
	
	int m2=median(arr2,low2,high2);
	while(low2<high2)
	{
		int p=find_pos(arr1,m2,0,high1)+1;
		
		if(p==high1/2)
		{
			if((h2+h1)%2==0)
				return (m1+arr2[p])/2;
			else
				return m1;
		}		
		else if(p>high1/2)
			 m2=median(arr2,low2,high2/2-1);
		
		else
			m2=median(arr2,high2/2+1,high2);
	}
}

void find_median_wrapper(int arr1[],int arr2[],int n1,int n2)
{
	//cout<<"\nAns is:"<<find_median(arr1,arr2,0,n1,0,n2);
	cout<<"\nAns is:"<<binary_search(arr1,arr2,0,n1,0,n2);
}

int main()
{
	int n1,n2,arr1[100],arr2[100],t;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n1;
		
		for(int i=0;i<n1;i++)
			cin>>arr1[i];
			
		cin>>n2;
		for(int i=0;i<n2;i++)
			cin>>arr2[i];
		
		//cout<<find_pos(arr1,n2,0,n1);	
		find_median_wrapper(arr1,arr2,n1,n2);
	}
}
