#include<iostream>
#include<limits.h>
using namespace std;
int t,r,c,min_cost,cost,dp[505][505],arr[505][505];
bool check_optimal(int x,int y)
{
	//cout<<"Called for X: "<<x<<"\tY: "<<y<<"\n";
	int a,b,max_total=-10000,min1=10000,min_path=10000;
	bool flag;
	a=x;
	b=y;
	a++;
	while(1)
	{
		if(a==r-1&&b==c-1)
			{
				if(max_total<min_path)		
				{
					max_total=min_path;
					flag=true;
				}	
				break;
			}
	//					cout<<"i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
		if(dp[a+1][b]>dp[a][b+1])
			a=a+1;
		else if(dp[a+1][b]<dp[a][b+1])
			b=b+1;
		else 
		{
			if(check_optimal(a,b)==true)
				a=a+1;
			else
				b=b+1;
		}
		min1=dp[a][b];
		if(min_path>min1)
		min_path=min1;
		//cout<<min_path<<"-minpath\n";
	}
	a=x;
	b=y;
	b++;
	min_path=0;
	while(1)
	{	
		if(a==r-1&&b==c-1)
			{
				if(max_total<min_path)		
				{
					max_total=min_path;
					flag=false;
				}	
				break;
			}
	//					cout<<"i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
		if(dp[a+1][b]>=dp[a][b+1])
			a=a+1;
		else if(dp[a+1][b]<dp[a][b+1])
			b=b+1;
		else 
		{
			if(check_optimal(a,b)==true)
				a=a+1;
			else
				b=b+1;
		}
		min1=dp[a][b];
		if(min_path>min1)
		min_path=min1;
		//cout<<min_path<<"-minpath123\n";
	}
	//cout<<flag;
	return flag;
}

int main()
{
	
	cin>>t;
	for(int l=0;l<t;l++)
	{
		for(int i=0;i<505;i++)
		for(int j=0;j<505;j++)
		{
			arr[i][j]=-10000;
			dp[i][j]=-10000;
		}
		cost=0;
		min_cost=10000;
		cin>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>arr[i][j];
		for(int i=0;i<r;i++)
			dp[i][c-1]=arr[i][c-1];
		for(int j=0;j<c;j++)
			dp[r-1][j]=arr[r-1][j];
			
		for(int i=r-2;i>=0;i--)
			for(int j=c-2;j>=0;j--)
				dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j]);
		
		/*for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<dp[i][j]<<" ";
				cout<<"\n";
			}*/

		int i=0,j=0;

//		cout<<"r: "<<r<<"c: "<<c<<"\n";
		while(1)
			{
				
					if(i==r-1&&j==c-1)
						break;
					
//					cout<<"i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
					if(dp[i+1][j]>dp[i][j+1])
						i=i+1;
					else if(dp[i+1][j]<dp[i][j+1])
						j=j+1;
					else 
					{
						if(check_optimal(i,j)==true)
							i=i+1;
						else
							j=j+1;
					}
					cost+=arr[i][j];
//					cout<<"5i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
					if(cost<min_cost)
					min_cost=cost;
//					cout<<"4i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
			}
			min_cost--;
			if(min_cost>=0)
			min_cost=-1;	
		cout<<-min_cost<<"\n";	
	}
}
