/* You are given 3 integer arrays A, B and C of length n1, n2 and n3 respectively.
All arrays are sorted.
We define triplet of these 3 arrays as (x,y,z) where x is any integer from A, y from B and z from C.
We define distance of triplet as maximum difference among triplet elements, i.e. Maximum of x – y, y – z or z – x.
Write a program to find minimum triplet distance.
(means there are n1*n2*n3 number of possible triplets are possible...
among all triplets which triplet has minimum distance...
Give only distance, but not triplet elements).
Your program must be as much efficient as possible.*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using  namespace std;

int main()
{
	int x[100],y[100],z[100],n1,n2,n3,a,b,c;
	scanf("%d %d %d",&n1,&n2,&n3);
	for(int i=0;i<n1;i++)
		scanf("%d",&x[i]);
	for(int i=0;i<n2;i++)
		scanf("%d",&y[i]);
	for(int i=0;i<n3;i++)
		scanf("%d",&z[i]);

	int i1=0,i2=0,i3=0;
	a=10000;
	while(i1<n1&&i2<n2)
	{
		if(x[i1]>y[i2])
		{
			if(a>(x[i1]-y[i2]))
				a=x[i1]-y[i2];
			i2++;
		}
				
		if(x[i1]<y[i2])
		{
			if(a>(y[i2]-x[i1]))
				a=y[i2]-x[i1];
			i1++;
		}
		if(x[i1]==y[i2])
		{
			cout<<"Equal for i1 and i2:"<<i1<<"\t Arr[i1]="<<x[i1]<<"\t i2:"<<i2<<"\t Arr[i2]="<<y[i2];
			a=0;
			break;		
		}
	}

	i1=0;i2=0;i3=0;
	b=10000;
	while(i2<n2&&i3<n3)
	{
		if(y[i2]>z[i3])
		{
			if(b>(y[i2]-z[i3]))
				b=y[i2]-z[i3];
			i3++;
		}
				
		if(y[i2]<z[i3])
		{

			if(b>(z[i3]-y[i2]))
				b=z[i3]-y[i2];
			i2++;
		}
		if(y[i2]==z[i3])
		{
			cout<<"Equal for i2 and i3:"<<i2<<i3;
			cout<<"Equal for i2 and i3:"<<i2<<"\t Arr[i1]="<<y[i2]<<"\t i3:"<<i3<<"\t Arr[i3]="<<z[i3];
			b=0;
			break;
		}
	}
	i1=0;i2=0;i3=0;
	c=10000;
	while(i1<n1&&i3<n3)
	{
		if(x[i1]>z[i3])
		{
			if(c>(x[i1]-z[i3]))
				c=x[i1]-z[i3];
			i3++;
		}
				
		if(x[i1]<z[i3])
		{
			if(c>(z[i3]-x[i1]))
				c=z[i3]-x[i1];
			i1++;
		}
		if(x[i1]==z[i3])
		{
			cout<<"Equal for i1 and i3:"<<i1<<"\t Arr[i1]="<<x[i1]<<"\t i3:"<<i3<<"\t Arr[i3]="<<z[i3];
			cout<<"Equal for i1( and i3:"<<i1<<i3;
			c=0;
			break;
		}
	}
	cout<<"\n\n\n"<<a<<"\n"<<b<<"\n"<<c<<"\n";
	cout<<max(a,max(b,c));
	return 0;
}
