#include<iostream>
#include<cassert>

using namespace std;

long long cnt=0;
char arr[10];

void calc(int val, int iter)
{
	if(iter==6)
	{
		cnt++;
		return;
	}
	
	for(int i=val;i>=0;i--)
		calc(i,iter+1);
}

void find(int val, int iter, long long int &num)
{
	if(iter==6)
	{
		if(num)
			num--;
			
		else
		{
			cout<<arr;
			assert(0);
		}
			return;
	}
	
	for(int i=val;i>=0;i--)
	{
		arr[iter]=val+'0';
		find(i,iter+1,num);
	}
}


int main()
{
	long long int cnt=0;
	
	for(int i=0;i<=1000;i++)
	{
		for(int j=i;j<=1000-i;j++)
		{
			for(int k=j;k<=1000-(i+j);k++)
			{
				for(int l=k;l<=1000-(i+j+k);l++)
				{
					if((1000-(i+j+k+l))>=l)
						cnt++;
				}
			}
		}
	}
	
	cout<<cnt;
	cin>>cnt;
	
	for(int i=0;i<100;i++)
		cout<<i<<"\n";
	
	calc(9,0);
//	cout<<cnt;
	cnt=cnt-2003;
	find(9,0,cnt);
//	long long cnt=0;
	
/*	for(int i=0;i<=1000;i++)
	{
		for(int j=i;j<=1000-i;j++)
		{
			for(int k=j;k<=1000-(i+j);k++)
			{
				for(int l=k;l<=1000-(i+j+k);l++)
				{
					if((1000-(i+j+k+l))>=l)
						cnt++;
				}
			}
		}
	}
	
	cout<<cnt;*/
	
	//for(int i=0;i<2014;i++)
	//	cnt+=(i*(i+1));
	
//	cout<<cnt;

}
