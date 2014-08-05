#include<iostream>
using namespace std;
int n,min1,cnt=0;;
long long int arr[1000005][3],val;

int main()
{
	cin>>n;
	while(n!=0)
	{
		cnt++;
		val=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>arr[i][j];
		
		arr[0][2]=arr[0][1]+arr[0][2];
		arr[0][0]=1000005;
		for(int i=1;i<n;i++)
		{
			arr[i][0]=arr[i][0]+min(arr[i-1][0],arr[i-1][1]);
			arr[i][1]=arr[i][1]+min(min(min(arr[i][0],arr[i-1][0]),arr[i-1][1]),arr[i-1][2]);
			arr[i][2]=arr[i][2]+min(min(arr[i][1],arr[i-1][1]),arr[i-1][2]);
		}
		cout<<cnt<<". "<<arr[n-1][1]<<"\n";
		cin>>n;
	}
}
