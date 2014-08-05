#include<iostream>
#include<vector>

using namespace std;

int b_search(vector<int> arr,int start,int end,int val)
{
//	cout<<"b_search(vector<int> arr,int start:"<<start<<",int end:"<<end<<",int val:"<<val<<")\n";
	
	if(start>=end)
	{
		if(arr[start]==-1&&arr[start-1]<val)
			return start;
			
		if(arr[start]==-1&&arr[start-1]<val)
			return start-1;
			
		if(arr[start]<val)
			return start+1;
			
		if(arr[start]>val)
			return start;
	}
	
	int mid=start+(end-start)/2;
	
	if(arr[mid]>val||arr[mid]==-1)
		return b_search(arr,start,mid-1,val);
		
	if(arr[mid]<=val)
		return b_search(arr,mid+1,end,val);
}

int main()
{
	int n,arr[1000],j;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		vector<int> lis(n+1,-1);
		vector<int> seq;
		
		lis[1]=arr[0];
		seq.push_back(arr[0]);
		for(int i=1;i<n;i++)
		{
			j=b_search(lis,1,n,arr[i]);
			//cout<<"j:"<<j<<"\n";
			for(j=1;j<=n;j++)
				if(!(lis[j]!=-1&&arr[i]>lis[j]))
					break;
			
		//	cout<<"j:"<<j<<"\n";
			if(lis[j]==-1&&arr[i]>lis[j-1])
			{
				lis[j]=arr[i];
				seq.push_back(arr[i]);
			}

			if(j>1)
			{
				lis[j]=arr[i];
				seq.pop_back();
				seq.push_back(arr[i]);
			}
			
/*			for(int i=1;i<=n;i++)
				cout<<lis[i]<<" ";
*/			
		}
		
		for(int i=1;i<=n;i++)
			//cout<<lis[i]<<" ";
			if(i==n||lis[i+1]==-1)
			{
				cout<<i<<"\n";
				break;
			}
			for(int i=0;i<seq.size();i++)
			cout<<seq[i]<<" ";
			seq.clear();
			cout<<"\n";
	}
}
