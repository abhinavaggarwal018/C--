#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char str[20],str1[20];
int ans=1000,cnt=1000,len,kill_task=0;

int toggle(int a)
{
	if(str[a]=='1')
		str[a]='0';
	else
		str[a]='1';
}

int swap_index(int a)
{
	if(a!=0)
		toggle(a-1);
	toggle(a);
	if(a!=len-1)
		toggle(a+1);

}

int find_ans()
{
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='1')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		if(ans>cnt)
			{
				ans=cnt;
				kill_task=1;
			}
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
		strcpy(str1,str);
		len=strlen(str);
		
		int num=0;
		
		 //For storing number from input as a number
/*		for(int i=len-1;i>=0;i--)
			if(str[i]=='1')
			{
				int num2 =  1<<(len-1-i);
				num = num + num2;
			}
*/			
		num1=1<<len;
		num=num1-1;
		kill_task=0;
				
		while ( num >= 0 && kill_task==0)
		{
			strcpy(str,str1);
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
			find_ans();
			num--;
		}
		if(ans==1000)
		ans=-1;
		printf("%d\n",ans);

	}
}

