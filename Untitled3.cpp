Branch 
Level of coding
About us



What are functions?

Recursion: Base conndition
		   Statement
		   recursive Work
		   
sum of subset of array=k.

fact
fib

binary_search(0,n-1);

int binary_search(int start, int end, int data)
{
	if(start>end)
		return -1;
		
	int mid=start+(end-start)/2;
	
	if(arr[mid]>data)
		binary_search(start,mid-1);
		
	if(arr[mid]>data)
		binary_search(mid+1,end);
}


void subset_sum(int arr[],int i, int n, int sum, int k)
{
	if(sum==k)
		return true;

	if(sum>k || i>=n)
		return false;
		
	return subset_sum(arr,i+1,n,sum+arr[i],k)||subset_sum(arr,i+1,n,sum,k);
}

Complexity: 2^n
/*
void permute_string(char arr, int i1, int n, char ans[], int i2)
{
	if(i1==n)
		cout<<ans;
		
	for(int i=i1;i<n;i++)
	{
		char temp=arr[i1];
		arr[i1]=arr[i];
		arr[i]=temp;
		
		permute_string(arr,i1+1,n);
		
		arr[i1]=arr[i];
		arr[i]=temp;
	}
}

Comp: T(n)=n*T(n-1)+ O(n)
=n*n!

void string_len_k(char arr[], int k, int i1, int n)
{
	if(i1==k)
	{
		print;
		return;
	}
	
	for(int i=i1;i<n-k;i++)
	{
		swap(arr[i],arr[i1]);
		string_len_k(arr,k,i,n);
		swap(arr[i],arr[i1]);
	}
}

Comp: 

int num1=num

int palindrome_check(int num, int &num1)
{
	if(num/10==0)
		return num;
		
	if(num1%10!=palindrome_check(num/10))
		retuern false;
		
	
}*/

Find missing number in array from 1 to n
