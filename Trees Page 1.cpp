#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<cassert>
#include<signal.h>
  
using namespace std;

int max_height=0,no_of_elements=0;

struct tree
{
	int data;
	struct tree *left,*right;
};

struct tree* create_tree(int val)
{
	struct tree* node=new tree;
	node->left=NULL;
	node->right=NULL;
	node->data=val;
	return node;
}


void inorder(struct tree *root)
{
	//struct tree *node=root;
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
}

int preorder(struct tree*root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}

int postorder(struct tree*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"->";
	}
}

struct tree* create_temp()
{
	struct tree *root=create_tree(7);
	root->left=create_tree(3);
	root->right=create_tree(11);
	
	root->left->left=create_tree(1);
	root->left->right=create_tree(5);
	
	root->left->left->left=create_tree(0);
	root->left->left->right=create_tree(2);

	root->left->right->left=create_tree(4);
	root->left->right->right=create_tree(6);
	
	root->right->left=create_tree(9);
	root->right->right=create_tree(13);
	
	root->right->left->left=create_tree(8);
	root->right->left->right=create_tree(10);
	
	root->right->right->left=create_tree(12);
	root->right->right->right=create_tree(14);

	
/*	struct tree* root = create_tree(1);
    root->left = create_tree(2);
    root->right = create_tree(3);
    root->left->left = create_tree(4);
    root->left->right = create_tree(5);
    root->right->left = create_tree(6);
    root->right->right = create_tree(7);
    root->left->left->left = create_tree(8);
    root->left->right->right = create_tree(9);
    root->right->right->left = create_tree(10);
*/
	return root;
}

int cnt_recur1=0,arr[100];
void print_ancestor_recur(struct tree *root,int val)
{
	if(root==NULL)
		return;
		
	arr[cnt_recur1]=root->data;
	cnt_recur1++;
	print_ancestor_recur(root->left,val);
	
	if(val==root->data)
	{
		for(int i=0;i<cnt_recur1-1;i++)
			cout<<arr[i];
		cout<<"\n";		
	}
	
	print_ancestor_recur(root->right,val);
	
	cnt_recur1--;
}

void print_ancestor_iter(struct tree *root, int val)
{
	stack<struct tree*> s;
	
	struct tree *temp=root;
		
	int flag=0;
	
	cout<<"HERE\n";
	
	while(1)
	{
		cout<<1;
		cout<<temp->data<<":";
				cout<<3;
		if(!s.empty())
			cout<<s.top()->data<<"\n";
		
		getchar();
		
		while(temp && temp->data!=val)
		{	
			s.push(temp);
			temp=temp->left;
		}

		if(temp && temp->data==val)
			break;			
						cout<<4;
		while((s.top()->right==temp) && !s.empty())
			s.pop();
				cout<<5;
		temp=s.top()->right;			
	
		
		if(!s.empty()&& temp==NULL)
		{
				cout<<6;
			cout<<"A;";
			s.push(temp);
			cout<<temp->data;

		}
		else
		{
							cout<<7;
			while(s.top()&&!s.empty())
				s.pop();
		}	

			cout<<8;
	}
	cout<<1;
	stack<int> s1;
	while(!s.empty())
	{
		s1.push(s.top()->data);
		s.pop();
	}
	
//	cout<<s1.size()<<":";
	
	while(!s1.empty())
	{
		cout<<s1.top();
		s1.pop();
	}
	cout<<"\n";
}

void print_ancestors(struct tree *root, int key)
{
	if(root==NULL)
		return;
		
	stack<struct tree*> s;
	
	struct tree *temp;
	
	while(1)
	{
		while(root && root->data!=key)
		{
			s.push(root);
			root=root->left;
		}
		
		if(root && root->data==key)
			break;
		
		if(s.empty())
			return;
				
	//	cout<<s.top()->right->data<<":"<<root->data<<"\n";		
	//		getchar();
		
		while((s.top()->right== NULL || s.top()==root || s.top()->right == root)&&!s.empty())
		{
			root=s.top();
			s.pop();
		}
			
		if(s.empty())
			return;
			
		else
			root=s.top()->right;
		
		temp=root;
		
/*		if(s.empty())
			return;

		root=s.top()->right;
		if(!root)
			s.pop();*/
	}
	
	cout<<key<<"  :  ";
	while(!s.empty())
	{
		cout<<s.top()->data<<" ";
		s.pop();
	}
	cout<<"\n";

}

void display_left(struct tree *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->left;
	}
	cout<<"END\n";
}

void display_right(struct tree *root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	cout<<"END\n";
}

struct tree * change_to_dll_left(struct tree *root, struct tree *ancestor)
{
	if(root==NULL)
		return NULL;

	static struct tree*pre=NULL;
		
	change_to_dll_left(root->left,root);
	root->left=pre;
	pre=root;
	change_to_dll_left(root->right,ancestor);
	
	return pre;
}

struct tree * change_to_dll_right(struct tree *root, struct tree *ancestor)
{
	if(root==NULL)
		return NULL;
		
