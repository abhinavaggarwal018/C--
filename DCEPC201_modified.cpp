#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char str[20],str1[20];
int ans=1000,cnt=1000,len,kill_task=0,arr1;

int swap_index(int a)
{
	if(a!=0)
		arr1=arr1^(1<<(a-1));
		arr1=arr1^(1<<(a));
	if(a!=len-1)
		arr1=arr1^(1<<(a+1));
}

int main()
{

	int t, num1;
	scanf("%d",&t);
	while ( t-- )
	{
		ans=1000;
		cnt=1000;
		scanf("%s" ,&str);
		len=strlen(str);
		
		int num=0;
		int arr=0;
		 //For storing number from input as a number
		for(int i=len-1;i>=0;i--)
			if(str[i]=='1')
			{
				int num2 =  1<<(len-1-i);
				arr = arr + num2;
			}
			
		num1=1<<len;
		num=num1-1;
		kill_task=0;
				
		while ( num >= 0 && kill_task==0)
		{
			arr1=arr;
			num1=num;
			cnt=0;
			for(int i=0;num1!=0;i++)
			{
				if(num1&1==1)
				{
					cnt++;
					swap_index(i);
				}
				num1=num1>>1;
			}
			if( arr1==0)
			{
				ans=cnt;
				break;
			}
			num--;
		}
		if(ans==1000)
		ans=-1;
		printf("%d\n",ans);

	}
}

