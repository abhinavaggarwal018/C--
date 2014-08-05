#include<abhinav.h>

int find_median(int arr1[],int arr2[],int start1,int end1, int start2,int end2)
{

	int mid1=start1+(end1-start1)/2;
	int mid2=start2+(end2-start2)/2;
	
	int mid=min(mid1,mid2);

	if(start1==end1)
	{
		
		if(start2==end2)
			return (arr1[start1]+arr2[start2])/2;
		
		
		if((start2-end2)%2==1)
		{
			if(arr1[start1]<arr2[mid2])
				return arr2[mid2];
				
			if(arr1[start1]>arr2[mid2+1])
				return arr2[mid2+1];
			
			else
				return arr1[start1];
		}
		
		else
		{
			int arr[]={arr1[start1],arr2[mid2-1],arr2[mid2],arr2[mid2+1]};
			
			for(int i=0;i<4;i++)
				for(int j=i+1;j<4;j++)
				{
					if(arr[i]>arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					}
				}
			
			return (arr[1]+arr[2])/2;
		}

	}
	
	if(start1==end1-1)
	{

		if(start2==end2)
		{
			if(arr1[start1]>arr2[mid2])
				return arr1[start1];
				
			if(arr1[start1+1]<arr2[mid2])
				return arr1[start1+1];
			
			else
				return arr2[mid2];
		}
		
		if((start2-end2)%2==0)
		{
			int arr[]={arr1[start1],arr1[start1+1],arr2[mid2-1],arr2[mid2],arr2[mid2+1]};
			
			for(int i=0;i<5;i++)
				for(int j=i+1;j<5;j++)
				{
					if(arr[i]>arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					}
				}
			
			return arr[2];
		}
		
	/*check 	else if(arr1[start1]<arr2[mid2] && (start2-end2)%2==1)
			return (arr2[start2]+arr1[start1])/2;  also check if arr2 has only one/2 elements
		*/
		else
			assert(0);
	}
	
	int m1=arr1[mid1];
	int m2=arr2[mid2];
	cout<<m1<<" "<<m2;
	if(m1==m2)
		return m1;
		
	if(m1>m2)
		find_median(arr1,arr2,start1,end1-mid,start2+mid,end2);
		
	else if(m1<m2)
		find_median(arr1,arr2,start1,end1-mid,start2+mid,end2);
}

int main()
{
	int arr1[]={1, 5, 7, 10, 13, 27};
	int arr2[]={11, 15, 23, 30, 45};
	int n1=6;
	int n2=5;
	
	cout<<find_median(arr1,arr2,0,n1-1,0,n2-1);
}
