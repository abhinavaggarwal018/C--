//Kth smallest number in q_sort
#include<iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;

int n,arr[1000005],t,k;

int quick_sort(int a,int b)
{
	//cout<<"Quick Sort for a="<<a<<"b= "<< b <<"\n";
	if(a >= b)
	return 0;
	
	int pivot_index=(rand()%(b-a))+a;
	
	int temp=arr[pivot_index];
	arr[pivot_index]=arr[a];
	arr[a]=temp;
	
	int pivot=arr[a];
	pivot_index=a;
	//cout<<"\n";
	//for(int i=0;i<n;i++)
	//{
	//	printf("%d ",arr[i]);
	//}
	//cout<<"\n"<<"pivot:"<<pivot<<"\n";
	for(int i=a+1;i<=b;i++)
	{
		if(arr[i]<pivot)
		{
		//	cout<<pivot_index<<"\t"<<i<<"\t"<<pivot_index+1<<"\n1";
			int temp1=arr[pivot_index];
			int temp2=arr[i];
			int temp3=arr[pivot_index+1];
			
		//	cout<<temp1<<"\t"<<temp2<<"\t"<<temp3<<"\n";
		//	cout<<"\narr[i](arr["<<i<<"] is "<<arr[i];
			arr[pivot_index]=temp2;
			
		//	cout<<"\narr[pivot_index](arr["<<pivot_index<<"] is "<<arr[pivot_index];
			arr[i]=temp3;
			arr[pivot_index+1]=temp1;
		//	cout<<"\narr[pivot_index+1](arr["<<pivot_index+1<<"] is "<<arr[pivot_index+1];
			
			pivot_index++;
		}
	//	cout<<"Inner array\n";
	//	for(int i=0;i<n;i++)
	//	{
	//		printf("%d ",arr[i]);
	//	}	
	}
	//for(int i=0;i<n;i++)
	//{
	//	printf("%d ",arr[i]);
	//}
	//	cout<<"Quick Sort for a="<<a<<"pivot_index-1= "<< pivot_index -1 <<"\n";
	if(k==pivot_index)
		return pivot;
	if(k<pivot_index)
		return quick_sort(a,pivot_index-1);
	//	cout<<"Quick Sort for pivot_index+1="<<pivot_index+1<<"b= "<< b <<"\n";
	if(k>pivot_index)
		return quick_sort(pivot_index+1,b);
}

int main()
{


		scanf("%d",&n);
		scanf("%d",&k); //kth number
		k--; // kth smallest=arr[k-1]
		if(k>=n||k<0)
			return 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		cout<<quick_sort(0,n-1);
		

}
