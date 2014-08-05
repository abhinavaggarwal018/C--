#include<iostream>
#include<cstdio>
using namespace std;

int cutRodDP(int arr[], int size)
{
	for(int i=2;i<size;i++)
	{
		for(int j=1;j<=i/2;j++)
			arr[i]=max(arr[i],arr[j]+arr[i-j]);
	}
	
	return arr[size];
}

int cutRod(int arr[], int size)
{
	if(size<=0)
		return 0;
	
	int ans=arr[size];
		
	for(int i=0;i<=size/2;i++)
	{
		ans= max(cutRod(arr,i)+cutRod(arr,size-i-1),ans);
	}
	
	
	return ans;
}


int main()
{
    int arr[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Maximum Obtainable Value is %d\n", cutRod(arr,  size));

    getchar();
    return 0;
}
