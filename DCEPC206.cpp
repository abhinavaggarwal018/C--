/*
SPOJ Problem Set (classical)
10810. Its a Murder!
Problem code: DCEPC206

Once detective Saikat was solving a murder case. 
While going to the crime scene he took the stairs and saw that a number is written on every stair.
He found it suspicious and decides to remember all the numbers that he has seen till now. 
While remembering the numbers he found that he can find some pattern in those numbers. 
So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
Calculate the sum of all the numbers written on his notes diary.
Input

First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output

For each test case output one line giving the final sum for each test case.
Constraints

T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Example

Input:
1
5
1 5 3 6 4

Output:
15

Time limit:	3s 
*/

#include<iostream>
#include<stdio.h>

using namespace std;

long long int sum=0;

int t,n,arr[100005];

int return_index(int b,int max_val)
{
	int val=arr[b];
	while(val==arr[b]&&b<max_val)
	{
		b++;
	}
	return b;
}

int merge( int start, int mid , int end)
{
	int c[100005];
	int a=start;
	int b=mid+1;
	int index=0;

//	cout<<"The next iteration is for start="<<start<<" iteration is for mid="<<mid<<" iteration is for end="<<end<<" and sum"<<sum<<" \n";	
	
	while( a <= mid && b <= end )
	{
		if ( arr[a] < arr[b] )
		{
			//cout<<"end:"<<end<<"mid:"<<mid<<"b:"<<b;
			sum+=(long long int)((end)-(b)+1)*(long long int)arr[a];
//			cout<<"\n"<<sum<<"\n";
			c[index]=arr[a];
			index++;
			a++;
		}
		
		else if ( arr[a] > arr[b] )
		{
			c[index]=arr[b];
			index++;
			b++;
		}
		else if( arr[a] == arr[b] )
		{
			sum+=(long long int)((end)-(return_index(b,end)))*(long long int)arr[a];
			c[index]=arr[a];
			index++;
			a++;
		}
	}
	
	while ( b <= end )	
	{
		c[index]=arr[b];
		index++;
		b++;
	}
	
	while ( a <= mid )
	{
		c[index]=arr[a];
		index++;
		a++;
	}

	for(int i=0;i<index;i++)
		arr[start+i]=c[i];
		
}

int split( int start, int end )
{
	if (start>=end)
		return 0;
	int mid=start+(end-start)/2;
	if(start<end)
	{
		split(start,mid);
		split(mid+1,end);
		merge(start,mid,end);
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		split(0,n-1);
		
	//	for(int i=0;i<n;i++)
	//		cout<<arr[i]<<"\t";
		cout<<sum<<"\n";
	}
}


			  
