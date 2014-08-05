//#include<bitset>
//#include<vector>
#include<stdio.h>

//#define MAX 1000005
//#define NUM 1000
//#define SIZE 80000

//std::vector<int> arr(MAX);

int main()
{
/*	int i;
	bool flag=true;
	
	for(int j=4;j<MAX;j+=2)
		arr[j]=2;

	for(int j=9;j<MAX;j+=6)
		arr[j]=3;
	
	for(i=5;i<NUM;)
	{
		if(!arr[i])
		{
			for(int j=i*i, k=(i<<1);j<MAX;j+=k)
				arr[j]=i;
		}
		
		if(flag)
			i+=2;
		else
			i+=4;
			
		flag^=true;
	}
	
//	for(int i=0;i<=400;i++)
//			printf("%d ",arr[i]);

*/	int t,n;
	scanf("%d",&t);

//	std::bitset<MAX> ans;
	
	while(t--)
	{
		
		scanf("%d",&n);
		printf("%d\n",((n+1)>>1));
	}
	//	scanf("%d",&n);
	
/*	for(int na=2;na<1000005;na++)
	{
		n=na;
		ans.reset();
		int cnt=0;
		
		int n1;
		
		while(n>=2)
		{
			if(ans[n])
			{
				--n;
				continue;
			}
			
			n1=n;
			
			cnt++;

			while(1)
			{
				ans[n]=1;
				if(!arr[n])
					break;
				n=(n/arr[n]);
			}
			
			n=n1-1;		
		}
		
		if(cnt!=(na+1)/2)
			printf("%d:%d\n",cnt,na);
	}
	}*/
	
	return 0;

}
