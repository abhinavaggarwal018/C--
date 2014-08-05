#include<iostream>
#include<cstring>

using namespace std;

void print_interleaved(char str1[], char str2[], char str[],int i1, int i2, int n, int n1, int n2)
{
	if(i1==n1 && i2==n2)
	{
		cout<<str<<"\n";
		return;
	}
	
	if(i1<n1)
	{
		str[n]=str1[i1];
		str[n+1]='\0';
		print_interleaved(str1,str2,str,i1+1,i2,n+1,n1,n2);
	}

	if(i2<n2)
	{
		str[n]=str2[i2];
		str[n+1]='\0';
		print_interleaved(str1,str2,str,i1,i2+1,n+1,n1,n2);
	}
}

bool is_interleaved(char str1[], char str2[], char str[],int i1, int i2, int i, int n1, int n2)
{
	if(i1==n1 &&i2==n2)
		return true;
	
	if(i1<n1 && i2<n2)
	{
		if(str[i]==str1[i1] && str[i]==str2[i2])
			return is_interleaved(str1,str2,str,i1+1,i2,i+1,n1,n2)||is_interleaved(str1,str2,str,i1,i2+1,i+1,n1,n2);
			
		if(str[i]==str1[i1])
			return is_interleaved(str1,str2,str,i1+1,i2,i+1,n1,n2);
		
		if(str[i]==str2[i2])
			return is_interleaved(str1,str2,str,i1,i2+1,i+1,n1,n2);
			
		else
			return false;
	}
	
	if(i1<n1)
	{
		if(str[i]==str1[i1])
			return is_interleaved(str1,str2,str,i1+1,i2,i+1,n1,n2);
		
		else
			return false;
	}

	if(i2<n2)
	{
		if(str[i]==str2[i2])
			return is_interleaved(str1,str2,str,i1,i2+1,i+1,n1,n2);
		
		else
			return false;
	}

}

int main()
{
	char str1[1000],str2[1000],str[1000]="";
	cin>>str1;
	cin>>str2;
	cin>>str;
	
	if(strlen(str)!=(strlen(str1)+strlen(str2)))
	{
		cout<<false;
		return false;
	}
	
	cout<<is_interleaved(str1,str2,str,0,0,0,strlen(str1),strlen(str2));
	//print_interleaved(str1,str2,str,0,0,0,strlen(str1),strlen(str2));
}
