#include<abhinav.h>

using namespace std;

int swap_arr(int start,int end, char arr[])
{
	int mid=start + (end-start)/2;
	
	for(int i=start;i<=mid;i++)
	{
		char temp=arr[i];
		arr[i]=arr[end+start-i];
		arr[end+start-i]=temp;
	}
}
int main()
{
	char str[]="I am Abhinav Aggarwal";
	int n=strlen(str);
	
	int start=0,flag=0;
	
	for(int i=0;i<n;i++)
	{
		if(str[i]==' '&&flag==0)
		{
			swap_arr(start,i-1,str);
			flag=1;
			cout<<start<<" "<<i-1<<"\n";
			printf("%s\n",&str);
		}
		
		else if(flag==1)
		{
			start=i;
			flag=0;
		}
	}
	
	swap_arr(start,n-1,str);
	
	printf("%s",&str);
}
