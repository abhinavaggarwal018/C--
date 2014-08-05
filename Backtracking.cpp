#include<iostream>

using namespace std;

void swap(char *a, char *b)
{
	char *c=a;
	*a=*b;
	*b=*c;
}

void permute(string str, int pos, int n)
{
	if(pos==n)
		cout<<str<<"\n";
		
	for(int i=pos;i<n;i++)
	{
		swap(str[pos],str[i]);
		permute(str, pos+1, n);
		swap(str[pos],str[i]);
	}
}

int main()
{
	string str;
	cin>>str;
	permute(str, 0, str.length());
}
