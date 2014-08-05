#include<iostream>

using namespace std;

int main()
{
	int n,sum,inp[10000];
	bool arr[100000];
	
	cin>>n;
	
	sum=0;
	for(int i=0;i<n;i++)
	{
//		cout<<i<<":"<<n;
		cin>>inp[i];
		
		sum+=inp[i];
	}
	
//	cout<<sum;
	arr[0]=true;
	
	for(int j=0;j<n;j++)
		for(int i=sum/2;i>=0;i--)
		{
				if(arr[i])
					if((i+inp[j])<=sum/2)
						arr[i+inp[j]]=true;
		}
	
	int i;

	for(i=sum/2;i>=0 && arr[i]==false;i--);
	
	cout<<sum/2-i;

	return 0;
}
