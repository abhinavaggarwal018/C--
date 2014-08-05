#include<iostream>
#include<cassert>
#include<cstdio>
#include<stack>

using namespace std;


int arr[1000];
int cnt=0;
/*
void recur(int sum, int curr_sum, int start)
{
	if(curr_sum == sum)
	{
		if(cnt==1)
			return;
			
		for(int i=0;i<cnt;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
		return;
	}
	
	if(curr_sum > sum)
		return ;
		
	for(int i=start;i<=sum-curr_sum;i++)
	{
		curr_sum+=i;
		arr[cnt]=i;
		cnt++;
//		cout<<sum<<":"<<curr_sum<<":"<<i<<"\n";
		recur(sum,curr_sum,i);
		cnt--;
		curr_sum-=i;
	}
}
*/
/*
void ques2()
{
	int arr[1000]={1,2,3,4,5,6,7,8,9,10,11,12};
	int n=12;
			
	
	for(int i=0;i<n;i++)
		cout<<arr[i];
}
*/
/*
void search_in_pivoted_array()
{
	int n=5;
	int arr[]={1,2,3,4,5};
	int val=3;
	
	int start=0,mid=0,end=n-1;
	while(start<end-1)
	{
		mid=start+(end-start)/2;
		
		if(arr[mid]>=arr[start])
			start=mid;
		else
			end=mid;
	}
	
	int pivot=start+1;
	
	if(pivot==n-1)
		pivot=0;
	
	if(arr[val]==arr[pivot])
		cout<<pivot;
	
	if(arr[val]>arr[pivot])
	{
		start=pivot;end=n-1;
	}

	if(arr[val]<arr[pivot])
	{
		end=pivot;start=0;
	}
	
	while(start<=end-1)
	{
		mid=start+(end-start)/2;
		
		if(arr[mid]==arr[start])
		{
			cout<<start;
			break;
		}
		if(arr[mid]>arr[start])
			start=mid;
		else
			end=mid;
	}
	
}
*/
/*
int find_first_non_repetitive_character()
{
	string str;
	int ans[100]={0};
	cin>>str;
	
	for(int i=0;i<str.length();i++)
		ans[str[i]-50]++;
	
	for(int i=0;i<str.length();i++)
		if(ans[str[i]-50]==1)
		{
			cout<<str[i];
			break;
		}
}
*/
/*
void k_way_merge(int ans[], int arr[][100], int n, int k, int ind)
{
		
	if(ind==k)
		return;
		
	int c[10000];	

	int cnt=0;
	int i=0,j=0;
	
	while(i<(n*ind) && j<n)
	{
		if(ans[i]<=arr[ind][j])
		{
			c[cnt]=ans[i];
			cnt++;
			i++;
		}
		
		else
		{
					
			c[cnt]=arr[ind][j];
			cnt++;
			j++;
		}
	}
	
	while(i<(n*ind))
	{
			c[cnt]=ans[i];
			cnt++;
			i++;
	}
	
	while(j<n)
	{
		c[cnt]=arr[ind][j];
		cnt++;
		j++;
	}
	
	for(int i=0;i<cnt;i++)
		ans[i]=c[i];
		
	for(int i=0;i<cnt;i++)
		cout<<c[i]<<" ";
	cout<<endl;
	return k_way_merge(ans,arr,n,k,ind+1);
}

struct node
{
	int data;
	int i;
	int j;
	
	node(int a, int b, int c)
	{
		data=a;
		i=b;
		j=c;
	}
	
	node()
	{
		;
	}
	
}heap[100];

void swap(struct node heap[], int start, int end)
{
	struct node node1;
	
	node1.data=heap[start].data;
	node1.i=heap[start].i;
	node1.j=heap[start].j;
	
	heap[start].data=heap[end].data;
	heap[start].i=heap[end].i;
	heap[start].j=heap[end].j;
	
	heap[end].data=node1.data;
	heap[end].i=node1.i;
	heap[end].j=node1.j;
}

void min_heapify(struct node heap[], int k, int i)
{
	int left=2*i+1,right=2*i+2;
	
		if(left< k && right<k)
		{
			if(heap[i].data>heap[left].data && heap[left].data<=heap[right].data)
			{
				swap(heap,i,left);
				min_heapify(heap,k,left);
			}
			else if(heap[i].data>heap[right].data && heap[right].data<=heap[left].data)
			{
				swap(heap,i,right);
				min_heapify(heap,k,right);
			}
		}
		
		else if(left< k)
		{
			if(heap[i].data>=heap[left].data)
			{
				swap(heap,i,left);
				min_heapify(heap,k,left);
			}
		}
}

void create_heap(struct node heap[], int k)
{
	for(int i=k/2;i>=0;i--)
		min_heapify(heap,k,i)		;
}

void heaps_print()
{
	int n,k,arr[100][100];
	
	cin>>k>>n;
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
		
		arr[i][n]=INT_MAX;
	}
	
	for(int i=0;i<k;i++)
		heap[i]=node(arr[i][0],i,0);
		
	create_heap(heap, k);
	int n123;
	
	while(heap[0].data!=INT_MAX)
	{
	
		cout<<heap[0].data;
		heap[0].j=heap[0].j + 1;
		heap[0].data=arr[heap[0].i][heap[0].j];

		min_heapify(heap, k, 0);
		
		getchar();
	}
	
}

void merge_k_arrays()
{
	int n,k, arr[100][100],ans[10000];
	
//	cin>>k;
//	cin>>n;
	
//	for(int i=0;i<k;i++)
//		for(int j=0;j<n;j++)
//			cin>>arr[i][j];

//	for(int i=0;i<n;i++)
//		ans[i]=arr[0][i];
					
//	k_way_merge(ans,arr,n,k,1);
	
//	for(int i=0;i<(n*k);i++)
//		cout<<ans[i];
	
	
	heaps_print();
}
*/

