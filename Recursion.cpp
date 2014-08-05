#include<iostream>

using namespace std;

void find_combinations(char arr[], int k, int n, char str[], int pos)
{
	if(k==pos)
	{
		cout<<str<<"\n";
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
//		cout<<pos<<i;
		str[pos]=arr[i];
		str[pos+1]='\0';
		find_combinations(arr,k,n,str,pos+1);
	}
	
	return;
	
}

void make_groups(char arr[], int k, int n, char str[], int pos, int start)
{
	if(pos==k)
	{
		cout<<str<<"\n";
		return;
	}
	
	if(start > n)
	return;
		
	for(int i=start;i<n;i++)
	{
		str[pos]=arr[i];
		str[pos+1]='\0';
		
		make_groups(arr,k,n,str,pos+1,i+1);
		
		while(i<n && arr[i]==arr[i+1])
			i++;
	}
}

int main()
{
	char arr[1000],str[1000]="";
	int k,n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	
	make_groups(arr,k,n,str,0,0);
	
	//find_combinations(arr,k,n,str,0);
	
	
}
