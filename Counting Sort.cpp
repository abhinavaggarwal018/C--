#include<iostream>

using namespace std;

int hash[26]={0};

int main()
{
	string str;
	cin>>str;
	
	for(int i=0;i<str.length();i++)
		hash[str[i]-'a']++;
		
	for(int i=0;i<26;i++)
		while(hash[i]--)
			cout<<char('a'+i);
			
	cout<<"\n";
}
