#include<stdio.h>// Time Limit Exceeded
//using namespace std;
char a,input[100005],output[100005];
int n,count[4]={0},flag=0;
void dfs(int num)
{
	bool dig_possible[4]={true,true,true,true};
	for(int i=0;i<4;i++)
	{
		if(input[num]=='A'+i)
			{
			//	cout<<"Making "<<char('A'+i)<<" false through input array\n";
				dig_possible[i]=false;
			}
		if(num>0 && output[num-1]=='A'+i)
			{
			//	cout<<"Making "<<char('A'+i)<<" false through input array\n";
				dig_possible[i]=false;
			}
	}
	/*for(int i=0;i<4;i++)
	{
		if(dig_possible[i]==true && count[i]>0)
		cout<<char('A'+i)<<1;
		else
		cout<<char('A'+i)<<0;
	}
	cout<<"\n";*/
	for(int i=0;i<4;i++)
	{
		if(dig_possible[i]==true && count[i]>0)
		{
			count[i]--;
			output[num]=char('A'+i);
			//cout<<"output["<<num<<"]="<<char('A'+i);
			if(num==(2*n) - 1)
			{
				flag=1;
				return;		
			}
			dfs(num+1);
			if(flag==1)
			return;
			count[i]++;
		}
	}
	
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<4;i++)
		count[i]=n;
	scanf("%s",input);
	//printf("%s",input);
	for(int i=0;i<2*n;i++)
	{
		a=input[i];
		switch(a)
		{
			case 'A':  	count[0]--;
						break;	
			case 'B':  	count[1]--;
						break;
			case 'C':  	count[2]--;
						break;
			case 'D':  	count[3]--;
						break;		
		}
	}
	/*for(int i=0;i<4;i++)
	{
		cout<<char('A'+i)<<n-count[i];
	}*/
	//cout<<"\n";
	dfs(0);
	output[2*n]=='\0';
	printf("%s",output);
	//cout<<output;
}
