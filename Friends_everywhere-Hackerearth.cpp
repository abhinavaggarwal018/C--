#include<iostream>
#include<stdio.h>
int arr[100005]={0};
using namespace std;
int main()
{
	int n,m,cnt_len,i,num1,num2;
	scanf("%d %d",&n,&m);
	int cnt[100005];
	cnt_len=0;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&num1,&num2);
		if(arr[num1]==2)
			arr[num2]=1;
		else if(arr[num1]==0)
			{
				arr[num1]=2;
				arr[num2]=1;
				cnt[cnt_len]=num1;
				cnt_len++;
			}
	}
	cout<<cnt_len<<"\n";
	for(int i=0;i<cnt_len;i++)
		printf("%d ",cnt[i]);
}
