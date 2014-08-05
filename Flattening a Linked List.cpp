#include<abhinav.h>

using namespace std;

struct list
{
	int data;
	struct list *next,*down;
};

struct list * create_list(int data)
{
	struct list *node=new struct list;
	
	node->next=NULL;
	node->down=NULL;
	node->data=data;
	
	return node;
}

void display(struct list *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->down;
	}
	
	cout<<"END\n";
}

struct list* flatten(struct list *root)
{
	if(root==NULL)
		return root;
		
	if(root->next==NULL)
		return root;
		
	struct list *temp =root->next,*curr1=root,*curr2=root->next,*prev2,*prev1;
	while(temp)
	{

		while(curr1->down!=NULL && curr2!=NULL)
		{
			if(curr1->down->data <= curr2->data)
				curr1=curr1->down;
			
			else
			{
				prev1=curr1->down;
				curr1->down=curr2;
				prev2=curr2;
				curr2=curr2->down;
				prev2->down=prev1;
			}
		}
		
		if(curr2!=NULL)
			curr1->down=curr2;
		
		curr1=root;
		curr2=temp->next;
		temp=temp->next;
	}
	
	return root;
}



int main()
{
	struct list *root= create_list(5),*temp;
	temp=root;
	
	temp->down=create_list(7);
	temp->down->down=create_list(8);
	temp->down->down->down=create_list(30);

	temp->next=create_list(10);
	temp=temp->next;

	temp->down=create_list(20);

	temp->next=create_list(19);
	temp=temp->next;

	temp->down=create_list(22);
	temp->down->down=create_list(50);



	temp->next=create_list(28);
	temp=temp->next;
	temp->down=create_list(35);
	temp->down->down=create_list(40);
	temp->down->down->down=create_list(45);

	display(root);
	display(root->next);
	display(root->next->next);
	display(root->next->next->next);
	
	root=flatten(root);
	
	display(root);
}
