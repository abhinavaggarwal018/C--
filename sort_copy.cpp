#include<stdio.h>
int A[200005],A1[200005];
long long int cnt=0;
// declare arrays of big sizes globally.
void merge(int p,int r,int q)
{
//	cout<<"Entered P:"<<p<<"R:"<<r<<"Q:"<<q<<"\n";
	//	for(int i=p;i<=q;i++)
	//	cout<<A[i]<<" ";
	//	cout<<"\n";
	int i=p,j=r+1,index=0;
	while(i<=r&&j<=q)
	{
		if(A[i]>A[j])
		{
			A1[index]=A[j];
			j++;
			cnt+=r-i+1;
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
	int i,n,t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
			
		mergesort(0,n-1);
	
		printf("%lld\n",cnt);
	}
	return 0;
}