	change_to_dll_right(root->left,root);
	struct tree*temp=root->right;
	root->right=ancestor;
	change_to_dll_right(temp,ancestor);
	
//	return root;
}

int find_height(struct tree *root)
{
	if(root==NULL)
		return 0;
		
	stack<struct tree *> s;
	int cnt=0,ans=0;

	while(1)
	{
		while(root)
		{
			cnt++;
			s.push(root);
			root=root->left;
		}
		
		ans=max(ans,cnt);
		
		if(!s.top()->right)
		{
			root=s.top();
			s.pop();
			cnt--;
			while(!s.empty() && (s.top()->right==root))
			{
				root=s.top();
				s.pop();
				cnt--;
			}
		}	
				
		if(s.empty())
			return ans;
		
		root=s.top()->right;
	}
}

void permute(int arr[], int pos, int n, string str)
{
	if(pos>=n)
	{
		cout<<str<<"->";
		return;
	}
	
	if(arr[pos]>0)
		permute(arr,pos+1,n,str+char('a'+arr[pos]-1));
	
	if( pos <= n-2 )
	{
		int val=arr[pos]*10 + arr[pos+1];
	
		if( val<=26 && val>=10 )
			permute(arr,pos+2,n,str+char('a'+val-1));
	}
}

struct tree * create_complete_binary_tree(struct tree *root, int data)
{
	if(root==NULL)
		return create_tree(data);
		
	queue <struct tree *> q;
	q.push(root);
	
	while(1)
	{
		struct tree *temp=q.front();
		q.pop();
		
		if(temp->left)
			q.push(temp->left);
		else
		{
			temp->left=create_tree(data);
			return root;
		}
	
		if(temp->right)
			q.push(temp->right);
		else
		{
			temp->right=create_tree(data);
			return root;
		}
	}
}

struct tree *inorder_successor(struct tree *root,struct tree *parent)
{
	if(root==NULL)
		return NULL;
	
	static struct tree *prev1=NULL;
	
	inorder_successor(root->right,root);
	root->right=prev1;
	prev1=root;
	inorder_successor(root->left,parent);
	
	return prev1;
}
				
struct tree * update_right(struct tree *root)
{
	if(root==NULL)
		return NULL;
	
	static struct tree *prev2=NULL;
	
	while(root)
	{
		root->right=prev2;
		prev2=root;
		root=root->left;
	}
	
	return prev2;
}

bool is_identical_bst(int arr1[],int arr2[],int i1,int i2, int n,int minm,int maxm)
{
	int i,j;
	for(i=i1;i<n;i++)
		if(arr1[i]>minm && arr1[i]<maxm)
			break;
			
	for(j=i2;j<n;j++)
		if(arr2[j]>minm && arr2[j]<maxm)
			break;
			
	if(i==n &&j==n)
		return true;
		
	if(i==n || j==n || arr2[j]!=arr1[i])
		return false;
		
	return is_identical_bst(arr1,arr2,i+1,j+1,n,minm,arr1[i])&is_identical_bst(arr1,arr2,i+1,j+1,n,arr1[i],maxm);
}

int height_iter(struct tree *root, int *ans)
{
	int cnt=0;
	struct tree *temp=NULL;
	stack<struct tree *> s;
	
	while(1)
	{
		cout<<1;
		if(root)
			cout<<root->data;
		cout<<2;
		while(root)
		{
			cout<<3;
			s.push(root);
			root=root->left;
			cnt++;
		}
		cout<<4;
		*ans=max(*ans,cnt);
		
		root=s.top();
		if(root->right)
			root=root->right;
		
		else
		{
			root=s.top()->right;
			s.pop();
			cnt--;
			cout<<s.top()->right->data;
			
			while((!root||s.top()->right==temp)&&!s.empty())
			{
				s.pop();
				cnt--;
			}
		}
/*			while(!s.empty() && (!s.top()->right || s.top()->right==root))
			{
				cout<<5;
				root=s.top();
				s.pop();
				cnt--;
			}*/
		cout<<6;
		if(s.empty())
			return 0;
		cout<<7;
		
		temp=root->right;
	}
}

struct tree * construct_bst_from_preorder_traversal(int arr[], int start, int n)
{
	if(start>n)
		return NULL;
	
	struct tree *root=create_tree(arr[start]);
	
	int i;
	
	for(i=start;i<=n;i++)
		if(arr[i]>arr[start])
			break;
		
	++start;
	root->left=construct_bst_from_preorder_traversal(arr,start,i-1);
	root->right=construct_bst_from_preorder_traversal(arr,i,n);
	
	return root;
}

struct tree* construct_bst_from_preorder_traversal( int pre[], int *start, int n, int minm, int maxm)
{
	if(*start>n)
		return NULL;
		
	if(pre[*start]<= minm|| pre[*start]>= maxm)
		return NULL;
		
	struct tree *root=create_tree(pre[*start]);
	
	*start=*start+1;
	if(*start<=n)
		root->left=construct_bst_from_preorder_traversal(pre,start,n,minm,root->data);
		
