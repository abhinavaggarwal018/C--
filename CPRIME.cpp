#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

#define MAX 100000005
#define SIZE 20000000

bool arr[MAX];
int val[SIZE];
int cnt;

bool check_prime(int n)
{
	for(int i=2;i<sqrt(n);i++)
		if(!(n%i))
			return false;
	
	return true;
}

void mark_all(int i)
{
	for(int j=i*i;j<MAX;j+=i)
		arr[j]=1;
}

void display()
{
	for(int i=0;i<cnt;i++)
	{
		cout<<val[i];
//		getchar();
	}
}

void update()
{
	for(int i=2;i<MAX;i++)
		if(!arr[i])
		{		
			val[cnt]=i;
			cnt++;
		}
		
	cout<<cnt;
//	cout<<val[0];
}

/*int b_search_ceil(int start, int end, int num)
{
	if(start>=end)
		return start;
		
	if(arr[start]==num)
		return start;
		
	int mid= start+(end-start)/2;
	
	if(arr[mid]==num)
		return mid;
		
	if(arr[mid]<num)
		b_search_ceil
	
	
}

int b_search_floor(int start, int end, int num)
*/

int b_search(int start, int end, int num)
{
//	cout<<start<<"::"<<end<<"\n";
//	getchar();
	if(start==end || start==end-1)
	{
	
		if(val[start]>num)
			return start-1;
			
		if(val[start+1]>num)
			return start;
			
		if(val[start+2]>num)
			return start+1;
	
	}
		
	int mid= start+(end-start)/2;
	
	if(val[mid]==num)
		return mid;
		
	if(val[mid]<num)
		return b_search(mid,end,num);
	
	if(val[mid]>num)
		return b_search(start,mid-1,num);
}

int main()
{
	int NUM=sqrt(MAX),n;
	
	arr[0]=1;
	arr[1]=1;
	
	for(int i=4;i<NUM;i+=2)
		arr[i]=1;
		
	for(int i=9;i<NUM;i+=6)
		arr[i]=1;
		
	bool flag=true;
	
	for(int i=5;i<NUM;)
	{
		if(!arr[i])
			mark_all(i);
			
		if(flag)
		{
			flag=0;
			i+=2;
		}
		
		else
		{
			flag=1;
			i+=4;
		}
	}
	
	update();
	
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
			
		float calc;
		
		if(n==2)
			calc=1;
			
		else if(n==val[cnt-1])
			calc=cnt;
			
		else
			calc=b_search(0,cnt,n)+1;
			
		printf("%.1f\n",abs((float)calc - (float)(n/log(n)))/(float)calc *100);
	}
	
/*	if(n<=2)
		n1=0;
		
	else
		n1=b_search_ceil(0,cnt,n);
		
		
	if(n>=val[cnt-1])
		n2=cnt-1;
		
	else
		n2=b_search_floor(0,cnt,n);


	
	float calc=n2-n1+1;
	calc=(float)calc -  
*/	
}
