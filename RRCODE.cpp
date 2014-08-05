#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int n,k,ans,arr[1050];
		string str;
		
		scanf("%d %d %d",&n,&k,&ans);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		cin>>str;
		
		if(str=="XOR")
		{
			if(!(k&1))
				printf("0\n");
			else
			{
				for(int i=0;i<n;i++)
					ans^=arr[i];
					
				printf("%d\n",ans);
			}
		}
		
		else if(str=="AND")
		{
			for(int i=0;i<n;i++)
			{
				ans&=arr[i];
				if(!ans)
					break;
			}
			
			printf("%d\n",ans);
		}
		
		else if(str=="OR")
		{
			for(int i=0;i<n;i++)
				ans|=arr[i];
			
			printf("%d\n",ans);
		}
	}
}