	if(*start<=n)
		root->right=construct_bst_from_preorder_traversal(pre,start,n,root->data,maxm);
	
		
	return root;
}

int find_ceil(struct tree *root,int key)
{
	static int ceil=-1;
	
	if(root==NULL)
	{
		if(key>ceil)
			return -1;
		
		return ceil	;
	}
	
	if(root->data==key)
		return root->data;
		
	if(root->data<key)
		return find_ceil(root->right,key);
		
	else
	{
		ceil=root->data;
		return find_ceil(root->left,key);
	}
}

void preorder_iter(struct tree *root)
{
	if(root==NULL)
		return;
		
	stack<struct tree *> s;
	
	while(1)
	{
		while(root)
		{
			cout<<root->data<<"->";
			s.push(root);
			root=root->left;
		}
		struct tree *temp;
		
		while(!s.empty())
		{
			temp=s.top();
			s.pop();
			
			if(temp->right)
				break;
		}
		
		if(s.empty()&&!(temp->right))
			return;
			
		root=temp->right;	
		
	}
}

void find_pointers(struct tree *root, struct tree **ptr1,struct tree **ptr2)
{
	if(root==NULL)
		return;
		
	static int flag1=0;
	static struct tree* prev=NULL;
	
	find_pointers(root->left,ptr1,ptr2);
	if(prev)
	{
		if(flag1==0 && root->data < prev->data)
		{
			cout<<"here\n";
			*ptr1=prev;
			*ptr2=root;
			flag1=1;
		}
	
		else if( root->data < prev->data)
		{
			cout<<"there\n"<<root->data<<"\n";
			*ptr2=root;
		}
	}
	prev=root;
	cout<<prev->data<<"\n";
	find_pointers(root->right,ptr1,ptr2);
}

void correct_bst_with_two_nodes_swapped(struct tree *root)
{
	if(root==NULL)
		return;
		
	static int flag=0;
	static struct tree *ptr1=create_tree(0),*ptr2=create_tree(0),*temp=create_tree(0);
		
	find_pointers(root,&ptr1, &ptr2);
	
	cout<<ptr1->data;
	cout<<ptr2->data;
	
	temp->data=ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=temp->data;
}

struct tree * construct_bst_from_preorder_traversal(int pre[],int n)
{
	if(n<0)
		return NULL;
		
	int start=0;
	struct tree *root=create_tree(pre[start]);
	start++;
	stack <struct tree *> s;
	s.push(root);
	
	while(!s.empty()&& start<=n)
	{
		if(pre[start]<s.top()->data && start <=n)
		{
			if(!s.top()->left)
				s.top()->left=create_tree(pre[start]);
			start++;
			s.push(s.top()->left);
		}
		
		else
		{
			struct tree *temp=s.top();
			s.pop();
			
			while(!s.empty() && temp->data > s.top()->data)
			{
				temp=s.top();
				s.pop();
			}
			
			temp->right=create_tree(pre[start]);
			s.push(temp->right);
			start++;
		}
	}
	
	return root;
}

bool check_tree_complete(struct tree *root)
{
	if(root==NULL)
		return true;
		
	queue<struct tree*> q;
	
	q.push(root);
	int cnt=1;
	bool is_open=true;
	
	while(!q.empty())
	{
		while(cnt--)
		{
			struct tree *temp=q.front();
			q.pop();
			
			if(temp->left)
			{
				if(is_open)
					q.push(temp->left);
				else
					return false;
			}
			else
				is_open=false;
			
			
			if(temp->right)
			{
				if(is_open)
					q.push(temp->right);
				else
					return false;
			}
			else
				is_open=false;
		}
		cnt=q.size();
	}
	return true;
}

bool check_bst_has_one_child_from_preorder_traversal(int arr[],int n)
{
	if(n<2)
		return true;
		
	int minm=INT_MIN,maxm=INT_MAX;
	
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>arr[i-1])
			minm=arr[i-1];
		else
			maxm=arr[i-1];
			
//		cout<<arr[i]<<":"<<minm<<"\t"<<maxm<<"\n";
		
		if(arr[i]>maxm || arr[i]<minm)
			return false;
	}
	
	return true;
}

struct tree * construct_special_binary_tree(int pre[],char preln[], int n)
{
	static int start=0;
	
	if(start>n)
		return NULL;
		
	struct tree *root= create_tree(pre[start]);
	start++;
	if(start<=n && preln[start-1]=='N')
	{
		root->left=construct_special_binary_tree( pre, preln, n);
		root->right=construct_special_binary_tree( pre, preln, n);
	}
	return root;
}

struct tree * construct_special_binary_tree_iter(int pre[],char preln[], int n)
{
	static int start=0;
	
	if(start>n)
		return NULL;
		
	struct tree *root= create_tree(pre[start]);
	
	stack<struct tree *> s;
	if(start<=n && preln[start]=='N')
		s.push(root);
	start++;
	
