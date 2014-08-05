#include<iostream>
//#include<stdio.h>
#include<limits.h>
using namespace std;
int t,r,c,cost,arr[505][505],back_dp[505][505];

int main()
{
	cin>>t;
	for(int l=0;l<t;l++)
	{
		for(int i=0;i<505;i++)
		for(int j=0;j<505;j++)
		{
			arr[i][j]=-10000;
			//dp[i][j]=-10000;
		}
		cost=0;
		//min_cost=10000;
		cin>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>arr[i][j];
		for(int i=0;i<r;i++)
		{
			back_dp[i][0]=arr[i][0];
	//		dp[i][c-1]=arr[i][c-1];
		}
		for(int j=0;j<c;j++)
		{
			back_dp[0][j]=arr[0][j];
	//		dp[r-1][j]=arr[r-1][j];
		}
	/*	for(int i=r-2;i>=0;i--)
			for(int j=c-2;j>=0;j--)
				dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j]);
	*/	
		for(int i=1;i<r;i++)
			for(int j=1;j<c;j++)
				back_dp[i][j]=arr[i][j]+max(arr[i-1][j],arr[i][j-1]);
	/*	cout<<"\ndp\n\n";
		for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<dp[i][j]<<" ";
				cout<<"\n";
			}*//*
		cout<<"\nback_dp\n\n";
		for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				cout<<back_dp[i][j]<<" ";
				cout<<"\n";
			}*/
//		cout<<"r: "<<r<<"c: "<<c<<"\n";
		/*while(1)
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
						if(back_dp[i+1][j]>=back_dp[i][j+1])
							i=i+1;
						else if(back_dp[i+1][j]<back_dp[i][j+1])
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
	}*/
		int i=r-1,j=c-1;
		while(1)
		{
				if(i==0&&j==0)
					break;
				
					//cout<<"i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
					if(i>0&&j>0)
					{
						if(back_dp[i-1][j]>=back_dp[i][j-1])
							i=i-1;
						else
							j=j-1;
					}
					else if(j>0)
						j=j-1;
					else
						i=i-1;
				cost+=arr[i][j];
				if(arr[i][j]<0)
					cost=arr[i][j];
//					cout<<"5i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
//					cout<<"4i:"<<i<<"\tj:"<<j<<"\tarr[i][j]"<<arr[i][j]<<"\tcost"<<cost<<"\tmin_cost"<<min_cost<<"\n";
				//getchar();
		}
		cost--;
		if(cost>=0)
		cost=-1;	
	cout<<-cost<<"\n";	
	}
	return 0;
}
