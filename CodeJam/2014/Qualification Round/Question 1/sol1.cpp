#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t,num;
	int arr[16],arr2[4][4];
	
	cin>>t;
	
	for(int k=0;k<t;k++)
	{

		for(int i=0;i<16;i++)
			arr[i]=0;
		
		cin>>num;
		
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>arr2[i][j];
				
		for(int i=0;i<4;i++)
			arr[arr2[num-1][i]-1]++;
		
		cin>>num;
		
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>arr2[i][j];
				
		for(int i=0;i<4;i++)
			arr[arr2[num-1][i]-1]++;

		int cnt=0,val=0;

		for(int i=0;i<16;i++)
		{
			if(arr[i]==2)
			{
				cnt++;
				val=i;
			}
		}

		if(cnt==1)
			printf("Case #%d: %d\n",k+1,val+1);
			
		if(cnt==0)
			printf("Case #%d: Volunteer cheated!\n",k+1);

		if(cnt>1)
			printf("Case #%d: Bad magician!\n",k+1);
			
	}
}
