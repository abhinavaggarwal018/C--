#include<iostream>
using namespace std;

#define k_max 50
#define n_max 50
#define size k_max*n_max
int ans[size+10],n,k,arr[n_max][k_max];

void merge(int k)
{
	int index1=0,index2=0;
	int c[size+10],index=0;

	while(index1<n*k&&index2<n)
	{
	//	cout<<"\tans[index1]"<<ans[index1]<<"arr[k][index2]:"<<arr[k][index2]<<"\n";
		if(arr[k][index2]<=ans[index1])
		{
	//		cout<<"*1*\tindex:"<<index<<"\n";
			c[index]=arr[k][index2];
			index2++;
			index++;
		}
		else
		{
	//		cout<<"*2*\tindex:"<<index<<"\n";
			c[index]=ans[index1];
			index1++;
			index++;
		}
	}
	
	while(index1<n*k)
	{
		c[index]=ans[index1];
	//	cout<<c[index]<<"\t";
		index1++;
		index++;
	}	
	
	while(index2<n)
	{
		c[index]=arr[k][index2];
	//	cout<<c[index]<<"\t";
		index2++;
		index++;
	}
		
	for(int i=0;i<=index;i++)
	{
		ans[i]=c[i];
	}
}


int main()
{
	cin>>k>>n;
	
	for(int i=0;i<n;i++)
		cin>>ans[i];

	for(int i1=1;i1<k;i1++)
		for(int i=0;i<n;i++)
			cin>>arr[i1][i];
	
	for(int i=1;i<k;i++)
		merge(i);
		
	for(int i=0;i<n*k;i++)
		cout<<ans[i]<<"->";
	cout<<"END\n";
}


