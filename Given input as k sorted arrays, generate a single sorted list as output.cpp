#include<iostream>

using namespace std;

#define k_max 50
#define n_max 50

int arr[k_max][n_max],heap[k_max],n,k,index[k_max]={0};;

void display()
{
	for(int i=0;i<k;i++)
		cout<<heap[i]<<" ";	
	cout<<"\n"	;
}

void swap_arr(int index, int num)
{
	int temp=heap[num];
	heap[num]=heap[index];
	heap[index]=temp;
}

void max_heapify(int i)
{

	int lc=2*i+1,rc=2*i+2;
	if(rc>k-1&&lc>k-1)
		return;
	if(rc>k-1)
	{
//		display();
		if(heap[i]<heap[lc])
			swap_arr(i,lc);
//		display();
		return;
	}
	if(lc>k-1)
	{
//		display();
		if(heap[i]<heap[rc])
			swap_arr(i,rc);
//		display();	
		return;
	}
//	display();	
	int max_ind=i;
	if(heap[lc]>heap[max_ind])
		max_ind=lc;
	if(heap[rc]>heap[max_ind])
		max_ind=rc;
//	cout<<max_ind<<":"<<i<<"\n";
	if(max_ind==i)
		return;
	if(max_ind==rc)
	{
		swap_arr(i,rc);
//		display();
		return max_heapify(max_ind);
	}
	else 
	{
		swap_arr(i,lc);
//		display();
		return max_heapify(max_ind);
	}
}
//		0
//	1  		2
//3 		4-5		6
//7-	  

//		0
//	7  		6
//3 		4-5		2
//1-	  


void create_heap(int n)
{
	for(int i=n/2-1;i>=0;i--)
		max_heapify(i);
}

int main()
{
	k=8;
	for(int i=0;i<8;i++)
	heap[i]=i;
	create_heap(8);
	
	display();
	cin>>n>>k;

	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	
	for(int i=0;i<k;i++)
	{
		heap[i]=arr[i][0];
	}
	
	create_heap(k);
//	display();
	int cnt=1;
	cout<<heap[0];	
	while(cnt<n*k)
	{
		for(int i=0;i<k;i++)
		{
			if(arr[i][index[i]]==heap[0]&&index[i]<n)
			{
				cnt++;
				index[i]++;
				if(index[i]<n-1)
					heap[0]=arr[i][index[i]];
			}
		}
	}
}
