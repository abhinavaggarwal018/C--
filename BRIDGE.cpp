#include<iostream>
using namespace std;
int t,n,a[1005],b[1005],min_val,val,min_index,lis[1005];
//int b1[]={13,54276,8893,94,35,61,75,88,9};;
void sort_b(int start,int end)
{
	//cout<<"Start: "<<start<<"End: "<<end;
	for(int j=start;j<end;j++)
	{
		int temp;
		min_val=b[j];
		min_index=j;
	
		for(int i=j+1;i<end;i++)
			if(b[i]<b[min_index])
				min_index=i;
				
		temp=b[min_index];
		b[min_index]=b[j];
		b[j]=temp;
	}
}
void sort()
{
	//cout<<"\n";
	for(int j=1;j<=n;j++)
	{
		int temp;
		min_val=a[j];
		min_index=j;
	
		for(int i=j+1;i<=n;i++)
			if(a[i]<=a[min_index])
				min_index=i;
				
		//cout<<a[j]<<" "<<a[min_index]<<"\n";
		temp=a[min_index];
		a[min_index]=a[j];
		a[j]=temp;
		//cout<<a[j]<<" 1 "<<a[min_index]<<"\n";		

		temp=b[min_index];
		b[min_index]=b[j];
		b[j]=temp;
	}
		for(int i=1;i<=n;i++)
		{
			int j;
			
			for(j=i+1;j<=n;j++)
			{
					if(a[i]!=a[j])
					break;

			}
			sort_b(i,j);
			i=j-1;
			
		}
}

void lis1()
{
	sort();
	for(int i=1;i<=n;i++)
	{
		int count1=0;
		for(int j=1;j<i;j++)
		{
			if(b[j]<=b[i])
			{
				if(lis[j]>count1)
					count1=lis[j];
			}
		}
		lis[i]=1+count1;
	}
 	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
		cout<<b[i]<<" ";
	}*/

	for(int i=1;i<=n;i++)
	{
	//	cout<<lis[i]<<" ";
		if(lis[i]>val)
		val=lis[i];
	}
	
}
int main()
{
	cin>>t;
	
	for(int l=0;l<t;l++)
	{
		val=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		cin>>b[i];
		lis1();
		cout<<val<<"\n";
	}
}
