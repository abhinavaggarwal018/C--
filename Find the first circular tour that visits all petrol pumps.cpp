#include<iostream>

using namespace std;

int main()
{
	int petrol[100],dist[100],n,start,avail=0;
	while(1)
	{
		start=0;
		avail=0;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>petrol[i];
			cin>>dist[i];
		}
		
		for(int i=0;i<n;i++)
		{
			avail=avail+petrol[i]-dist[i];
			if(avail<0)
			{
				avail=0;
				start=i+1;
			}
		}

		cout<<start;
		
		for(int i=0;i<start;i++)
		{
			avail=avail+petrol[i]-dist[i];
			if(avail<0)
			{
				cout<<"IMPOSSIBLE\n";
			}
		}
		cout<<start;
	}
}
