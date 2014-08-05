#include<iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
ListNode *mergeList(ListNode *node1,ListNode *node2)
{
    if(node1==NULL)
        return node2;
    
    if(node2==NULL)
        return node1;
        
    if(node1->val <= node2->val)
    {
        node1->next=mergeList(node1->next,node2);
        return node1;
    }
    else
    {
        node2->next=mergeList(node1,node2->next);
        return node2;
    }
}

ListNode *sortList(ListNode *head) {
    if(head==NULL||head->next==NULL)
        return head;
        
    ListNode *fast,*slow,*temp;
    
    slow=head;
    fast=head->next;
    while(1)
    {
        if(fast==NULL||fast->next==NULL)
        {
            temp=slow->next;
            slow->next=NULL;
            head=sortList(head);
            temp=sortList(temp);
            return mergeList(head,temp);
        }
     
        slow=slow->next;
        fast=fast->next->next;
    }
}

int main()
{
	int t,n,x;
	cin>>t;
	ListNode * head= new ListNode(1), *head1;

	head1=head;
	
	for(int i=0;i<t;i++)
	{
		while(head1->next)
			head1=head1->next;
		
		cin>>x;
			
		head1->next=new ListNode(x);
	}

	
	head1=head;

	while(head1)
	{
		cout<<head1->val<<" ";
		head1=head1->next;
	}

	
	head=sortList(head);

	while(head)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
}