/*
int b_search(int arr[], int start, int end)
{
	if(start> end)
		return INT_MAX;
		
	if(start==end)
		return arr[start];
		
	int mid=start+(end-start)/2;
	
	if(arr[mid]>arr[mid+1])
		return b_search(arr,mid+1,end);
		
	if(arr[mid]> arr[mid-1])
		return b_search(arr,start,mid-1);
	
}
*/

/*
void find_smallest_in_sorted_and_pivoted_array()
{
	int n,arr[1000];
	
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	cout<<b_search(arr,0,n-1);	
}
*/
/*
int f(int x) { return (x*x - 10*x - 20); }

int find_ele(int a, int b)
{
	cout<<a<<" "<<b<<"\n";
	
	if(b-a==1)
		return f(a)>0 ? a:b ;
		
	if(a==b)
		return a;
		
	int mid=a+(b-a)/2;
	
	if(f(mid)>0)
		return find_ele(a,mid);
		
	else
		return find_ele(mid+1,b);
}

void find_point_where_function_becomes_increasing()
{
	int i=1;
	if(f(1)>0)
	{
		cout<<1;
		return;
	}
	
	while(f(i)<0)
	{
		i=i<<1;
	}

	cout<<find_ele(i>>1,i);
}
*/

/*
void max_prod_increasing_len()
{
	int n, arr[100];
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int prod=0,max1,max2,max3;
		
	for(int i=3;i<n;i++)
	{
		max1=0;
		max2=0;
		max3=0;
		
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				int num=arr[j];
				max1=arr[i];
				
				if(num>max2)
				{
					max3=max2;
					max2=num;
				}
				
				else if(num>max3)
					max3=num;
			}
		}
		
		prod=max(prod,max1*max2*max3);
		cout<<max1<<":"<<max2<<":"<<max3<<"::"<<prod<<"\n";
		
	}
	
	cout<<prod;
	return;
} 
*/

void take_input(int arr[], int &n)
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

int find_piv(int arr[], int start, int end)
{
	if(start>end)
		return start;
		
	if(start==end)
		return start;
	
	if(end-1==start)
		return arr[start]<arr[end]? start:end ;
		
	int mid= start+(end-start)/2;
		
	if(arr[start]<arr[end])
		return start;
		
	else
	{
		if(arr[mid]>arr[start])
			return find_piv(arr,mid,end);
		else
			return find_piv(arr,start,mid);
	}
}

