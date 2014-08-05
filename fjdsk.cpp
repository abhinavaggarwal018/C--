#include<iostream>
using namespace std;
int main(){
	int a[1001],j;
	a[1]=1;
	a[2]=1;
	for(j=3;j<=1000;j++)
	{
		a[j]=a[j-1]+a[j-2];
		if(a[j]>1000)
			break;
	}
	
	for(int i=1;i<=j-1;i++)
	{
		cout<<a[i]<<" \n";
	}
	
	return 0;
}
