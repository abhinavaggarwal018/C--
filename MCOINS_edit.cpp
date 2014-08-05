#include<iostream>
#include<queue>
int k,l,m,temp,i,num[55];
#define MAX 1000006
char dp[MAX];

using namespace std;
int main()
{
	cin>>k>>l>>m;
	for(i=0;i<MAX;i++)
		dp[i]=' ';
	num_max=-100;
	for(int p=0;p < m;p++)
	{
		cin>>num[p];
		if(num[p]>num_max)
		num_max=num[p];
	}

		dp[1]='A';
		dp[k]='A';
		dp[l]='A';

		if(dp[num]==' ')
		{
			for(int i=temp;i<=num;i++)
			{
				if((i-k)>0)
				{
					if(dp[i]=='A')
						dp[i]='B';
					else dp[i]='A';
				}
				else if((i-l)>0)
				{
					if(dp[i]=='A')
						dp[i]='B';
					else dp[i]='A';
				}
				if((i-1)>0)
				{
					if(dp[i]=='A')
						dp[i]='B';
					else dp[i]='A';
				}
			}
				cout<<dp[num];
		}
		else cout<<dp[num];
	if(temp<num)
		temp=num+1;
	}
	return 0;
}
