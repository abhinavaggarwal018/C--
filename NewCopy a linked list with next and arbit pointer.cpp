#include<abhinav.h>

using namespace std;

struct list
{
	int data;
	struct list *next,*prev;
}*mid=NULL;



struct stack* push(struct stack* top,int data)
{
	struct stack *node=new struct stack;
	cnt++;

	if(top)
		top->next=node;

	node->data=data;
	node->next=NULL;
	node->prev=top;

	if(cnt==1)
		mid=node;
	else if(cnt%2==1)
		mid=mid->next;	
	
	return node;
}

int main()
{
	
}