	while(start<=n)
	{
		while(preln[start]=='N')
		{
			s.top()->left=create_tree(pre[start]);
			s.push(s.top()->left);
			start++;
		}
		
		while(preln[start]=='L')
		{
			if(s.top()->left)
			{
				s.top()->right=create_tree(pre[start]);
				
				s.pop();
				start++;
			}
			else
			{
				s.top()->left=create_tree(pre[start]);
					start++;
			}	
		}
	}
	
	return root;
}

struct tree *create_special_tree_from_inorder_traversal(int in[],int start,int end)
{
	if(start>end)
		return NULL;
		
	if(start==end)
		return create_tree(in[start])	;
	
	int maxm=start;

	for(int i=start+1;i<=end;i++)
	{
		if(in[i]>in[maxm])
			maxm=i;
	}
	struct tree *root= create_tree(in[maxm]);
	//cout<<in[maxm]<<":"<<maxm;
	root->left=create_special_tree_from_inorder_traversal(in,start,maxm-1);
	root->right=create_special_tree_from_inorder_traversal(in,maxm+1,end);
	
	return root;
}

struct tree *fix_right_pointers(struct tree *root,struct tree **prev1,struct tree **prev2)
{
	if(root==NULL)
		return NULL;
		
	fix_right_pointers(root->left,prev1,prev2);
	
	if((*prev1))
		(*prev1)->right=root;
	else
		(*prev2)=root;
	(*prev1)=root;
	
	fix_right_pointers(root->right,prev1,prev2);
	
	return (*prev2);
}

void fix_left_pointers(struct tree *root,struct tree **prev)
{
	if(root==NULL)
		return;
	
	root->left=(*prev);
	(*prev)=root;
	
	return fix_left_pointers(root->right,prev);
}

struct tree * to_dll_method1(struct tree *root)
{
	if(root==NULL)
		return NULL;

	struct tree *temp1=NULL,*temp2=NULL;		
	root=fix_right_pointers(root,&temp1,&temp2);
	temp1=NULL;
	fix_left_pointers(root,&temp1);
	
	return root;
}

void display_start(struct tree *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<"<->";
		root=root->right;
	}
	
	cout<<"END";
}

void display_end(struct tree *root)
{
	while(root->right!=NULL)
		root=root->right;
	
	while(root!=NULL)
	{
		cout<<root->data<<"<->";
		root=root->left;
	}
	
	cout<<"END";
}

struct tree* convert_to_circular_dll( struct tree *root)
{
	if(root==NULL)
		return NULL;
		
	struct tree *left,*right;
	
	left=convert_to_circular_dll(root->left);
	right=convert_to_circular_dll(root->right);
	
	    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
	
	root->left=root;
	root->right=root;
	
	if(left)
	{
		root->left=left->left;
		left->left->right=root;
		left->left=root;
		root->right=left;
		
		if(right)
		{
			root->right=right;
			right->left->right=left;
			left->left=right->left;
			right->left=root;
		}
		
		return left;
	}
	
	if(right)
	{
		root->left=right->left;
		root->right=right;
		right->left->right=root;
		right->left=root;
	}
	
	return root;
}

void break_dll(struct tree *root)
{
	if(root==NULL)
		return;
		
	root->left=NULL;
	
	struct tree *temp=root;
	
	while(temp->right!=root)
		temp=temp->right;
	
	temp->right=NULL;
}

struct tree * to_dll_method2(struct tree *root)
{
	if(root==NULL)
		return NULL;
		
	struct tree * node=convert_to_circular_dll(root);
//	display_start(root);
	break_dll(node);
	
	return node;
}

struct tree * to_dll(struct tree *root)
{
	if(root==NULL)
		return NULL;
		
//	return to_dll_method1(root);
	return to_dll_method2(root);
}


struct tree *merge(struct tree *head1, struct tree *head2)
{
	if(head1==NULL)
		return head2;
		
	if(head2==NULL)
		return head1;
		
	if(head1->data <= head2->data)
	{
		struct tree *temp=merge(head1->right,head2);
		
		temp->left=head1;
		head1->right=temp;
		
		return head1;
	}

	if(head2->data < head1->data)
	{
		struct tree *temp=merge(head1,head2->right);
		
		temp->left=head2;
		head2->right=temp;
		
		return head2;
	}	
	
}

int find_size(struct tree *root)
{
	int cnt=0;
	while(root)
	{
		cnt++;
		root=root->right;
	}
	return cnt;	
}

struct tree *to_tree(struct tree **head,int n)
{
	if(n<=0 || (*head)==NULL)
		return NULL;
		
	struct tree *left=to_tree(head,n/2);
	
	struct tree *root= create_tree((*head)->data);
	
	(*head)=(*head)->right;
	root->left=left;
	
	root->right = to_tree(head,n-n/2-1);
	
	return root;
}

struct tree * merge_trees(struct tree *root1, struct tree *root2)
{
	if(root1==NULL)
		return root2;
		
	if(root2==NULL)
		return root1;

	struct tree *head1,*head2;
	
	head1=to_dll(root1);
	head2=to_dll(root2);
	
