/*	
Implement Queue using Stacks
March 13, 2010

A queue can be implemented using two stacks.
*/

#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int num;
	stack<int> s,s1;
	int curr=0,val;  // represents data in 0 is imp 
	while(1)
	{
		cout<<"Enter 1 for insert,2 for pop";
			cin>>num;
		
		if(num==1)
		{
			cout<<"Enter value:\n";
			cin>>val;
		}
		
		if(num==1)
		{
			if(curr==0)
				s.push(val);
		}
		
		if(num==2)
		{
			if(curr==0)
			{
				while(!s.empty())
				{
					val=s.top();
					s.pop();
					s1.push(val);
				}

				cout<<"Popped element is: "<<s1.top()<<"\n";
				s1.pop();

				while(!s1.empty())
				{
					val=s1.top();
					s1.pop();
					s.push(val);
				}
			}
		}
	}
}
