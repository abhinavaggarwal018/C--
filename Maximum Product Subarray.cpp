#include<iostream>

using namespace std;

int main()
{
	int n,arr[100],cnt,idx,prod,prod_max;
	while(1)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cnt=0;
		idx=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<0&&(cnt%2==0))
			{
				cnt++;
				idx=i+1;
			}
			else if(arr[i]<0&&(cnt%2==1))
			{
				idx=0;
				cnt++;
			}
		}
		cout<<idx<<"\n";
		prod=1;
		prod_max=0;
		for(int i=0;i<idx-1;i++)
		{
			prod=prod*arr[i];
			if(prod>prod_max)
				prod_max=prod;
			if(prod==0)
				prod=1;
		}
		cout<<prod<<"\n";
		for(int i=idx;i<n;i++)
		{
			prod=prod*arr[i];
			if(prod>prod_max)
				prod_max=prod;
			if(prod==0)
				prod=1;
			cout<<prod<<" ";
		}
		
		cout<<prod_max;
		
	}
}
