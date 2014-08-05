#include<iostream>
using namespace std;

SLL
*delete a LL
*Print nth node
*Print nth from end
*No. of times a no occurs in LL
*Delete a node
*Find mid

DLL
*create
*delete a LL
*Print nth node
*Print nth from end
*No. of times a no occurs in LL
*Delete a node

Puzzles:
1. Flip 10 cards in a deck of cards
2. 2 dice to show all dates such that date in month starts from 0 to 30.
3. Divide a triangle into n triangles.
4. 

struct list
{
	int data;
	struct list *next;
};

struct list *create_list(struct list *)
{
	struct list *node=new struct list;
	
	node->data=num;
	node->next=NULL;
	
	return node;
}

struct list *display(struct list *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main()
{
	struct list *head=NULL;
	head=create_list
}

