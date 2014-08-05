// IMPORTANT ARRAYS

#include "C:\Users\Abhinav123\Documents\C++\abhinav.h"
//#include<abhinav>

int ceil_bin(int val,int lis[],int start,int end)
{
	if(start==end)
		return start;
		
	int mid=start+(end-start)/2;
	
	if(lis[mid]==val)
		return mid;
	
	if(lis[mid]<val)
		return ceil_bin(val,lis,mid+1,end);
	else
		return ceil_bin(val,lis,start,mid);

}
int main()
{
	int n=16,arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
/*	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
*/		
	int lis[100]={10000},len=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<lis[0])
			lis[0]=arr[i];
			
		else if(arr[i]>lis[len])
			lis[++len]=arr[i];
			
		else
		{
			cout<<"ceil_bin(arr[i],lis,0,len):"<<ceil_bin(arr[i],lis,0,len)<<"\n";
			lis[ceil_bin(arr[i],lis,0,len)]=arr[i];
		}
		cout<<"\n"<<i<<":"<<len+1<<"\n";
		for(int i=0;i<=len;i++)
			cout<<lis[i]<<" ";
	}
	cout<<len+1;
}

