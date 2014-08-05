#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    
    ListNode *ans,*curr;
    curr=ans;
    
    int carry = 0;
    
    if(l1==NULL)
        return l2;
        
    if(l2==NULL)
        return l1;

    if(l1!=NULL && l2!=NULL)
    {
        int data=l1->val + l2->val + carry;
        carry = data/10;
        curr = new ListNode(data%10);
        l1=l1->next;
        l2=l2->next;
    }
    
    while(l1!=NULL && l2!=NULL)
    {
        int data=l1->val + l2->val + carry;
        carry = data/10;
        curr->next = new ListNode(data%10);
        curr = curr->next;
        l1=l1->next;
        l2=l2->next;
    }
    
    while(l1==NULL && l2!=NULL)
    {
        int data = l2->val + carry;
        carry = data/10;
        curr->next = new ListNode(data%10);
        curr=curr->next;
        l2=l2->next;
    }
    
    while(l1!=NULL && l2==NULL)
    {
        int data=l1->val + carry;
        carry = data/10;
        curr->next = new ListNode(data%10);
        curr=curr->next;
        l1=l1->next;
    }
    
    if(carry)
    {
        curr = new ListNode(carry);
    }
    curr->next=NULL;
    
    return ans;
}

int main()
{
	ListNode *l1 = new ListNode(0);
//	l1->next = new ListNode(2);
	ListNode *l2 = new ListNode(0);
//	l2->next = new ListNode(2);
	
	ListNode *ans = addTwoNumbers(NULL,NULL);
	
	while(ans)
	{
		cout<<ans->val<<" -> ";
		ans=ans->next;
	}
}
