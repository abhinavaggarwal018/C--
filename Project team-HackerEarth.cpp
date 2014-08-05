#include<stdio.h>
int A[100000],n,t,A1[100000];
void merge(int p,int r,int q)
{
//	cout<<"Entered P:"<<p<<"R:"<<r<<"Q:"<<q<<"\n";
	//	for(int i=p;i<=q;i++)
	//	cout<<A[i]<<" ";
	//	cout<<"\n";
	int i=p,j=r+1,index=0;
	while(i<=r&&j<=q)
	{
		if(A[i]>=A[j])
		{
			A1[index]=A[j];
			j++;
		}
		else
		{
			A1[index]=A[i];
			i++;
		}
		index++;
	//	for(int i=p;i<=q;i++)
	//	cout<<A[i]<<" ";
	//	cout<<"\n";
	//	cout<<"1"<<"\n";
	}
	while(i<=r)
	{
		A1[index]=A[i];
		index++;
		i++;
	//	for(int i=p;i<=q;i++)
	//	cout<<A[i]<<" ";
	//	cout<<"\n";
	//	cout<<"2"<<"\n";
	}
	while(j<=q)
	{
		A1[index]=A[j];
		index++;
		j++;
	//	for(int i=p;i<=q;i++)
	///	cout<<A[i]<<" ";
	//	cout<<"\n";
	//	cout<<"3"<<"\n";
	}
	for(i=p;i<=q;i++)
	{
		A[i]=A1[i-p];
	}
//		for(int i=p;i<=q;i++)
	//	cout<<A[i]<<" ";
	//	cout<<"\n";
}
void mergesort(int p,int q)
{
	//cout<<"Entered P:"<<p<<"Q:"<<q;
	if(p!=q)
	{
		int r=p+((q-p)/2);
		mergesort(p,r);
		mergesort(r+1,q);
		merge(p,r,q);
	//	cout<<"A:p:q ";
	}
}
int main()
{

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);	
		mergesort(0,n-1);
		int max1=0;
		int min1=32000;
		for(int i=0;i<n/2;i++)
		{
			if((A[i]+A[n-1-i])>max1)
			max1=A[i]+A[n-1-i];
			if((A[i]+A[n-1-i])<min1)
			min1=A[i]+A[n-1-i];
		}
		printf("%d\n",max1-min1);
	}
	
}
