#include<iostream>
#include<climits>
#include<stdio.h>
#include<queue>
using namespace std;
/*

	**************       SET 1 CODING ROUND   *************

*/
/*
void find_minimum_distance(int arr[], int n, int num1, int num2)
{
	if(n==0)
		return;
		
	bool found1=false, found2=false;
	int ans=INT_MAX, idx;
		
		
	if(num1!=num2)
	{	
		for(int i=0;i<n;i++)
		{
			if(arr[i]==num1)
			{
				if(found2==true)
				{
					ans=min(ans,i-idx);
					found2=false;
				}

				found1=true;
				idx=i;
			}
			
			if(arr[i]==num2)
			{
				if(found1==true)
				{
					ans=min(ans,i-idx);
					found1=false;
				}

				found2=true;
				idx=i;
			}
		}
	}
	
	if(num1==num2)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]==num1)
			{
				if(found1==true)
					ans=min(ans,i-idx);

				found1=true;
				idx=i;
			}
		}
	}
	
	cout<<ans;
	
}

struct list
{
	int data;
	struct list *next;
};

struct list * create_list(int num)
{
	struct list *node= new struct list;
	
	node->next=NULL;
	node->data=num;
	
	return node;
}

struct list* create()
{
	int n, data;
	
	cin>>n;
	
	if(n<=0)
		return NULL;
		
	cin>>data;
	
	struct list *head=create_list(data),*temp;

	temp=head;
		
	while(--n)
	{
		cin>>data;
		head->next=create_list(data);
		head=head->next;
	}
	
	return temp;
}

void display(struct list *head)
{
	cout<<"\n";
	while(head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}

struct list *reverse(struct list *root)
{
	if(root==NULL)
		return root;;
	
	struct list *prev=NULL;
	
	while(root->next!=NULL)
	{	
		struct list *temp=root->next;
	
		root->next=prev;

		prev=root;		
		root=temp;
	}
	
	root->next=prev;
	
	return root;	
}

struct list * sum1(struct list *head1, struct list *head2, struct list *head3, int carry)
{
	
	if(head1 && head2 && head3)
	{
		int sum=head1->data+head2->data+head3->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1->next,head2->next,head3->next,carry);
		return head;
	}
	
	if(head1 && head2)
	{
		int sum=head1->data+head2->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1->next,head2->next,head3,carry);
		return head;
	}
	
	if(head2 && head3)
	{
		int sum=head2->data+head3->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1,head2->next,head3->next,carry);
		return head;
	}

	if(head1 && head3)
	{
		int sum=head1->data+head3->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1->next,head2,head3->next,carry);
		return head;
	}
	
	if(head1)
	{
		int sum=head1->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1->next,head2,head3,carry);
		return head;
	}
	
	if(head2)
	{
		int sum=head2->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1,head2->next,head3,carry);
		return head;
	}
	
	if(head3)
	{
		int sum=head3->data+carry;
		struct list *head= create_list(sum%10);
		carry=sum/10;
		head->next=sum1(head1,head2,head3->next,carry);
		return head;
	}
	
	if(carry!=0)
	{
		struct list *head=create_list(carry);
		return head;
	}

	return NULL;	
}

int main()
{
	
	struct list *head1=create();
	struct list *head2=create();
	struct list *head3=create();

	display(head1);
	display(head2);
	display(head3);
	

	struct list *temp1=reverse(head1), *temp2=reverse(head2), *temp3=reverse(head3);

	display(temp1);
	display(temp2);
	display(temp3);	
	
	int carry=0;

	struct list *head=sum1(temp1, temp2, temp3, 0);
	
	display(head);
	
	head=reverse(head);
	
	display(head);

// part 1
	while(1)
	{
		int arr[1000];
		int n,num1,num2;
		
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		cin>>num1>>num2;
			
		find_minimum_distance(arr,n,num1,num2);
	}
}

*/

/*
	QUESTION 2 ROUND 2
*/

