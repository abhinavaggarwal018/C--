#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	int n;
	int arr[105];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	std::sort(arr,arr+n);
	
	int hash[105];
	
	for(int i=0;i<n;i++)
		hash[i]=false;
	
	int cnt=0,cnt_temp=0;
	
	int prev=arr[0];
	
	for(int i=0;i<n;i++)
	{
		if(prev==arr[i] && arr[i]<=i)
			cnt_temp++;
		
		else
		{
			cnt=std::max(cnt_temp,cnt);
			cnt_temp=0;
			prev=arr[i];
		}
		
//		std::cout<<cnt_temp;
	}

	cnt=std::max(cnt_temp,cnt);	
	printf("%d\n",cnt);

}
