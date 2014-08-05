#include <stdio.h>
int main()
{
int marksList[10];
int i;
int grace=5;
int flag=1;
for (i= 0; i< 10; i++)
{
scanf ("%d", &marksList[i]);

/* code expected here */

if(marksList[i]<0)
	flag=0;
    
if(flag==0)
	continue;

if(marksList[i]<50)
	printf ("%d ", marksList[i]+grace);
else
	printf ("%d ", marksList[i]);
}
return 0;
}
