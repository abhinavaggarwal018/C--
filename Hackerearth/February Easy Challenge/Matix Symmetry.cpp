#include<cstdio>

int main()
{
	int test,n;
	char t[55][55];
	bool ans1,ans2;
	
	scanf("%d",&test);
	
	while(test--)
	{
		ans1=true;
		ans2=true;
		
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("\n%s",&t[i]);
		
		for(int i=0;i<n && ans1;i++)
		{
			for(int j=0;j<n/2 && ans1;j++)
			{
				if(t[i][j]!=t[i][n-j-1])
					ans1=false;
			}
		}

		for(int i=0;i<n/2 && ans2;i++)
		{
			for(int j=0;j<n && ans2;j++)
			{
				if(t[i][j]!=t[n-i-1][j])
					ans2=false;
			}
		}
					
		
		if(ans1&ans2)
			printf("BOTH\n");
			
		else if(ans1)
			printf("VERTICAL\n");
		
		else if(ans2)
			printf("HORIZONTAL\n");
			
		else
			printf("NO\n");
	}
}
