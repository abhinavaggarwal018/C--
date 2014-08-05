#include<iostream>
#include<vector>

using namespace std;

vector<int> find_lis(int arr[],int n, vector<int> lis)
{
	//cout<<2;
	for(int i=0;i<n;i++)
		lis[i]=1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[j]<=arr[i]&&(lis[j]+1)>lis[i])
				lis[i]=(lis[j]+1);
	//cout<<3;
	return lis;
}

vector<int> find_lds(int arr[],int n, vector<int> lds)
{
	for(int i=0;i<n;i++)
		lds[i]=1;
	
	for(int i=n-1;i>=0;i--)
		for(int j=n-1;j>i;j--)
			if(arr[j]<=arr[i]&&(lds[j]+1)>lds[i])
				lds[i]=(lds[j]+1);
	
	return lds;
}
int biotonic_sequence(int arr[],int n)
{
	 vector<int> lis(n),lds(n);
	 //cout<<0;
	 lis=find_lis(arr,n,lis);
	 lds=find_lds(arr,n,lds);
	 
	 for(int i=0;i<n;i++)
	 	cout<<lis[i]<<" ";
	 cout<<"\n";
	 for(int j=0;j<n;j++)
	 	cout<<lds[j]<<" ";
	cout<<"\n";
	 
	 int max_len=-1;
	 for(int i=0;i<n;i++)
	 	if(lis[i]+lds[i]-1>max_len)
	 		max_len=lis[i]+lds[i]-1;
	 		
	return max_len;
}

int main()
{
	int n,arr[1000];
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<"Length is: "<<biotonic_sequence(arr,n);
	}
}
