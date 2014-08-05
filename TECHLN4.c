#include<stdio.h>
//long long int cnt;
int find_cnt(int x1,int y1,int x2,int y2)
{
	int a,b;
	a=(x2+x1)/2;
	b=(y2+y1)/2;
	if(((x1-a)==(a-x2))&&((y1-b)==(b-y2)))
		{
			return find_cnt(x1,y1,a,b) + find_cnt(a,b,x2,y2) +1;
		}
	return 0;
}
int main()
{
	int t,x1,y1,x2,y2,l;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		//cnt=0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("Case #%d: %lld\n",l+1,find_cnt(x1,y1,x2,y2));
	}
	return 0;
}
