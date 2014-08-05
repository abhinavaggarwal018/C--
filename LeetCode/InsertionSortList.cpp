#include<iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode *head1=NULL;
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return head;
    
        ListNode *node=head,*temp=head1;
        while(node!=NULL)
        {        
            node=node->next;
            ListNode *node1=head,*node2=head,*prev=NULL;
            int num=1000000000;
            while(node1)
            {
    
                if(node1->val<=num)    
                    num=node1->val;
                    
                node1=node1->next;
            }
            temp=head1;
            while(node2)
            {
                if(node2->val==num)
                {
                    if(head1==NULL)
                        head1= new ListNode(node2->val);
                    else
                    {
                        while(temp->next)
                            temp=temp->next;
                            
                        head1->next=new ListNode(node2->val);
                        head1=head1->next;
                    }
                    
                    break;
                }
                prev=node2;
                node2=node2->next;
            }
            
            if(prev==NULL)
                node2=node2->next;
            else
                prev->next=node2->next;
        }
        
        return head1;
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

	
	head=insertionSortList(head);

	while(head)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
}
