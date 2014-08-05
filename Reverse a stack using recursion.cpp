#include<iostream>
#include<stack>

using namespace std;

int reverse(stack<int> s, int num)
{
	if(s.empty())
		return num;
		
	int val=s.top();
	s.pop();
	s.push(reverse(s,val));
	return val;
}

void display(stack<int> s)
{
	while(!s.empty())
	{
		cout<<s.top()<<"->";
		s.pop();
	}
}

int main()
{
	stack<int> s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);
	
	reverse(s,s.top());
	display(s);
}
