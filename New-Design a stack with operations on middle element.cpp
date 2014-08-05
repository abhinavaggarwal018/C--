#include<abhinav.h>

struct stack
{
	int data;
	struct stack *next,*prev;
}*mid=NULL;

int cnt=0;

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

int pop(struct stack** top)
{
	if(top)
	{
		int ans=(*top)->data;
		struct stack *node=*top;
		
		if(cnt%2==1)
			mid=mid->prev;
		
		cnt--;
		(*top)=(*top)->prev;
		delete node;
		
		return ans;
	}
	else
		cout<<"EMPTY!\n";
		return 1;;
}

int find_middle()
{
	return mid->data;
}

void delete_middle()
{
	struct stack* mid1=mid;
	
	if(cnt%2==1)
		mid=mid->prev;
		
	mid->prev->next=mid->next;
	mid->next->prev=mid->prev;
	
	delete mid1;
	cnt--;
	
	return;
}


int main()
{
    struct stack *ms=NULL;
    
	ms=push(ms, 11);
    ms=push(ms, 22);
    ms=push(ms, 33);
	ms=push(ms, 44);
    ms=push(ms, 55);
    ms=push(ms, 66);
    ms=push(ms, 77);
 	
 	delete_middle();
    printf("Middle Element is %d\n", find_middle());
    printf("Item popped is %d\n", pop(&ms));
    printf("Middle Element is %d\n", find_middle());
    printf("Item popped is %d\n", pop(&ms));
    printf("Middle Element is %d\n", find_middle());
}
