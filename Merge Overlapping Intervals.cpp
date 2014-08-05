#include<iostream>
#include<vector>

using namespace std;

struct interval
{
	int start;
	int end;
}temp;

vector<interval> arr;
int n;


interval A1[1000005];
void merge(int p,int r,int q)
{
	int i=p,j=r+1,index=0;
	while(i<=r&&j<=q)
	{
		if(arr[i].start>=arr[j].start)
		{
			A1[index]=arr[j];
			j++;
		}
		else
		{
			A1[index]=arr[i];
			i++;
		}
		index++;
	}
	while(i<=r)
	{
		A1[index]=arr[i];
		index++;
		i++;
	}
	while(j<=q)
	{
		A1[index]=arr[j];
		index++;
		j++;
	}
	for(i=p;i<=q;i++)
	{
		arr[i]=A1[i-p];
	}
}
void mergesort(int p,int q)
{
	if(p!=q)
	{
		int r=p+((q-p)/2);
		mergesort(p,r);
		mergesort(r+1,q);
		merge(p,r,q);
	}
}

int main()
{
	int maxm;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)	
		{
			cin>>temp.start>>temp.end;
			arr.push_back(temp);
		}
		
		mergesort(0,n-1);
		
		cout<<arr[0].start<<" ";
		
		maxm=arr[0].end;
		for(int i=1;i<n;i++)
			if(maxm<arr[i].start)
			{
				cout<<maxm<<"\n"<<arr[i].start<<" ";
				maxm=arr[i].end;
			}
			else
			{
				maxm=max(maxm,arr[i].end);
			}
			
		cout<<maxm;
	}
}