/*
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree * create_tree(int data)
{
	struct tree *root= new struct tree;
	
	root->left=NULL;
	root->right=NULL;
	root->data=data;
	
	return root;	
}

struct tree *insert(struct tree *head,int data)
{
	if(head==NULL)
		return create_tree(data);
		
	if(head->data >= data)
		head->left=insert(head->left,data);
		
	else
		head->right=insert(head->right,data);
		
	return head;
}

int getdata(struct tree *root)
{
	if(root==NULL)
		return 0;
	else
		return root->data;
}

void to_sum_tree(struct tree *root)
{
	if(root==NULL)
		return;
		
	root->data=getdata(root->left)+getdata(root->right);
	
	to_sum_tree(root->left);
	to_sum_tree(root->right);	
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int main()
{
	struct tree *root=NULL;
	
	root=insert(root,10);
	root=insert(root,3);
	root=insert(root,1);
	root=insert(root,4);
	root=insert(root,8);
	root=insert(root,5);
	root=insert(root,7);
	root=insert(root,6);
	
	inorder(root);
	to_sum_tree(root);
	cout<<"\n";
	inorder(root);
}

*/

/*
void swap_arr(int arr[], int start, int end)
{
	for(int i=start;i<=start+(end-start)/2;i++)
	{
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
	}
}

int sort_by_value_asc(int arr[], int n)
{
	int start=0, end=n-1;
	
	while(start<=end)
	{
		if(arr[start]<0)
			start++;
			
		else
		{
			int temp=arr[end];
			arr[end]=arr[start];
			arr[start]=temp;
			end--;
		}
	}
		
	int piv;
		
	if(arr[end]>0)
		piv=end;
	else
		piv=end+1;

	return piv;
//	swap_arr(arr,piv,n-1);
}

int sort_by_value_desc(int arr[], int n)
{
	int start=0, end=n-1;
	
	while(start<=end)
	{
		if(arr[start]>0)
			start++;
			
		else
		{
			int temp=arr[end];
			arr[end]=arr[start];
			arr[start]=temp;
			end--;
		}
	}
		
	int piv;
		
	if(arr[end]<0)
		piv=end;
	else
		piv=end+1;

	return piv;
}


void arrange_elements(int arr[],int n)
{
	if(n<=0)
		return;
		
	int fir=arr[0],neg_cnt,pos_cnt,piv;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
			neg_cnt++;
			
		if(arr[i]>0)
			pos_cnt++;
	}
	
	
	if(neg_cnt<=pos_cnt)	
		piv=sort_by_value_asc(arr,n);
	else
		piv=sort_by_value_desc(arr,n);
		
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" "<<"\n";
	cout<<piv<<"\n";

	
	if(neg_cnt <= pos_cnt)
	{
		if(fir>0)
		{
			int cnt=0;
			for(int i=0;i<=piv-1;i+=2)
			{
				int temp=arr[i];
				arr[i]=arr[cnt+piv];
				arr[cnt+piv]=temp;
				cnt++;
			}
		}
		else
		{
			int cnt=0;
			for(int i=0;i<=piv;i+=2)
			{
				int temp=arr[i];
				arr[i]=arr[cnt+piv];
				arr[cnt+piv]=temp;
				cnt++;
			}	
		}
	}
	
	if(neg_cnt > pos_cnt)
	{
		if(fir<0)
		{
			int cnt=0;
			for(int i=0;i<=piv-1;i+=2)
			{
				int temp=arr[i];
				arr[i]=arr[cnt+piv];
				arr[cnt+piv]=temp;
				cnt++;
			}
		}
		else
		{
			int cnt=0;
			for(int i=0;i<=piv;i+=2)
			{
				int temp=arr[i];
				arr[i]=arr[cnt+piv];
				arr[cnt+piv]=temp;
				cnt++;
			}
		}
	}

}
*/
/*
void block_swap(int arr[], int start, int end)
{
	int temp=arr[end];
	
	for(int i=end;i>start;i--)
		arr[i]=arr[i-1];
	
	arr[start]=temp;
}

bool neg_update(int arr[], int start, int end)
{
	for(int i=start;i<=end;i++)
	{
		if(arr[i]<0)
		{
			block_swap(arr,start,i);
			return true;
		}
	}
	return false;
}

bool pos_update(int arr[], int start, int end)
{
	for(int i=start;i<=end;i++)
	{
		if(arr[i]>0)
		{
			block_swap(arr,start,i);
			return true;
		}
	}
	
	return false;
}

void arrange_elements_n2(int arr[], int n)
{
	if(n<=0)
		return;
		
	int fir=arr[0],neg_cnt,pos_cnt,piv;

	for(int i=1;i<n;i++)
	{
		if((arr[i]>0 && arr[i-1]<0)||(arr[i]<0 && arr[i-1]>0))
			continue;
			
		if(arr[i-1]<0)
			if(!pos_update(arr,i,n-1))
				return;
		
		else if(arr[i-1]>=0)
			if(!neg_update(arr,i,n-1))
					return;
		
	}
}

int main()
{
	int n, arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	arrange_elements_n2(arr,n);

	for(int i=0;i<n;i++)
		cout<<arr[i];

}



*/

