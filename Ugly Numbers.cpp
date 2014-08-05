/*
	
Ugly Numbers
July 11, 2009

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150?th ugly number.
*/

#include<iostream>

using namespace std;

long long int n,arr[1000],next_multiple_of_2,next_multiple_of_3,next_multiple_of_5,curr_index,i2,i3,i5;

long long int ugly(int n)
{
	if(arr[n-1]!=0)
		return arr[n-1];
		
	for(int i=curr_index;i<n;i++)
	{
		arr[i]=min(min(next_multiple_of_2,next_multiple_of_3),next_multiple_of_5);
		
		if(arr[i]==next_multiple_of_2)
		{
			i2++;
			next_multiple_of_2=2*arr[i2];
			curr_index++;
		}
		
		if(arr[i]==next_multiple_of_3)
		{
			i3++;
			next_multiple_of_3=3*arr[i3];
			curr_index++;
		}
		
		if(arr[i]==next_multiple_of_5)
		{
			i5++;
			next_multiple_of_5=5*arr[i5];
			curr_index++;
		}
	}
		
	return arr[n-1];
}

int main()
{
	arr[0]=1;
	next_multiple_of_2=2;// represent indexes
	next_multiple_of_3=3;
	next_multiple_of_5=5;
	i2=0;i3=0;i5=0;
	curr_index=1;
	while(1)
	{
		cin>>n;
		cout<<ugly(n)<<"\n";
	}
}

/*#include<iostream>

using namespace std;

int main()
{
	int i2=0,i3=0,i5=0,i=0,ugly[155]={0};
	
	ugly[0]=1;
	i=1;
	
	while(i<150)
	{
		ugly[i]=min(ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
		
		if(ugly[i2]*2==ugly[i])
			i2++;
		
		if(ugly[i3]*3==ugly[i])
			i3++;
		
		if(ugly[i5]*5==ugly[i])
			i5++;
			
		i++;
	}
	
	cout<<ugly[149];
	5832
}*/

# include<stdio.h>
# include<stdlib.h>
# define bool int
 
/* Function to find minimum of 3 numbers */
unsigned min(unsigned , unsigned , unsigned );
 
/* Function to get the nth ugly number*/
unsigned getNthUglyNo(unsigned n)
{
    unsigned *ugly =
             (unsigned *)(malloc (sizeof(unsigned)*n));
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned i;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
    *(ugly+0) = 1;
 
    for(i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           next_multiple_of_3,
                           next_multiple_of_5);
       *(ugly+i) = next_ugly_no;                   
       if(next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;      
           next_multiple_of_2 = *(ugly+i2)*2;
       }
       if(next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = *(ugly+i3)*3;
       }
       if(next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = *(ugly+i5)*5;
       }
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
 
/* Function to find minimum of 3 numbers */
unsigned min(unsigned a, unsigned b, unsigned c)
{
    if(a <= b)
    {
      if(a <= c)
        return a;
      else
        return c;
    }
    if(b <= c)
      return b;
    else
      return c;
}
 
/* Driver program to test above functions */
int main()
{
    unsigned no = getNthUglyNo(150);
    printf("%dth ugly no. is %d ", 150, no);
    getchar();
    return 0;
}
