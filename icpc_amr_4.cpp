    #include <iostream>
    #include<cstdio>
    using namespace std;
    int a[500][4], r[500], d[500];
    int max(int a, int b, int c)
    {
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
    }
    int min(int a, int b, int c)
    {
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
    }
     
    int cost(int i)
    {
    int sum=0,j;
    for(j=0;j<3;++j)
    {
    sum=sum+max(a[i][j],a[i-1][j],a[i-2][j])-min(a[i][j],a[i-1][j],a[i-2][j]);
    }
    return sum;
    }
     
     
    int cost_val(int i)
	{
		if(i==0)
			return max(a[0][0],a[0][1],a[0][2])-min(a[0][0],a[0][1],a[0][2]);
			
		if(i==1)
			return min(dp[0] + max(a[0][0],a[0][1],a[0][2])-min(a[0][0],a[0][1],a[0][2]),(max(a[0][0],a[0][1],a[1][0])-min(a[0][0],a[0][1],a[1][0]))+(max(a[0][2],a[1][1],a[1][2])-min(a[0][2],a[1][1],a[1][2])),);
	} 
    int main()
    {
	    int i,j,k,n,t,ro,co;
	    scanf("%d",&t);
	    
		while(t--)
	    {
	    	scanf("%d",&n);
	    	for(i=0;i<n;++i)
	    	{
	    		for(j=0;j<3;++j)
	    		{
	    			scanf("%d",&a[i][j]);
	    		}
	    	}
	    	
	    	
	    r[0]=d[0]=max(a[0][0],a[0][1],a[0][2])-min(a[0][0],a[0][1],a[0][2]);
	     
	    if(n>=2)
	    {
	    	d[1]=r[1]=r[0]+min(max(a[1][0],a[1][1],a[1][2])-min(a[1][0],a[1][1],a[1][2]);
	     
	    if(n>=3)
	    {
	    	r[2]=d[1]+max(a[2][0],a[2][1],a[2][2])-min(a[2][0],a[2][1],a[2][2]);
	    	co=cost(2);
	    	if(co<=r[2]) 
				d[2]=co;
	    	else 
				d[2]=r[2];
	    
			for(i=3;i<n;++i)
	    	{
	    		r[i]=d[i-1]+max(a[i][0],a[i][1],a[i][2])-min(a[i][0],a[i][1],a[i][2]);
	    		co=d[i-3]+cost(i);
	    		
				if(co<=r[i]) 
					d[i]=co;
	    		else 
					d[i]=r[i];
	    	}
	    }
	    
		}
     
    printf("%d\n",d[n-1]);
    }
    return 0;
    }
    
    
ppp
qqq
rrr

xxx
PPQ
PQQ

xxx
pqq
ppq

ppq
pqq
xxx

pqq
ppq
xxx

pqr
pqr
pqr