void find_ele(int arr[], int start, int end, int k)
{
	if(start>end)
	{
		cout<<-1;
		return;
	}	
	int mid=start+(end-start)/2;
	
	if(arr[mid]==k)
	{
		cout<<mid;
		return;
	}
	
	if(arr[mid]>k)
		return find_ele(arr,start,mid-1,k);
	
	else	
		return find_ele(arr,mid+1,end,k);
}

void search_in_pivoted_array()
{
	int arr[100],n,k;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	
	int piv=find_piv(arr,0,n-1);
	
	cout<<piv;
	
	int start=0, end=n-1;
	
	if(k==arr[piv])
	{
		cout<<piv;
		return;
	}
	
	if(k==arr[start])
	{
		cout<<start;
		return;
	}

	if(k==arr[end])
	{
		cout<<end;
		return;
	}
		
	if(k<arr[end])
		find_ele(arr,piv,end,k);
	else
		find_ele(arr,start,piv,k);
}		

void find_maxm_in_first_increasing_then_decreasing(int arr[], int start, int end)
{
	if(start==end)
	{
		cout<<arr[start];
		return;
	}

	if(start==end-1)
	{
		cout<<max(arr[start],arr[end]);
		return ;
	}
	int mid=start+(end-start)/2;
	
	if(arr[mid]>arr[mid-1])
		return find_maxm_in_first_increasing_then_decreasing(arr,mid,end);
	
	else
		return find_maxm_in_first_increasing_then_decreasing(arr,start,mid);
}

float fms_util(int arr1[], int start1, int end1, int arr2[], int n1,int n2)
{
	
	if(start1>end1)
		return fms_util(arr2,max(0,(n2+n1)/2-n1),min(n2,(n1+n2)/2),arr1,n2,n1);
		
	int i=start1+(end1-start1)/2;
	int j=(n1+n2)/2-i-1;
	
	if(j>=0 && arr1[i]<arr2[j])
		return fms_util(arr1,i+1,end1,arr2,n1,n2);
		
	if(j<n2-1 && arr1[i]>arr2[j+1])
		return fms_util(arr1,start1,i-1,arr2,n1,n2);
		
	else
	{
		if((n1+n2)%2==1)
			return arr1[i];
			
		else if(i>0)
			return (arr[i]+max(arr1[i-1],arr2[j]))/2.0;
			
		else
			return (arr[i]+arr[j])/2.0;
	}
/*	cout<<start1<<end1<<"\n";
	
	if(start1>end1)
		find_median(arr2,0,n2-1,arr1,0,n1-1,n2,n1);
	
	if((n1+n2)%2==1)
	{	
		int mid=start1+(end1-start1)/2;
		int n=(n1+n2+1)/2;
		
		
		if(n-mid<0)
			return find_median(arr1,mid+1,end1,arr2,start2,end2,n1,n2);
			
		else if(arr1[mid]>=arr2[n-mid] && arr1[mid]<=arr2[n-mid+1])
			return arr1[mid];
		
		else if( arr1[mid]>arr2[n1-mid] )
			return find_median(arr1,mid+1,end1,arr2,start2,end2,n1,n2);
			
		else if(arr1[mid]<arr2[n1-mid-1])
			return find_median(arr1,start1,mid-1,arr2,start2,end2,n1,n2);
	}
	
	else
	{
		
		return 0;
		
	}
	*/
	
	
}

void shift_elements(int arr[], int n, int d)
{
	for(int i=0;i<d;i++)
	{
		int j=i;
		int temp=arr[i];
		
		while((i+d)<n)
		{
			arr[i]=arr[(i+d)%n];
			i=i+d;
		}
		
		arr[i]=temp;
		
		i=j;
	}
	
	for(int i=0;i<n;i++)
		cout<<arr[i];
}


