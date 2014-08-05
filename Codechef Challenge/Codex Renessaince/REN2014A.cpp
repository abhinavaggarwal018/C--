#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int num(char str[], int len, int base)
{
	int ans=0;
	for(int i=0;i<len;i++)
		ans=ans*base + (str[i]-'0');
		
	return ans;
}

int main()
{
	int t,base1,base2;
	char str1[10],str2[10];
	
	scanf("%d",&t);
	
	while(t--)
	{
		base1=2;
		base2=2;
		scanf("%s %s",str1,str2);
		
		for(int i=0;i<strlen(str1);i++)
			base1=max(base1,str1[i]-'0'+1);

		for(int i=0;i<strlen(str2);i++)
			base2=max(base2,str2[i]-'0'+1);
			
		printf("%d\n",num(str1,strlen(str1),base1)+num(str2,strlen(str2),base2));
		
	}
}
