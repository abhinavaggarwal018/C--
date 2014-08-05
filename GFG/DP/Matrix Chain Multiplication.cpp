#include<iostream>

using namespace std;

MatrixChainOrder(int arr[], int start, int end,int left, int right)
{
	int val1,val2,left1,right1,left2,right2;
	
	val1=MatrixChainOrder(arr,start+1,end,left1,right1);
	val2=MatrixChainOrder(arr,start,end-1,left2,right2);
	
	if((val1)<(val2))
	
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ",
                          MatrixChainOrder(arr, 1, n-1));
 
    getchar();
    return 0;
}
