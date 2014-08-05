#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t,n;
	double arr1[1005],arr2[1005];
	
	cin>>t;
	
	for(int j=0;j<t;j++)
	{
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			cin>>arr1[i];

		for(int i=0;i<n;i++)
			cin>>arr2[i];
			
		sort(arr1,arr1+n);
		sort(arr2,arr2+n);

		int cnt=0;
		
		for(int i=0;i<n;i++)
		{
			if(arr1[i]>arr2[n-1-i])
				cnt++;
		}
		
		cout<<"Case #"<<j+1<<": "<<cnt<<" "<<n-cnt<<"\n";
	}
}
