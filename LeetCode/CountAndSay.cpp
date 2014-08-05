#include<iostream>
#include<string>

using namespace std;

string calc(string num, int n)
{
	if(n==0)
		return num;

	string str;
	
    int len=num.length();
    
    for(int i=0;i<len;)
    {
        char val=num[i] ;
        int j;
        
        for(j=1 ; (i+j)<len && num[j+i]==val ; j++);
        
        str=str + char(j+'0');
        str= str + val;
        i=i+j;
        
//        cout<<str<<"\n";
    }
    
    return calc(str,n-1);
}
string countAndSay(int n) {
    if(n>0)
    	return calc("1",n-1);
    else
    	return "";
}

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		cout<<countAndSay(n)<<"\n";

	}
}

