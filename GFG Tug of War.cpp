#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int sum=0,n=0,arr[1000],pos=0;

vector< vector<int> > val((20000) , vector<int> (10000));
int find(int start,int end,int sum,int cnt)
{
	if(start>end)
		return sum;
	
	val[pos].push_back(arr[pos]);
	pos+=2;
	return min(abs(find(start+1,end,sum-arr[start],cnt)),abs(find(start+1,end,sum,cnt+1)));
		
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	pos=0;
	val[pos].push_back(arr[pos]);
	pos+=2;
	cout<<"Ans is:"<<min(find(1,n-1,sum-arr[0],1),find(1,n-1,sum,0))<<"This\n";
}
