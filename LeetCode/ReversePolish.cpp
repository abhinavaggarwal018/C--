#include<vector>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

stack<int> s;

    int evalRPN(vector<string> &tokens) {
        for(int i=0;i<tokens.size();i++)
        {

			if(tokens[i]=="+" ||tokens[i]=="-" ||tokens[i]=="/" ||tokens[i]=="*")
            {

                long long int v1=s.top();
                s.pop();
                long long int v2=s.top();
                s.pop();
                
                if(tokens[i]=="+")
                {
                    s.push(v1+v2);
                }

                else if(tokens[i]=="-")
                {
                    s.push(v2-v1);
                } 

                else if(tokens[i]=="*")
                {
                    s.push(v1*v2);
                } 

                else if(tokens[i]=="/")
                {
                    s.push(v2/v1);
                } 

            }
            else
            {
                string str=tokens[i];
				
				int i1=0;
                bool flag=false;
                if(str[0]=='-')
                {
                	flag=true;
                	i1=1;
                }
                
                long long int v=0;
                for(int i=i1;i<str.length();i++)
                    v=v*10 + str[i]-'0';
				
				if(flag)
					v=-1*v;
				                    
                s.push(v);
            }
        }
        
        cout<<s.top();
        s.pop();
        return 0;
    }
    
int main()
{
	string str[]={"-3","4","+"};
//	cout<<;
	vector<string>tokens(str,str+sizeof(str)/sizeof(str[0])) ;
	evalRPN(tokens);
}
