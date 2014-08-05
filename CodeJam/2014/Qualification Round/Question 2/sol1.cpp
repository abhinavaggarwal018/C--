#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

double c,x,f;

struct cookie
{
	double count;
	double time;
	double rate;
	
	cookie(double count1, double time1, double rate1)
	{
		count=count1;
		time=time1;
		rate=rate1;
	}
	
};

bool operator<(const cookie& lhs, const cookie& rhs)
{
  return lhs.time > rhs.time;
}


double func()
{
	priority_queue<struct cookie> s;
	
	s.push(cookie(0,0,2));
	
	if(c>x)
		return x/2;
	
	cookie c1(0,0,0);
	
	while(true)
	{
		c1=s.top();
		s.pop();
		
		if(c1.count>=x)
			break;
					
		s.push(cookie(x,c1.time + x/c1.rate,c1.rate));
		s.push(cookie(0,c1.time + c/c1.rate,c1.rate+f));
	}
	
	while(!s.empty())
		s.pop();
		
	return c1.time;
	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int t,n;
	double arr1[1005],arr2[1005];
	
	cin>>t;
	
	for(int j=0;j<t;j++)
	{

		cin>>c>>f>>x;
		
		printf("Case #%d: %.7f\n",j+1,func());
	}
}
