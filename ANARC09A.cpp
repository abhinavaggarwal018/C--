#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[2005];
	int ctr=0;
	while(1)
	{
		ctr++;
		cin>>str;
		int len=strlen(str);
		if(str[len-1]=='-')
		return 0;
		int num=0;
		int left_count=0;
		int right_count=0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]=='{')
			left_count++;
			else if(str[i]=='}')
			right_count++;
			
			if(left_count<right_count && left_count<len/2)
			{
				//cout<<"CASE1"<<"\t"<<left_count<<"\t"<<right_count<<"\t"<<num<<"\n";
				num++;
				left_count++;
				right_count--;
			}
			
			else if(left_count<right_count && left_count>=len/2)
			{
				//cout<<"CASE2"<<"\t"<<left_count<<"\t"<<right_count<<"\t"<<num<<"\n";
				//Impossible case 
			}
			
			else if(right_count<left_count && left_count<=len/2)
			{
				//cout<<"CASE3"<<"\t"<<left_count<<"\t"<<right_count<<"\t"<<num<<"\n";
				//Normal Case Do nothing
			}
			else if(right_count<left_count && left_count>len/2) // left count cannot be >len/2 It can only be equal
			{
				//cout<<"CASE4"<<"\t"<<left_count<<"\t"<<right_count<<"\t"<<num<<"\n";
				num++;
				left_count--;
				right_count++;
			}			
		
		}
		cout<<ctr<<". "<<num<<"\n";
		
	}
}
