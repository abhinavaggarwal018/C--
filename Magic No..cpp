#include<iostream>

using namespace std;

int n4, n7;
char ans[12]={'A'};
int cnt;

void update_ans(int cnt1)
{
//	cout<<cnt1<<ans[cnt1]<<"\n";
	if(ans[cnt1]=='A')
	{
		ans[cnt1]='4';
		n4++;
		cnt=cnt1+1;
		return;
	}	
	
	if(ans[cnt1]=='4')
	{
		n4--;
		n7++;
		ans[cnt1]='7';
		return;
	}
	
	else
	{
		n7--;
		n4++;
		ans[cnt1]='4';
		return update_ans(cnt1+1);
	}
}

void magic_no(int n, int cnt1)
{
	if(n==0)
	{
		cnt=cnt1;
		return;
	}
	
	int val=n%10;
	magic_no(n/10,cnt1+1);
	
	if(val<=4)
	{
		ans[cnt1]='0'+4;
		n4++;
	}
	
	else if(val<=7)
	{
		ans[cnt1]='0'+7;
		n7++;
	}
	
	else
	{
		ans[cnt1]='0'+4;
		n4++;
		update_ans(cnt1+1);
	}
}

void update()
{
//	cout<<n4<<n7;
	
	if(n4==n7)
		return;
		
	int i=0;
	while(n4>n7)
	{
		if(ans[i]=='4')
		{
			ans[i]='7';
			n4--;
			n7++;
		}
		
		i++;
	}
	
	while(n4<n7)
	{
		while(n4!=n7)
		{
			if(ans[i]=='4')
			{
				ans[i]='7';
				n4--;
				n7++;
				break;
			}
			
			if(ans[i]=='A')
				break;
			i++;
		
		}
		
		while(n4!=n7)
		{
			if(ans[i]=='7')
			{
				ans[i]='4';
				n7--;
				n4++;
			}
			
			else if(ans[i]=='A'||ans[i])
			{
				ans[i]='4';
				n4++;
			}
			
			i++;
		}
		
		cnt=max(i,cnt);
	}
}

int main()
{
	long long int n;
	n4=0;n7=0;
	
	cin>>n;
	
	for(int i=12;i>=0;i--)
		ans[i]='A';
		
	magic_no(n,0);
	
//	for(int i=cnt-1;i>=0;i--)
//		cout<<ans[i];
		
	n4=0;
	n7=0;
	
	for(int i=0;i<cnt;i++)
	{
		if(ans[i]=='4')
			n4++;
		else
			n7++;
	}
		
	if(cnt%2==1)
	{
		ans[cnt]='4';
		n4++;
		cnt++;
	}
//	for(int i=cnt-1;i>=0;i--)
//		cout<<ans[i];

	
	update();
	
	for(int i=cnt-1;i>=0;i--)
		cout<<ans[i];
}
