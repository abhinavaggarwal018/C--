#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int t,r,n,m,k,val[200],arr[200],num_val,num;
int main()
{
	cin>>t;
	cout<<"Case #1:\n";
	for(int l=0;l<t;l++)
	{
		cin>>r>>n>>m>>k;
		for(int i1=0;i1<r;i1++)
		{
			num_val=0;
			for(int i=0;i<200;i++)
				arr[i]=0;
			for(int j=0;j<k;j++)
			cin>>arr[j];
			for(int j=0;j<k;j++)
			for(int i=m;i>=2;i--)
			{
				while(arr[j]%i==0)
				{
					for(int k123=0;k123<m;k123++)
					{
						if(arr[k123]%i==0)
						arr[k123]=arr[k123]/i;
					}
					cout<<i;
					num_val++;
				//	num=i;
				}
			}

		if(num_val<n)
		{
			int diff=n-num_val;
			srand (time(NULL));
			while(diff!=0)
			{
				cout<<(rand()%(m-2))+ 2;	
				diff--;
			}
		}
		cout<<"\n";
		}
	}
}
