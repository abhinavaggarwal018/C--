#include<cstdio>

int main()
{
	int h,m,sh,sm;
	scanf("%d:%d",&h,&m);
	scanf("%d:%d",&sh,&sm);

	m=m-sm;
	h=h-sh;
	if(m<0)
	{
		m=m+60;
		h=h-1;
	}
	
	if(h<0)
		h=h+24;
	
	if(h>=10 && m>=10)
		printf("%d:%d\n",h,m);
	else if(h>=10)
		printf("%d:0%d\n",h,m);
	else if(m>=10)
		printf("0%d:%d\n",h,m);
	else
		printf("0%d:0%d\n",h,m);
}