int find_first_occurance(int arr[], int start, int end, int k)
{
	if(start==end)
		return start;
		
	if(start==end-1)
		return arr[start]==k? start: (arr[end]==k ? end : -1) ;
		
	int mid=start+(end-start)/2;
	
	if(arr[mid]>=k)
		return find_first_occurance(arr,start,mid,k);
		
	else
		return find_first_occurance(arr,mid+1,end,k);
}
	
int find_last_occurance(int arr[], int start, int end, int k)
{
	if(start==end)
		return start;
		
	if(start==end-1)
		return arr[start]==k? start: (arr[end]==k ? end : -1) ;
		
	int mid=start+(end-start)/2;
	
	if(arr[mid]<=k)
		return find_last_occurance(arr,mid,end,k);
		
	else
		return find_last_occurance(arr,start,mid-1,k);
}

int inv=0;

int merge(int arr[], int start, int mid, int end2)
{
	int end1=mid-1,a=start;
	int c[1000],cnt=0;
	
	while(start<=end1 && mid<=end2)
	{
		if(arr[start]<=arr[mid])
		{
			c[cnt]=arr[start];
			cnt++;
			start++;
		}
		
		else
		{
			inv+=mid-start;
			c[cnt]=arr[mid];
			cnt++;
			mid++;
		}
	}
	
	while(start<=end1)
	{
		c[cnt]=arr[start];
		cnt++;
		start++;
	}
	
	while(mid<=end2)
	{
//		inv+=start-a;
		c[cnt]=arr[mid];
		cnt++;
		mid++;
	}
	
	for(int i=0;i<cnt;i++)
		arr[a+i]=c[i];
}

void mergesort(int arr[], int start, int end)
{
	if(start>=end)
		return;
		
	int mid=start+(end-start)/2;
		
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	
	merge(arr,start,mid+1,end);
}

void print_leaders(int arr[], int n)
{
	stack < int > s;
	
	while(n>=0)
	{
		if(!s.empty())
		{
			while(!s.empty() && s.top() < arr[n])
				s.pop();
		}
		
		if(s.empty())
			cout<<arr[n]<<" ";
		
		s.push(arr[n]);
		n--;
	}
}

int max_sum(int arr[], int n)
{
	int dp[1000];
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	dp[2]=max(arr[0]+arr[2],arr[1]);
	if(n==1)
		return max(arr[0],arr[1]);
		
	if(n==2)
		return max(arr[0]+arr[2],arr[1]);
		
	for(int i=3;i<=n;i++)
		dp[i]=max(dp[i-2],dp[i-3])+arr[i];
		
	for(int i=0;i<=n;i++)	
		cout<<dp[i]<<" ";
}

void sort_by_frequency(int arr[], int n)
{
	//
}

void segregate(int arr[], int n)
{
	cout<<"Here";
	int start=0,end=n;
//	cout<<start<<end;
	while(start<=end)
	{
//		cout<<start<<end;
		if(arr[start]==0)
			start++;
		else
		{
			int temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
			end--;
		}
	}
	
	for(int i=0;i<=n;i++)
		cout<<arr[i]<<" ";
}

void min_heapify(int arr[], int ind, int k)
{
	int left=2*ind+1,right=2*ind+2;
	
	if(right<k)
	{
		if(arr[ind]>=arr[right] && arr[left]>=arr[right])
		{
			int temp=arr[ind];
			arr[ind]=arr[right];
			arr[right]=temp;
			
			min_heapify(arr,right,k);
		}
		
		else if(arr[ind]>=arr[left] && arr[right]>=arr[left])
		{
			int temp=arr[ind];
			arr[ind]=arr[left];
			arr[left]=temp;
			
			min_heapify(arr,left,k);
		}
	}
	
	if(left<k)
	{
		if(arr[ind]>arr[left])
		{
			int temp=arr[ind];
			arr[ind]=arr[left];
			arr[left]=temp;
			
			min_heapify(arr,left,k);
		}
	}
}

void build_heap(int arr[], int end)
{
	for(int i=end/2;i>=0;i--)
		min_heapify(arr,i,end);
}

