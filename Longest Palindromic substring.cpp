#include<iostream>
#include<string>

using namespace std;

string arr;
str lps[1200][1200]="0";

string reverse(string str, int n)
{
	for(int i=0;i<n/2;i++)
	{
		char temp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=temp;
	}
	
	return str;
}

string find_lps(string str, int start, int end, string ans1,string ans2)
{
	if(lps[start][end]!="0")
		return lps[start][end];
	if(start>end)
	{
		if((ans1.length()+ans2.length())>arr.length())
		{
//			cout<<ans2<<"-";
			
			ans2=reverse(ans2,ans2.length());
			
//			cout<<ans2<<">";
			
			arr=ans1+ans2;
		
		}
		
		lps[start][end]=arr;
		return arr;
	}
	
	if(str[start]==str[end]&&start!=end)
	{
		lps[start][end]=find_lps(str,start+1,end-1,ans1+str[start],ans2+str[end]);
		return lps[start][end];
	}
	if(str[start]==str[end]&&start==end)
	{
		lps[start][end]=find_lps(str,start+1,end-1,ans1+str[start],ans2);
		return lps[start][end];
	}
	
	string str1,str2;
	str1=find_lps(str,start,end-1,"","");
	str2=find_lps(str,start+1,end,"","");
	
	lps[start][end] str1.length()>str2.length() ? str1 : str2 ;
	return lps[start][end];
}

int main()
{
	string str;
	cin>>str;
	
	
	str=find_lps(str, 0, str.length()-1, "", "");
	
//	cout<<str.length();
	
	cout<<str;		
}
