#include<iostream>
using namespace std;

struct linked_list
{
	int val;
	struct linked_list* next;
	
	/*linked_list(linked_list *node)
	{
		node->next=NULL;
	}*/
	~linked_list();
}*head=NULL;

linked_list::~linked_list()
{
	linked_list *node1=head->next;
	while(head!=NULL)
	{
		head->next=NULL;
		delete head;
		head=node1;
	}
	node1->next=NULL;
	delete node1;
}	


void add_node(int num)
{
	struct linked_list* node=head;
	while(node!=NULL&&node->next!=NULL)
	{
		node=node->next;
	}
	if(NULL==head)
	{
		head=new linked_list();
		head->val=num;		
		head->next=NULL;
	}
	else{

			node->next=new linked_list();
			node->next->val=num;
			node->next->next=NULL;
	}
}

struct linked_list* getnode(int data)
{
	struct linked_list* node=new linked_list();
	node->val=data;
	node->next=NULL;
	return node;
}

void insert(linked_list* &head, int data)
{
	if(NULL==head)
		head=getnode(data);
	else
	{
		linked_list *node=head;
		while(node->next!=NULL)
		{
			node=node->next;
		}
		node->next=getnode(data);
	}
}

void show_list()
{
	struct linked_list* node=head;
	while(node!=NULL)
	{
		cout<<node->val<<"->";
		node=node->next;
	}
	cout<<"END";
}

int DeleteNAfterM(linked_list* &head,int n,int m)
{
	linked_list* temp=head;
	int cnt=1;
	linked_list* temp1=temp;
	//bool flag=true;
	//Assuming m>=1
	while(temp!=NULL)
	{
		//cout<<"1";
		//cout<<"Here2";
		if(m==cnt)
		{
			//temp->next=NULL;
		//	cout<<"2";
			cnt=0;
			//cout<<"\n\t"<<temp->val<<"\t"<<cnt<<"\t";
			temp1=temp;
			while(NULL!=temp1)
			{
		//		cout<<"3";
		//		cout<<"Here1";
				if(cnt==n)
				{
		//			cout<<"4";
					temp->next=temp1->next;
				//	cnt=0;
					break;
				}
				if(temp1!=NULL)
					{
						temp1=temp1->next;
						cnt++;
					}
		//		cout<<"\n\t"<<temp->val<<"\t"<<cnt<<"\t";
			}
			if(temp1==NULL)
				temp->next=NULL;
			cnt=0;
		}
		if(temp==NULL)
			break;	

		temp=temp->next;
		cnt++;
		int p;
		cin>>p;
	}
	//cout<<"END";
}

int main()
{
	int m,n,t,size_list,element_list;
	//head=head1;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		cin>>size_list;
		while(size_list--)
		{
			cin>>element_list;
			//add_node(element_list);
			insert(head,element_list);
		}
	//	for(int i=1;i<=8;i++)
	//	insert(head,i);
	//	m=2;
	//	n=2;
	//	cout<<"\n";
		DeleteNAfterM(head,n,m);
		show_list();
	//
	}	
		
}
