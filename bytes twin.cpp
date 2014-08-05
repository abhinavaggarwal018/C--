#include<stdio.h>
#include<string.h>
char str[1000005];
long long int a=0;
bool flag[1000005]={false};
bool possible=true;
char ans[1000005];
int t;
char c;
void 
twin_check(int start1,int start2)
{
		int len=strlen(str);
		c=str[start1];
		flag[start1]=true;
		for(int i=start2;i<len;i++)
		{
			for(i=0;i<len;i++)
			{
				if(flag[i]==false)
				{
					possible=false;
					return ;
				}
			}
			if(i==len)
			{
				possible=false;
				return;
			}
			if(str[i]==c && flag[i]==false)
			{
				ans[a]=c;
				a++;
				flag[i]=true;
				for(int i1=0;i1<len;i1++)
				{
				if(flag[i1]==false)
				twin_check(i1,i);
				}
				break;
			}
			
		}
}

int main()
{

	scanf("%d",&t);
	for(int i2=0;i2<t;i2++)
	{
		a=0;
		scanf("%s",&str);
		twin_check(0,1);
		if(possible==false)
		{
		printf("Twins don't exist");
		}
		else
		{
			for(int i=0;i<a;i++)
		printf("%d",ans[i]);
		}
	}
}
