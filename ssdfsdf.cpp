#include<iostream>

using namespace std;

char* StrCat(char *s1,char *s2)
{

char buffer[1024];

int i=0;

while(*s1)

{

buffer[i++]=*s1;

s1++;

}

while(*s2)

{

buffer[i++]=*s2;

s2++;

}

return buffer;

}

int main()
{
	cout<<StrCat("abh","inav");
}