void k_largest_in_array(int arr[], int n, int k)
{
	int heap[100];
	for(int i=0;i<k;i++)
		heap[i]=arr[i];
		
	build_heap(heap,k);
	
	for(int i=0;i<k;i++)
		cout<<heap[i]<<" ";
	
	for(int i=k;i<=n;i++)
	{
		if(heap[0]<arr[i])
		{
			heap[0]=arr[i];
			min_heapify(heap,0,k);
			
			for(int i=0;i<k;i++)
				cout<<heap[i]<<" ";
			cout<<"\n";
		}
	}
	
	for(int i=0;i<k;i++)
		cout<<heap[i]<<" ";
}

void floor_and_ceil_in_sorted_array(int arr[], int start, int end, int val, int n)
{
	if(start==end-1)
	{
		if(arr[start]>val)
			start>0 ? cout<<arr[start-1]<<":"<<arr[start] : cout<<"-1"<<arr[start];
			
		if(arr[start]==val)
			cout<<arr[start]<<":"<<arr[start];
			
		if(arr[start]<val)
			start+1<=n ? cout<<arr[start]<<":"<<arr[start+1] : cout<<arr[start]<<":"<<"-1";
			
		return;
	}
	
	int mid=start+(end-start)/2;
	
	if(arr[mid]==val)
	{
		cout<<"Floor:"<<arr[mid]<<"Ceil:"<<arr[mid];
		return;
	}
	
	if(arr[mid]<val)
		return floor_and_ceil_in_sorted_array(arr,mid,end,val,n);
		
	if(arr[mid]>val)
		return floor_and_ceil_in_sorted_array(arr,start,mid-1,val,n); // finding floor ceil would be next element
}

void min_len_subarray_sorting_which_makes_array_sorted(int arr[], int n)
{
	bool flag1,flag2;
	int ind1,ind2;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i+1]<arr[i] && flag1==false)
		{
			ind1=i;
			flag1=true;
		}
		
		if(arr[i+1]<arr[i])
			ind2=i+1;
	}
	
	cout<<ind1<<ind2;
	
	int minm=arr[ind1],maxm=arr[ind1];
	
	for(int i=ind1;i<=ind2;i++)
	{
		if(arr[i]<minm)
			minm=arr[i];
		
		else if(arr[i]>maxm)
			maxm=arr[i];
	}
	
	for(int i=0;i<ind1;i++)
		if(arr[i]>minm)
		{
			ind1=i;
			break;
		}
		
	for(int i=n;i>=ind2;i--)
		if(arr[i]<maxm)
		{
			ind2=i;
			break;
		}
		
	cout<<ind2<<":"<<ind1;
}

void print(	int arr[][100],int sr,int er,int sc,int ec)
{
	if(sr>er || sc>ec)
		return;
	
	for(int j=sc;j<=ec;j++)
		cout<<arr[sr][j]<<" ";
		
	for(int i=sr+1;i<=er;i++)
		cout<<arr[i][ec];
		
}
void spiral_printing()
{
	int m,n,arr[100][100];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
			
	print(arr,0,m-1,0,n-1);
}

void max_of_subarrays(int arr[], int n, int k)
{
	if(k>=n)
	{
		int maxm=arr[0];
		for(int i=1;i<n;i++)
			maxm=max(maxm,arr[i]);
			
		cout<<maxm;
		return;
	}
	
	deque <int> q;
	
	for(int i=0;i<k;i++)
	{
		while(!q.empty())
		{
			if(arr[i]>arr[q.back()])
				q.pop_back();
			else
				break;
		}
		
		q.push_back(i);
	}
	
	for(int i=k;i<=n;i++)
	{
		cout<<arr[q.front()]<<" ";
		
		while(!q.empty())
		{
			if(q.front()<=(i-k))
				q.pop_front();
			else
				break;
		}
		
		while(!q.empty())
		{
			if(arr[i]>arr[q.back()])
				q.pop_back();
			else
				break;
		}
		
		q.push_back(i);
	}
}

