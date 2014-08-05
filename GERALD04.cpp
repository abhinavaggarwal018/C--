#include<iostream>

using namespace std;

int main()
{
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	
	int time=(h1-h2)*60+(m1-m2);
	
	scanf("%d",&dist);
	
	printf("%d",time+dist);
	
	ans=0;
	ans+=dist;
	time-=dist;
}
