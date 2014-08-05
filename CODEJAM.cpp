#include<iostream>
using namespace std;
long long int a,oper;
int t,n,arr[1000005];
 
void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
 
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}

void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}

int main()
{
	dp[i][n]=min(1+dp[i][n-1],)
	cin>>t;
	for(int l=0;l<t;l++)
	{
		oper=0;
		cin>>a>>n;
		int n1=n;
		for(int j=0;j<n;j++)
		cin>>arr[j];
		quickSort(arr,n);
		n=n1;
		for(int i=0;i<n;i++)
		{
			cout<<n;
			//cout<<oper<<"  "<< i<<"  "<<arr[i]<<"  "<<n<<"\n";
			dp[0]=0;
			if(arr[i]<a)
				a+=arr[i];
			for(i>0)
			dp[i]=dp[i-1];
			else if(arr[i]>=a)
			{
					a+=a-1;
					dp[i]=min(1+dp[i-1])
			}
			}
			cout<<oper<<"  "<< a <<"  "<<arr[i]<<"  "<<i<<":"<<n<<"\n";
		}
		cout<<"Case #"<<l+1<<": "<<oper<<"\n";
	}
	
}