	display_start(head1);
	getchar();
	display_end(head1);
	getchar();

	cout<<"\n";

	display_start(head2);
	getchar();
	display_end(head2);
	getchar();
	struct tree *head= merge(head1,head2);

	cout<<"\nMerged: \n";
		
	display_start(head);
	getchar();
	display_end(head);
	getchar();
		
	return to_tree(&head,find_size(head));
}


void print_merged_inorder_traversal_of_two_bst(struct tree *root1, struct tree *root2)
{
	if(root1==NULL)
		return inorder(root2);
		
	if(root2==NULL)
		return inorder(root1);
	
	stack<struct tree *>s1,s2;
	
	int flag=0;
	
	while(root1||root2||!s1.empty()||s2.empty())
	{
		
		while(root1)
		{
			s1.push(root1);
			root1=root1->left;
		}
		
		while(root2)
		{
			s2.push(root2);
			root2=root2->left;
		}
		
		if(!s1.empty()&&s2.empty())
		{
			s1.top()->left=NULL;
			flag=1;
			//return inorder(s1.top());
		}
		
		if(s1.empty()&&!s2.empty())
		{
			s2.top()->left=NULL;
			flag=2;
			//return inorder(s2.top());
		}

		struct tree *a,*b;
		
		if(flag==0)
		{
			a=s1.top();
			b=s2.top();
			
			if(a->data<=b->data)
			{
				s1.pop();
				cout<<a->data<<"->";
				root1=a->right;
			}
			
			else
			{
				s2.pop();
				cout<<b->data<<"->";
				root2=b->right;
			}
		}
		
		if(flag==1)	
		{
			if(s1.empty())
				break;
			s1.pop();
			cout<<a->data<<"->";
			root1=a->right;
		}
		
		if(flag==2)	
		{
			if(s2.empty())
				break;
			s2.pop();
			cout<<b->data<<"->";
			root1=b->right;
		}
	}
	cout<<"END\n";
}

void maximum_sum_leaf_to_root_path(struct tree *root,int *ans,int sum)
{
	if(root==NULL)
		return ;
	
	maximum_sum_leaf_to_root_path(root->left,ans,sum);
	sum+=root->data;
	if(root->left==NULL && root->right==NULL)
		*ans=max(sum,*ans);
	maximum_sum_leaf_to_root_path(root->right,ans,sum);
}

int largest_bst_subtree(struct tree *root,int *minm,int *maxm,int *ans)
{
	if(root==NULL)
	{
		*minm=INT_MIN;*maxm=INT_MAX;*ans=0;
		return 0;
	}
	
	int min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN,h1,h2;
	
	h1=largest_bst_subtree(root->left,&min1,&max1,ans);
	h2=largest_bst_subtree(root->right,&min2,&max2,ans);	
	
	if(root->data <min2 && root->data >max1)
	{
		if(h1&&h2)
		{
			*maxm=max(max1,max2);
			*minm=min(min1,min2);
		}

		else if(h1)
		{
			*maxm=max(max1,root->data);
			*minm=min(min1,root->data);
		}
		
		else if(h2)
		{
			*maxm=max(root->data,max2);
			*minm=min(root->data,min2);
		}	
		else
		{
			*maxm=root->data;
			*minm=root->data;
		}
			
		*ans=max(*ans,h1+h2+1);
	}
	
	return h1+h2+1;
}

void inorder_successor(struct tree *curr, struct tree **root,int data)
{
	if(curr==NULL)
		return;
		
	if(curr->data < data)
		return inorder_successor(curr->right,root,data);
		
	if(curr->data > data)
	{
		(*root)=curr;
		return inorder_successor(curr->left,root,data);
	}
	else if(curr->data == data)
	{
		if(curr->right)
		{
			curr=curr->right;
			
			while(curr->left)
				curr=curr->left;
				
			cout<<curr->data;
		}
		
		else
		{
			while((*root)->left && (*root)->left->data > data)
				(*root)=(*root)->left;
			
			if((*root)->data < data)
				cout<<-1;
			else
			cout<<(*root)->data;
		}
	}
}

int convert_to_sum_tree(struct tree *root)
{
	if(root==NULL)
		return 0;
		
	int data=root->data;
	root->data = convert_to_sum_tree(root->left) + convert_to_sum_tree(root->right);
	
	return root->data +data;
}

struct tree* inorder_successor(struct tree *root,struct tree **prev, struct tree **ans)
{

	if(root==NULL)
		return NULL;
	
	inorder_successor(root->left,prev,ans);
	
	if((*prev))
		(*prev)->right=root;
	else
		(*ans)=root;
		
	(*prev)=root;
	
	inorder_successor(root->right,prev,ans);
}

