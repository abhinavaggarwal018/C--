#include<iostream>

using namespace std;

int main()
{
	int n,arr[100],num1,num2;
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		cin>>num1>>num2;
		
		int ans=1000,cnt=1000;
		int num=num1+num2+1;// so that initially numnot equal to num1 or num2
		
		for(int i=0;i<n;i++)
		{
			if(arr[i]==num1&&num==num2)
			{
				ans=min(ans,cnt);
				cnt=0;
				num=num1;
			}
			
			else if(arr[i]==num2&&num==num1)
			{
				ans=min(ans,cnt);
				cnt=0;
				num=num2;
			}
			
			else if(arr[i]==num1||arr[i]==num2)
			{
				cnt=0;
				num=arr[i];
			}
			
			else
				cnt++;
		
		}
		
		cout<<ans+1;
	}
}