void max_ji_difference_max(int arr[],int n)
{
	int left[1000],right[1000];
	
	left[0]=arr[0];
	right[n]=arr[n];
	
	for(int i=1;i<n;i++)
		left[i]=min(arr[i],left[i-1]);
		
	for(int i=n-1;i>=0;i--)
		right[i]=max(arr[i],right[i+1]);
		
	int l=0,r=0,ans=INT_MIN;	
	
	while(l<=n && r<=n)
	{
		if(right[r]>left[l])
		{
			ans=max(ans,r-l);
			r++;
		}	
			
		else if(right[r]<=left[l])
			l++;			
	}
	
	cout<<ans;
}

int median_of_two_sorted_arrays(int arr[], int n);

int b_search(int arr[], int start, int end, int val)
{
	if(start==end)
	{
		if(arr[start]>val)
			return start;
		
		return start+1;
	}
	
	if(start==end-1)
	{
		if(arr[start]>val)
			return start;
		if(arr[end]>val)
			return end;
		else
			return end+1;
	}
		
	int mid=start+(end-start)/2;
	
	if(arr[mid]==val)
		return mid+1;
		
	if(arr[mid]<val)
		return b_search(arr,mid+1,end,val);
		
	if(arr[mid]>val)
		return b_search(arr,start,mid,val);
	
}

void find_lis(int arr[], int n, int left[])
{
	left[0]=arr[0];
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		int ind=b_search(left,0,cnt,arr[i]);
		cout<<ind<<"\n";
		
		left[ind]=arr[i];
		cnt=max(cnt,ind);
	}
}

int maximum_length_biotonic_subarray(int arr[], int n)
{
	if(n==0)	
		return 0;
		
	int left[1000],right[1000];
	find_lis(arr,n,left);
//	find_lds(arr,n,right);
	
	int maxm=0;
	for(int i=0;i<n;i++)
		maxm=max(maxm,left[i]+right[i]-1);
}

int max_prod_subarray(int arr[], int n)
{
	int ind1=-1,ind2=-1, prod=1,ans=0;
	
	for(int i=0;i<n;i++)
	{
		ind1=-1;
		ind2=-1;
		prod=1;
		
		while(i<n && arr[i]!=0)
		{
			if(arr[i]<0 && ind1==-1)
				ind1=i;
			
			else if(arr[i]<0)
				ind2=i;
				
			prod=prod*arr[i];
			i++;
		}
		
		if(prod<0)
		{
			if(ind2!=-1)
				prod=prod/min(abs(arr[ind1]),abs(arr[ind2]));
				
			else
				prod=prod/arr[ind1];
		}			
		
		ans=max(ans,prod);	
	}
	
	cout<<ans;
}

struct pair1
{
	int start, end;
	
	pair1(int a, int b)
	{
		start=a;
		end=b;
	}
};

void iterative_quick_sort(int arr[], int n)
{
	if(n==0)
		return;
	stack<pair1> s;

	s.push(pair1(0,n-1));
	
	while(!s.empty())
	{
	
		pair1 node=s.top();
		s.pop();
		
		int start=node.start;
		int end=node.end;

		int piv=arr[start];
		
		if(start>=end)
			continue;
		
		while(start<=end)
		{
			if(arr[start]<=piv)
				start++;
				
			else
			{
				int temp=arr[end];
				arr[end]=arr[start];
				arr[start]=temp;
				end--;
			}
		}
		
		arr[node.start]=arr[end];
		arr[end]=piv;
		
		s.push(pair1(start+1,node.end));
		s.push(pair1(node.start,start-1));
	}
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

void print_diagonally()
{
	int arr[100][100],m,n;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
			
	for(int i=0;i<n;i++)
	{
		int a=i;
		int b=0;
		
		while(a<m &&a >=0 && b>=0)
		{
			cout<<arr[a][b]<<" ";
			a--;
			b++;
		}
		
		cout<<"\n";
	}
	
	for(int i=1;i<m;i++)
	{
		int a=n-1;
		int b=i;
		
		while(a<m &&a >=0 && b>=0)
		{
			cout<<arr[a][b]<<" ";
			a--;
			b++;
		}
		
		cout<<"\n";
	}
	
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}*/
}


