#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int a,b,c;

int print()
{
	while(a--)
		cout<<'|';
	cout<<'+';
	while(b--)
		cout<<'|';
	cout<<'=';
	while(c--)
		cout<<'|';
		
		return 0;	
}


int main()
{

/*	int t,n;
	long long int arr[100005];

	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
	}
*/

	string str;
	
	cin>>str;
	
	int ind1 = str.find_first_of('+');
	int ind2 = str.find_first_of('=');

	a = ind1;
	b = ind2-ind1-1;
	
	c = str.length()-ind2-1;
	
	//cout<<a<<b<<c;
	
	if(a+b==c)
		return print();
	
	if(a + b == c-2)
	{
		a++;
		c--;
		return print();
	}

	if(a + b == c + 2)
	{
		a--;
		c++;
		return print();
	}
	
	cout<<"Impossible";
	
	return 0;
	
}


