#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char str[100];
int len,bit_mask;

void swap_ptr(char *c,char *c1)
{
	char ch;
	ch=*c;
	*c=*c1;
	*c1=ch;
}
char lastChar=0;
void permute(char *c,int i,int len)
{/*
	if(i==len)
	{
		printf("%s->",c);
		return;
	}
	//cout<<"1";
	for(int i1=i;i1<len;i1++)
	{
		swap_ptr(&c[i],&c[i1]);
		permute(c,i+1,len);
		swap_ptr(&c[i],&c[i1]);	
	}*/
    if( i == len )
    { // We have a permutation so print it
        printf("%s->",c);
        lastChar=0;
        return;
    }
    for( int i1 = i; i1 < len; i1++ )
    {
        if( lastChar == c[i] ) 
            cout<<"\n"<<lastChar<<c[i]<<"\n";
			//continue;
		else 
            lastChar = c[i];
		
		swap_ptr(&c[i],&c[i1]);
		permute(c,i+1,len);
		swap_ptr(&c[i],&c[i1]);    
	}
}

int main()
{
	cin>>str;
	len=strlen(str);
	permute(str,0,len);
	cout<<"END";
}