void print(int arr[],int cnt)
{
	for(int i=0;i<cnt;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

void print_all_root_to_leaf_path(struct tree *root, int arr[], int *cnt)
{
	if(root==NULL)
		return;
		
	arr[(*cnt)]=root->data;
	(*cnt)++;
	
	print_all_root_to_leaf_path(root->left,arr,cnt);
	if(!root->left&&!root->right)
		print(arr,(*cnt));
	print_all_root_to_leaf_path(root->right,arr,cnt);
	(*cnt)--;
}

bool is_bst(struct tree * root,int minm, int maxm)
{
	if(root==NULL)
		return true;
		
	if(root->data >= minm && root->data <= maxm)
		return is_bst(root->left,minm,root->data)&is_bst(root->right,root->data,maxm);
	
	return false;
}

void spiral_level_traversal(struct tree *root)
{
	if(root==NULL)
		return;
		
	stack<struct tree *> q1,q2;
	q1.push(root);
	
	while(!q1.empty() || !q2.empty())
	{
		while(!q1.empty())
		{
			root=q1.top();
			cout<<root->data<<" ";
			q1.pop();
			
			if(root->left)
				q2.push(root->left);
				
			if(root->right)
				q2.push(root->right);
		}
		
		while(!q2.empty())
		{
			root=q2.top();
			cout<<root->data<<" ";
			q2.pop();
			
			if(root->right)
				q1.push(root->right);

			if(root->left)
				q1.push(root->left);
				
		}
	}
	
}

bool is_height_balanced( struct tree *root, int &ht)
{
	if(root==NULL)
		return true;
		
	int h1=0,h2=0;
	
	if(is_height_balanced(root->left,h1)&&is_height_balanced(root->right,h2))
	{
		if(abs(h1-h2)>1)
			return false;
			
		ht=max(h1,h2)+1;
		return true;
	}
	
	return false;
}

struct tree *construct_tree_from_preorder_and_inorder_traversal(char in[], char pre[], int &start, int n, int first, int last)
{
	
	if(start>n)
		return NULL;
		
	int i;
	for(i=first;i<=last;i++)
		if(pre[start]==in[i])
			break;
			
	if(i>last)
		return NULL;
		
	struct tree *root=create_tree(pre[start]);
	start++;	
	
	root->left=construct_tree_from_preorder_and_inorder_traversal(in, pre, start, n, first, i-1);
	root->right=construct_tree_from_preorder_and_inorder_traversal(in, pre, start, n, i+1, last);
	
	return root;
}

struct tree *to_double(struct tree *root)
{
	if(root==NULL)
		return NULL;
		
	struct tree *temp= root->left;
	root->left=create_tree(root->data);
	root->left->left=temp;
	
	to_double(temp);
	to_double(root->right);
	
	return root;
}

void maximum_width(int arr[],struct tree *root, int level)
{
	if(root==NULL)
		return;
		
	maximum_width(arr,root->left,level+1);
	arr[level]++;
	maximum_width(arr,root->right,level+1);
}

int maximum_width(struct tree *root)
{
	if(root==NULL)
		return 0;
		
	queue<struct tree *> q;
	q.push(root);
	
	int ans=1,cnt=1;
	while(!q.empty())
	{
		while(cnt--)
		{
			root=q.front();
			q.pop();
			
			if(root->left)
				q.push(root->left);
				
			if(root->right)
				q.push(root->right);
				
		}
		cnt=q.size();
		ans=max(ans,cnt);
	}
	return ans;
}

bool is_foldable_binary_tree(struct tree *root1, struct tree *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
		
	if(root1==NULL || root2==NULL)
		return false;
		
	if((root1->left!=NULL && root2->right!=NULL)||(root1->left==NULL && root2->right==NULL)||(root1->right!=NULL && root2->left!=NULL)||(root1->right==NULL && root2->left==NULL))
		return is_foldable_binary_tree(root1->left,root2->right)&is_foldable_binary_tree(root1->right,root2->left);
	
	return false;
		
}

void sorted_order_printing_of_array_that_represents_bst(int arr[], int start, int end)
{
	if(start>end)
		return;
		
	sorted_order_printing_of_array_that_represents_bst(arr, 2*start+1, end);
	cout<<arr[start];
	sorted_order_printing_of_array_that_represents_bst(arr, 2*start+2, end);
}

void print_ancestors(struct tree *node, int data, bool &done)
{
	if(node==NULL)
		return;
	
	if(done!=true)
	{
		if(node->data==data)
		{
			done=true;
			return;
		}
		if(node->data < data)
			print_ancestors(node->right,data,done);
			
		else if(node->data > data)
			print_ancestors(node->left,data,done);
	}
	
	if(done==true)
	{
		cout<<node->data;
		return;
	}
}

bool is_subtree(struct tree *root1, struct tree *root2)
{
	if(root1==NULL && root2==NULL)
		return true;
		
	if(root1==NULL || root2==NULL)
		return false;
		
	postorder(root1);
	cout<<"\n";
	postorder(root2);
	
	if(root1->data==root2->data)
	{
		//	
	}
}

void save_ancestors(struct tree *node, int data, bool &done, int arr[], int &cnt)
{
	if(node==NULL)
		return;
	
	if(done!=true)
	{
		save_ancestors(node->left, data, done, arr, cnt);
		
		if(node->data==data)
			done=true;
		
		if(!done)
			save_ancestors(node->right, data, done, arr, cnt);
	}
	
	if(done==true)
	{
		arr[cnt]=node->data;
		cnt++;
		return;
	}
}

void least_common_ancestor(struct tree *root, int data1, int data2)
{
	if(root==NULL)
		return ;
		
	int arr1[100]={0}, arr2[100]={0},n1,n2;
	bool done=false;

	save_ancestors(root,data1,done,arr1,n1);	

	done=false;
	save_ancestors(root,data2,done,arr2,n2);
	
	int i=n1-1,j=n2-1;
	
	for(int i1=n1-1 ;i1>=0;i1--)
		cout<<arr1[i1]<<" ";
	cout<<"\n";
	
	for(int i1=n2-1 ;i1>=0;i1--)
		cout<<arr2[i1]<<" ";
	cout<<"\n";
	
	while(i>=0 && j>=0)
	{
		if(arr1[i]==arr2[j])
		{
			i--;
			j--;
		}
		else
			break;
	}

	if(j<0)
		cout<<arr2[0];	
	else if(i<0)
		cout<<arr1[0];
	else
		cout<<arr1[i+1];
}

void inorder_successor_new(struct tree *root,struct tree *ancestor)
{
	if(root==NULL)
		return;

	struct tree *temp=root->right;

	inorder_successor_new(root->left,root);
	
	if(root->right==NULL)	
		root->right=ancestor;
	else
	{
		struct tree *temp=root->right;
		while(temp->left)
			temp=temp->left;
			
		root->right=temp;
	}
	
	//cout<<root->data<<"->";
	//cout<<root->right->data<<"\n";
		
	inorder_successor_new(temp,ancestor);
}

int print_ancestor(struct tree *root, int data)
{
	if(root==NULL)
		return 0;
		
	stack<struct tree *> s;
	int arr[100];
	int n=0,flag1=0;
	
	while(1)
	{
		while(root)
		{
			if(root->data==data)
			{
				flag1=1;
			//	break;
			}
			
			cout<<root->data<<"->";
			arr[n]=root->data;
			n++;
			s.push(root);
			root=root->left;
		}
		
		if(flag1==1)
			break;
		
		if(s.empty())
		{
			flag1=2;
			//break;
		}
			
		struct tree *temp=s.top();
		s.pop();
		n--;
		if(temp->right)
			root=temp->right;
		else
			root=NULL;
	}
	
	
	cout<<"HERE";
	if(flag1==1)
		while(!s.empty())
		{
			cout<<s.top()->data;
			s.pop();
		}
	return 0;
}




int main()
{
	
	struct tree *root= create_temp(),*root2=NULL,*temp=NULL;
	
	print_ancestor(root,0);
	print_ancestor(root,3);
	print_ancestor(root,10);
	print_ancestor(root,12);
	
//	least_common_ancestor(root1,10,14);
//	cout<<"\n";	
/*	struct tree *T        = create_tree(26);
    T->right              = create_tree(3);
    T->right->right       = create_tree(3);
    T->left               = create_tree(10);
    T->left->left         = create_tree(4);
    T->left->left->right  = create_tree(30);
    T->left->right        = create_tree(6);
 */
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
/*    struct tree *S    = create_tree(10);
    S->right          = create_tree(6);
    S->left           = create_tree(4);
    S->left->right    = create_tree(30);
    
    postorder(T);
    cout<<"\n";
    postorder(S);
    cout<<"\n";
    */
    
/*	bool done=false;
	
	for(int i=0;i<15;i++)
	{
		cout<<i<<": ";
		print_ancestors(root1,i,done);
		done=false;
		cout<<"\n"; 
	}
*/	
/*	int arr[] = {4, 2, 5, 1, 3};
	int arr_size = sizeof(arr)/sizeof(int);

	sorted_order_printing_of_array_that_represents_bst(arr, 0, arr_size-1);
*/
//	cout<<is_foldable_binary_tree(root1,root1);
//	cout<<maximum_width(root1);
		
/*	maximum_width(arr,root1,0);
	
	for(int i=0;i<10;i++)
		cout<<i<<": "<<arr[i]<<"\n";
*/
//	to_double(root1);

	inorder_successor_new(root,NULL);
	getchar();
	inorder(root);
	cout<<"\n";
	preorder(root);

/*	  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	  int n = sizeof(in)/sizeof(in[0]);

	int start=0;
	root2=construct_tree_from_preorder_and_inorder_traversal(in, pre, start, n-1, 0, n-1);

	inorder(root2);
	cout<<"\n";
	preorder(root2);
*/	
/*	int ht=0;
	cout<<is_height_balanced(root1,ht);
*/
//	spiral_level_traversal(root1);
/*

	int arr[1000];
	int cnt=0;
	print_all_root_to_leaf_path(root1, arr, &cnt);
*/
/*	convert_to_sum_tree(root1);
	inorder(root1);
	*/
/*
	for(int i=-5;i<20;i++)
	{	cout<<i<<": ";
		inorder_successor(root1,(&root2),i);
		cout<<"\n";
	}
*/
/*	int min1=INT_MAX,max1=INT_MIN,ans=0;
	largest_bst_subtree(root1,&min1,&max1,&ans);
	cout<<ans;
*/	
/*	int ans=0;
	maximum_sum_leaf_to_root_path(root1,&ans,0);
	cout<<ans;
*/	
/*    struct tree *root1  = create_tree(100);
    root1->left         = create_tree(50);
    root1->right        = create_tree(300);
    root1->left->left   = create_tree(20);
    root1->left->right  = create_tree(70);
 */
    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
/*    struct tree *root2  = create_tree(80);
    root2->left         = create_tree(40);
    root2->right        = create_tree(120);*/
 /*   int in[] = {5, 10, 40, 30, 28};
    int len = sizeof(in)/sizeof(in[0]);
    struct tree *root = create_special_tree_from_inorder_traversal(in, 0, 4);
	
	cout<<root->data;
*/
/*    int pre[] = {10, 30, 20, 5, 15};
    char preln[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
	
	temp=construct_special_binary_tree_iter(pre,preln,n-1);
*/	

//	struct tree *root = merge_trees(root1,root2);

/*	print_merged_inorder_traversal_of_two_bst(root1,root2);
	

	inorder(root1);
	cout<<"\n";
	preorder(root1);
	cout<<"\n";
	preorder_iter(root1);
	*/
/*	int pre[]={8, 3, 5, 7, 6};
	int start=0;
	int n=sizeof(pre)/sizeof(pre[0]);
	cout<<check_bst_has_one_child_from_preorder_traversal(pre,4);*/
/*	

	temp=construct_bst_from_preorder_traversal(pre,n-1);
	
	inorder(temp);
	cout<<"\n";
	preorder(temp);
	cout<<"\n";
	preorder_iter(temp);
*/	
/*	for(int i=-5;i<55;i++)
		cout<<i<<": "<<find_ceil(temp,i)<<"\n";
/*	print_ancestor_recur(root,0);
	print_ancestor_recur(root,3);
	print_ancestor_recur(root,10);
	print_ancestor_recur(root,12);
*/

/*    struct tree *root = create_tree(1);
    root->left        = create_tree(2);
    root->right       = create_tree(3);
    root->left->left  = create_tree(4);
    root->left->right = create_tree(5);
    root->right->right = create_tree(6);
  //  root->right->left = create_tree(7);

	cout<<check_tree_complete(root);
*/	
/*	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";

	correct_bst_with_two_nodes_swapped(root);
	
	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
 
*/
/*	for(int i=0;i<=14;i++)
		print_ancestors(root,i);
*/

/*    int arr1[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    int arr2[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n=sizeof(arr1)/sizeof(arr[0]);

	cout<<is_identical_bst(arr1,arr2,0,0,n,INT_MIN,INT_MAX);	
	*/

/*	int ans=0;
	ans=find_height(root);
//	height_iter(root,&ans);
	cout<<"Ans:"<<ans;*/
/*	int arr[] = {1, 1, 3, 4};
	permute(arr,0,4,"");
 cout<<"\n";
        // aaa(1,1,1) ak(1,11) ka(11,1)
        int arr2[] = {1, 1, 1};
        permute(arr2,0,3,"");
 cout<<"\n"; 
        // bf(2,6) z(26)
        int arr3[] = {2, 6};
        permute(arr3,0,2,"");
  cout<<"\n";
        // ab(1,2), l(12) 
        int arr4[] = {1, 2};
        permute(arr4,0,2,"");
  cout<<"\n";
        // a(1,0} j(10) 
        int arr5[] = {1, 0};
        permute(arr5,0,2,"");
  cout<<"\n";
        // "" empty string output as array is empty
        int arr6[] = {};
        permute(arr6,0,0,"");
  cout<<"\n";
        // abba abu ava lba lu
        int arr7[] = {1, 2, 2, 1};
        permute(arr7,0,4,"");
cout<<"\n";
/*	root=change_to_dll_left(root,NULL);
	root=update_right(root);
//	root=inorder_successor(root,NULL);
	display_left(root);
	display_right(root);
*/
//	inorder(temp);

/*	struct tree *root=NULL;

	root=create_complete_binary_tree(root,1);
	create_complete_binary_tree(root,2);
	create_complete_binary_tree(root,12);
	create_complete_binary_tree(root,3);
	create_complete_binary_tree(root,9);
	create_complete_binary_tree(root,2);
	create_complete_binary_tree(root,6);
	create_complete_binary_tree(root,4);
	create_complete_binary_tree(root,5);
	create_complete_binary_tree(root,7);
	create_complete_binary_tree(root,8);
	create_complete_binary_tree(root,10);
	create_complete_binary_tree(root,11);
	create_complete_binary_tree(root,13);

	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	preorder_iter(root);*/

	return 0;
}

/*
				 7
		    3        11
		 1    5    9    13
		0 2  4 6  8 10 12 14 
										*/
										