void init_hash(int hash[9])
{
	for(int i=0;i<9;i++)
		hash[i]=false;
}

bool check_hash(int hash[])
{
	for(int i=0;i<9;i++)
		if(hash[i]==false)
			return false;
}

bool is_correct_sudoku(int arr[9][9])
{
	
	
	for(int i=0;i<9;i++)
	{
		init_hash(hash)
		for(int j=0;j<9;j++)
			hash[arr[i][j]]=true;
			
		if(check_hash(hash)==false)
			return false;	
	}

	for(int i=0;i<9;i++)
	{
		init_hash(hash)
		for(int j=0;j<9;j++)
			hash[arr[j][i]]=true;
			
		if(check_hash(hash)==false)
			return false;	
	}
	
	for(int k=0;k<8;k+=3)
	{
		init_hash(hash);
		
		for(int i=k;i<k+3;i++)
			for(int j=0;j<3;j++)
				hash[arr[i][j]]=true;
				
			if(check_hash(hash)==false)
				return false;
	}
	
	for(int k=0;k<8;k+=3)
	{
		init_hash(hash);
		
		for(int i=k;i<k+3;i++)
			for(int j=0;j<3;j++)
				hash[arr[j][i]]=true;
				
			if(check_hash(hash)==false)
				return false;
	}
	
	return true;
}

int main()
{
/*	int sum;
	cin>>sum;
	recur(sum,0,1);*/
	
//	ques2();

//	search_in_pivoted_array();
	
//	find_first_non_repetitive_character();

//	merge_k_arrays();

//	find_smallest_in_sorted_and_pivoted_array();
	
//	find_point_where_function_becomes_increasing();	

//	max_prod_increasing_len();

//	search_n_pivoted_array();

//	search_in_pivoted_array();

	print_diagonally();

	int n1,n2,arr1[100],arr2[100],k,d;
	
	cin>>n1;
	for(int i=0;i<n1;i++)
		cin>>arr1[i];

	iterative_quick_sort(arr1,n1);

//	max_prod_subarray(arr1,n1);

//	find_lis(arr1,n1-1,arr);
	
/*	for(int i=0;i<n1;i++)
		cout<<arr[i]<<" ";*/
//	cin>>k;

//	max_ji_difference_max(arr1,n1-1);
		
//	max_of_subarrays(arr1,n1,k);
		
//	min_len_subarray_sorting_which_makes_array_sorted(arr1,n1-1);
		
/*	while(1)
	{	
		cin>>k;
		
		floor_and_ceil_in_sorted_array(arr1, 0, n1-1, k, n1-1);
	}
	*/

//	spiral_printing();
	
//	k_largest_in_array(arr1,n1-1,k);


//	segregate(arr1,n1-1);

//	max_sum(arr1,n1-1);
	
//	print_leaders(arr1,n1-1);
	
/*	mergesort(arr1,0,n1-1);
	
	for(int i=0;i<n1;i++)
		cout<<arr1[i]<<"  ";
	cout<<"\nINV:"<<inv;
	//cin>>k;
*/	
	//cout<<find_first_occurance(arr1,0,n1,k)<<":"<<find_last_occurance(arr1,0,n1,k);
	
//	cin>>d;
//	shift_elements(arr1, n1,d);

	cin>>n2;
	for(int i=0;i<n2;i++)
		cin>>arr2[i];
		
	cout<<fms_util(arr1,max(0,(n1+n2)/2-n2),min((n1+n2)/2,n1),arr2,n1,n2);
	//cin>>k;
	
//	find_maxm_in_first_increasing_then_decreasing(arr,0,n-1)	;
/*
	merge_arrays(int arr1[],int arr2[],int m, int n)
	{
		for(int i=m+n-1;i>=0;i--)
		{
			if(arr[i]<INT_MAX)
				i--;
			
			else
				for(int j=i-1;j>=0;j--)
					if(arr[j]<INT_MAX)
						break;
			
			arr[i]=arr[j];
			i=j;
		}
	}
	*/
}
