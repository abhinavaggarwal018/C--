#include<iostream>
#include<vector>

using namespace std;


struct entry
{
	int first;
	int second;
	int sum;	
};

struct entry* merge(struct entry arr[],int start,int mid,int end)
{
	
	struct entry c[100];

	int a=start, b=mid+1, ind=0;
	
	while(a<=mid&&b<=end)
	{
		if(arr[a].sum<=arr[b].sum)
		{
			
			c[ind].first=arr[a].first;
			c[ind].second=arr[a].second;
			c[ind].sum=arr[a].sum;
			
			a++;
			ind++;
		}
		
		if(arr[a].sum>arr[b].sum)
		{
			
			c[ind].first=arr[b].first;
			c[ind].second=arr[b].second;
			c[ind].sum=arr[b].sum;
			
			b++;
			ind++;
		}
	}

	while(a<=mid)
	{

		c[ind].first=arr[a].first;
		c[ind].second=arr[a].second;
		c[ind].sum=arr[a].sum;
		
		a++;
		ind++;
	}
		
	while(b<=end)
	{
		
		c[ind].first=arr[b].first;
		c[ind].second=arr[b].second;
		c[ind].sum=arr[b].sum;
		
		b++;
		ind++;
	}
	
	for(int i=0;i<ind;i++)
	{
		arr[start+i].first=c[i].first;
		arr[start+i].second=c[i].second;
		arr[start+i].sum=c[i].sum;
	}
	return c;
}

void merge_sort(struct entry arr[],int start,int end)
{
	if(start<end)
	{
		int mid=start+(end-start)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		arr=merge(arr,start,mid,end);
	}
}

void find_elements(int num[],int n,int sum)
{
	int val=(n*(n-1))/2;
	//vector<struct entry> arr(val+1);
	struct entry arr[1000];
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			arr[cnt].first=num[i];
			arr[cnt].second=num[j];
			arr[cnt].sum=num[i]+num[j];
			cnt++;
		}
	}

	for(int i=0;i<val;i++)
		cout<<arr[i].sum<<" ";
	cout<<"\n";
		
	merge_sort(arr,0,val-1);
	
	for(int i=0;i<val;i++)
		cout<<arr[i].sum<<" ";
	cout<<"\n";
		
	int i=0,j=val-1;
	
	while(i<j)
	{
		if((arr[i].sum+arr[j].sum)==sum)
		{
			if(arr[i].first!=arr[j].first && arr[i].first!=arr[j].second && arr[i].second!=arr[j].first && arr[i].second!=arr[j].second)
				cout<<"The numbers are: "<<arr[i].first<<","<<arr[i].second<<","<<arr[j].first<<" and "<<arr[j].second<<"\n";
				
			if(arr[j].sum==arr[j-1].sum)
				j--;
				
			else if(arr[i].sum==arr[i+1].sum)
				i++;
				
			else
			{
				i++;
				j--;
			}
		}
		if((arr[i].sum+arr[j].sum)<sum)
			i++;
		else
			j--;
	}
}
int main()
{
	int n,num[100],sum;
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>num[i];
		
		cin>>sum;
		
		find_elements(num,n,sum);
	}
}