/*
				SPIRAL ORDER TO TREE
*/

/*
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree * create_tree(int data)
{
	struct tree *root= new struct tree;
	
	root->left=NULL;
	root->right=NULL;
	root->data=data;
	
	return root;	
}

struct tree *insert(struct tree *head,int data)
{
	if(head==NULL)
		return create_tree(data);
		
	while(head->right)
		head=head->right;
		
	struct tree *node= create_tree(data);
	
	head->right=node;
	node->left=head;
}

int getdata(struct tree *root)
{
	if(root==NULL)
		return 0;
	else
		return root->data;
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;

	cout<<root->data<<"->";		
	inorder(root->left);
	inorder(root->right);
}

void display_right(struct tree *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
}

void display_left(struct tree *root)
{
	while(root->right)
		root=root->right;
	
	while(root)
	{
		cout<<root->data<<"<-";
		root=root->left;
	}
}

struct tree * to_tree(struct tree *root)
{
	if(root==NULL)
		return NULL;
		
	queue<struct tree *> q;
	q.push(root);
	
	root=root->right;
	
	int cnt=0,val=1;
	bool flag=0;
	
	while(!q.empty())
	{
		struct tree *node= q.front();
		q.pop();
		cnt++;
		
		if(!root)
		{
			node->right=NULL;
			node->left=NULL;
		}
		
		if(cnt==val)
		{
			if(flag==0)
				flag=1;
			else
				flag=0;	
				
			val=val*2;
			
			//reverse DLL here.
		}
		
		if(root)
		{
			if(flag==1)
			{
				node->right=root;
				q.push(node->right);
				root=root->right;
				
				if(root)
				{
					node->left=root;
					q.push(node->left);
					root=root->right;
				}
				
				else
					node->left=NULL;
			}
			
			else if(flag==0)
			{
				node->left=root;
				q.push(node->left);
				root=root->right;
				
				if(root)
				{
					node->right=root;
					q.push(node->right);
					root=root->right;
				}
				
				else
					node->left=NULL;
			}
		}
	}
}

int main()
{
	struct tree *root=NULL;
	
	root=insert(root,1);
	
	insert(root,2);	
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	
	display_right(root);
	display_left(root);
	
	to_tree(root);
	getchar();
	inorder(root);
}

*/

/*
int find_water(int r,int c, int X)
{
	float arr[100][100]={0},temp;
	//float[j][i];
	
	arr[1][1]=X;
	
	for(int j=1;j<=r;j++)
		for(int i=1;i<=j;i++)
		{
			if(arr[j][i]>1)
			{
				temp=arr[j][i]-1;
				arr[j][i]=1;
				
				arr[j+1][i]+=temp/2;
				arr[j+1][i+1]+=temp/2;
			}
		}
		
	for(int j=0;j<=r;j++)
	{
		for(int i=1;i<=j;i++)
			cout<<arr[j][i]<<" ";
		cout<<"\n";
	}
	
	
}


int main()
{
	find_water(5,3,13);
}
*/


