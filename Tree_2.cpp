#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cassert>

using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* create_tree(int val)
{
	struct tree * node=new struct tree;
	
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	
	return node;	
}

vector<int> arr;

struct tree* create()
{

	struct tree *root=create_tree(6);
	root->left=create_tree(-13);
	root->right=create_tree(14);
	
	root->left->right=create_tree(-8);
	
	root->right->left=create_tree(13);
	root->right->right=create_tree(15);
	
	root->right->left->left=create_tree(7);
//	root->right->right=create_tree(25);
	//root->right->right->right=create_tree(8);
	
//	root->left->left->left=create_tree(1);
//	root->left->left->left->right=create_tree(30);
/*
	 	
	
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
	*/
	return root;
}

void inorder(struct tree * root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

void postorder(struct tree * root)
{
	if(root==NULL)
		return;
		
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"->";
}

bool is_balanced(struct tree *root,int &ht)
{
	if(root==NULL)
	{
		ht=0;
		return true;
	}
	int h1,h2;
	if(is_balanced(root->right,h1)&&is_balanced(root->left,h2))
	{
		if(abs((h1-h2))>1)
			return false;
		else
		{

			ht=1+max(h1,h2);
			return true;
		}
	}
	return false;
}

struct tree *construct_tree(int pre[],char preln[],int *ind,int n)
{
/*	Construct a special tree from given preorder traversal*/

	struct tree *node=create_tree(pre[*ind]);
	
	*ind++;
	if(pre[*ind]=='N')
	{
		node->left=construct_tree(pre,preln,ind,n);
		node->right=construct_tree(pre,preln,ind,n);
	}
	
	return node;
}

int diameter(struct tree *root,int &h)
{
	if(root==NULL)
	{
		h=0;
		return 0;
	}
	
	int d1,d2,h1,h2;
	
	d1=diameter(root->left,h1);
	d2=diameter(root->right,h2);

	h=1+max(h1,h2);
	return max(max(d1,d2),1+h1+h2);	
}

void preorder_2(struct tree *root)
{
	stack<tree*> s;
	s.push(root);
	
	while(!s.empty())
	{
		struct tree* node=s.top();
		s.pop();

		if(node->right)
			s.push(node->right);
		
		if(node->left)
			s.push(node->left);
		
		cout<<node->data<<"->";

	}
}

void inorder_2(struct tree *root)
{
	if(root==NULL)
		return;
		
	stack<tree *> s;

	struct tree *node=root;
	
	while(1)
	{
		
		while(node!=NULL)
		{
			s.push(node);
			node=node->left;
		}		
		
		if(s.empty())
			break;
			
		node=s.top();
			s.pop();
		
		cout<<node->data<<"->";
		
		node=(node->right);
		
	}
}

int width[100]; // array of size height of tree
void find_width(struct tree * root,int level)
{
	/*width of a binary tree*/
	if(root==NULL)
		return;

	width[level]++;
	
	find_width(root->left,level+1);
	find_width(root->right,level+1);	
}

void child_sum_prop(struct tree *root)
{
/*Convert an arbitrary Binary Tree to a tree that holds Children Sum Property*/
	if(root!=NULL)
	{
		if(root->left&&root->right)
		{
			child_sum_prop(root->left);
			child_sum_prop(root->right);
			
			struct tree *node=root;

			int diff_new=root->data-root->left->data-root->right->data;

				if(diff_new==0)
					return;
				else if(diff_new<0)
					root->data=root->left->data+root->right->data;
				else if(diff_new>0)
					while(node->left!=NULL)
					{
						node->left->data=node->left->data+diff_new;
						node=node->left;
					}
		}
		
		else if(root->left)
		{
			child_sum_prop(root->left);

			struct tree *node=root;

			int diff_new=root->data-root->left->data;
				if(diff_new==0)
					return;
				else if(diff_new<0)
					root->data=root->left->data;
				else if(diff_new>0)
					while(node->left!=NULL)
					{
						node->left->data=node->left->data+diff_new;
						node=node->left;
					}
		}
		
		else if(root->right)
		{
			child_sum_prop(root->right);

			struct tree *node=root;

			int diff_new=root->data-root->right->data;
				
				if(diff_new==0)
					return;
					
				else if(diff_new<0)
					root->data=root->right->data;
				
				else if(diff_new>0)
					while(node->right!=NULL)
					{
						node->right->data=node->right->data+diff_new;
						node=node->left;
					}
		}
	}
}

void find_path_sum(struct tree* root,int sum)
{
	/*Root to leaf path sum equal to a given number*/
	if(root==NULL)
	{
		cout<<sum<<" ";
		return;
	}
	
	//cout<<root->data<<" "<<sum<<"\n";
	find_path_sum(root->left,sum+root->data);
	find_path_sum(root->right,sum+root->data);
}

void double_tree(struct tree *root)
{
	if(root==NULL)
		return;
		
	struct tree* left=root->left;
	struct tree* node=create_tree(root->data);
	node->left=left;
	root->left=node;
	
	double_tree(left);
	double_tree(root->right);
}

bool is_foldable_main(struct tree* left,struct tree *right)
{
	if(left==NULL&&right==NULL)
		return true;
	
	if(left==NULL||right==NULL)
		return false;
		
	if(((left->left&&right->right)&&(left->right&&right->left))
	||((!left->left&&!right->right)&&(left->right&&right->left))
	||((left->left&&right->right)&&(!left->right&&!right->left))
	||((!left->left&&!right->right)&&(!left->right&&!right->left)))
	return is_foldable_main(left->left,right->right)&is_foldable_main(left->right,right->left);
	
	return false;
}

bool is_foldable(struct tree *root)
{
	if(root==NULL)
		return true;
	
	if(root->left==NULL&&root->right==NULL)
		return true;
	
	if(root->left!=NULL && root->right!=NULL)
		return is_foldable_main(root->left,root->right);
		
	return false;
}

void nodes_at_k_distance(struct tree*root, int level)
{
	if(root==NULL)
		return;
	
	if(level==0)
		cout<<root->data<<" ";
		
	else
		{
			nodes_at_k_distance(root->left,level-1);
			nodes_at_k_distance(root->right,level-1);
		}
}

void sorted_printing(int arr[],int level,int n)
{
	if(level>=n)
		return;
	/*Sorted order printing of a given array that represents a BST*/
	sorted_printing(arr,2*level+1,n);
	cout<<arr[level]<<" ";
	sorted_printing(arr,2*level+2,n);

}

void inorder_successor(struct tree* root,int data)
{
	static int flag=0;
	
	if(root==NULL)
		return;
	
	if(flag==2)
		return;
	
	inorder_successor(root->left,data);
	if(flag==1)
	{
		cout<<root->data;
		flag=2;
		return;
	}
	if(root->data==data)
		flag=1;
	inorder_successor(root->right,data);
}

void kth_smallest(struct tree *root,int k)
{
	static int cnt=0;
	if(cnt>k||root==NULL)
		return;
		
	kth_smallest(root->left,k);
	if(cnt==k)
		cout<<root->data;
	cnt++;
	kth_smallest(root->right,k);
}

int level_of_node(struct tree *root,int data,int level)
{
	if(root==NULL)
		return 0;
		
	if(root->data==data)
		return level;
		
	if(root->data<data)
		return level_of_node(root->right,data,level+1);
	
	else if(root->data>data)
		return level_of_node(root->left,data,level+1);
}

void print_keys(struct tree *root,int min,int max)
{
	if(root==NULL)
		return;
	
	if(root->data>=min&&root->data<=max)
	{
		print_keys(root->left,min,max);
		cout<<root->data<<"->";
		print_keys(root->right,min,max);
	}
	
	if(root->data<=min)
		return print_keys(root->right,min,max);
		
	if(root->data>=max)
		return print_keys(root->left,min,max);
}

bool is_sumtree(struct tree *root)
{
	if(root==NULL)
		return true;
		
	if(((root->left && root->left->left==NULL && root->left->right==NULL) 
		|| (root->left==NULL)) 
		&& ((root->right &&root->right->left==NULL && root->right->right==NULL) 
		|| (root->right==NULL)))
	{
		if(root->left&&root->right)
		{
			if(root->data==root->left->data+root->right->data)
				return true;
		}
		if(root->left&&!root->right)
		{
			if(root->data==root->left->data)
				return true;
		}
		if(!root->left&&root->right)
		{
			if(root->data==root->right->data)
				return true;
		}
		else
			return false;
	}
	
	if(root->data=2*(root->left->data+root->right->data))
		return is_sumtree(root->left)&is_sumtree(root->right);
	else
		return false;
}

int to_sumtree(struct tree *root)	
{
	if(root==NULL)
		return 0;
	
	
	if(root->left==NULL&&root->right==NULL)
	{
		int temp=root->data;
		root->data=0;
		return temp;
	}
	
	if(root->left==NULL)
	{
		int temp=root->data;
	
		if(root->right->right==NULL&&root->right->left==NULL)
			root->data=to_sumtree(root->right);
		else
			root->data=2*to_sumtree(root->right);	
		
		return temp;
	}
	
	if(root->right==NULL)
	{
		int temp=root->data;
	
		if(root->left->right==NULL&&root->left->left==NULL)
			root->data=to_sumtree(root->left);
		else
			root->data=2*to_sumtree(root->left);	
		
		return temp;
	}
	
	else
	{
		int temp=root->data;
	
		if(root->left->right==NULL&&root->left->left==NULL&&root->right->right==NULL&&root->right->left==NULL)
			root->data=to_sumtree(root->left)+to_sumtree(root->right);
		else
			root->data=(to_sumtree(root->left)+to_sumtree(root->right)+root->left->data+root->right->data);	
		
		return temp;
	}	
	
}

void vertical_sum(struct tree* root,int *arr,int pos)
{
	if(root==NULL)
		return;
	
	arr[pos]+=root->data;
	
	vertical_sum(root->left,arr,pos-1);
	vertical_sum(root->right,arr,pos+1);
}

int pos=0;
void sum_path(struct tree * root,int sum)
{
	if(root==NULL)
		return;

	sum+=root->data;
	if(root->left==NULL && root->right==NULL)
		cout<<sum<<" ";			
	sum_path(root->left,sum);
	sum_path(root->right,sum);
	sum-=root->data;
}

struct tree * construct_b_tree(int pre[],int post[],int start,int end)
{
	if(start>end)
		return NULL;
		
	static int pos1=0;
	int i;
	for(i=start;i<=end;i++)
	{
		if(post[i]==pre[pos1])
			break;
	}
	
	struct tree *root=create_tree(post[i]);
	pos1++;
	root->left=construct_b_tree(pre,post,start,i-1);
	root->right=construct_b_tree(pre,post,i+1,end);
}

void special_inorder(struct tree *root)
{
	if(root==NULL)
		return;
		
	special_inorder(root->left);
		
	if(root->left==NULL&&root->right==NULL)
		cout<<root->data<<"->";
		
	special_inorder(root->right);
}

void print_right_boundary(struct tree *root)
{
	if(root->right==NULL)
		return;
		
	print_right_boundary(root->right);
	
	cout<<root->data<<"->";
}

void boundary_traversal(struct tree *root)
{
	if(root==NULL)
		return;
		
	struct tree *temp=root;	
//	cout<<1;	
	while(temp->left)
	{
		cout<<temp->data<<"->";
		temp=temp->left;
	}
//	cout<<2;
	special_inorder(root);
	
	print_right_boundary(root->right);
	cout<<"NULL\n";
}

void find_floor(struct tree *root,int num)
{
	static bool abcd=false;
	
	if(abcd==true || root==NULL)
		return;
	
	find_floor(root->left,num);
	
	if(root->data<num)
		abcd=false;
		
	if(root->data>=num)
	{
		cout<<root->data<<"->";
		abcd=true;
		return;
	}
			
	find_floor(root->right,num);
	
}

struct tree* construct_from_preorder(int pre[],int *ind,int min,int max,int end)
{
	if(*ind>=end)
		return NULL;
		
	struct tree *root=NULL;
	
	if(pre[*ind]<=max&&pre[*ind]>=min)
	{
		root=create_tree(pre[*ind]);
		*ind=*ind+1;
		
		if(pre[*ind]<end)
		{
			root->left=construct_from_preorder(pre,ind,min,pre[*ind-1],end);
			root->right=construct_from_preorder(pre,ind,pre[*ind-1],max,end);
		}
	}
	
	return root;
}

void sum_of_greater_keys(struct tree *root,int *sum)
{
	if(root==NULL)
		return;
		
	sum_of_greater_keys(root->right,sum);
	*sum=*sum+root->data;
	root->data=*sum;
	sum_of_greater_keys(root->left,sum);
}

int largest_independant_set(struct tree *root)
{
	if(root==NULL)
		return 0;
	
	return max(1+(root->left?(largest_independant_set(root->left->left)+largest_independant_set(root->left->right)):0)+((root->right?(largest_independant_set(root->right->left)+largest_independant_set(root->right->right)):0)),largest_independant_set(root->left)+largest_independant_set(root->right));
}

struct tree *remove_keys(struct tree *root,int min,int max)
{
	if(root==NULL)
		return NULL;
	

	if(root->data<=max && root->data>=min)
	{
			cout<<1;
		root->left=remove_keys(root->left,min,max);
		root->right=remove_keys(root->right,min,max);
		cout<<1;
		return root;
	}
	
	else if(root->data > max)
	{
			cout<<2;
		struct tree *temp=root->left;
		delete root;
		cout<<2;
		return remove_keys(temp,min,max);
	}
	
	else if(root->data < min)
	{
			cout<<3;
		struct tree *temp=root->right;
		delete root;
		cout<<3;
		return remove_keys(temp,min,max);
	}
}

struct tree * to_dll(struct tree *root)
{
	if(root==NULL)
		return NULL;
	
	struct tree *left=root->left;
	struct tree *right=root->right;
		
	if(root->left)
	{
		struct tree *node=to_dll(root->left);
		
		while(node->right)
			node=node->right;
			
		root->left=left;
		left->right=root;
	}
	
	if(root->right)
	{
		struct tree *node=to_dll(root->right);
		
		while(node->left)
			node=node->left;
			
		root->right=node;
		node->left=root;
	}
	
	return root;
}

/*
struct tree *to_dll(struct tree *root, struct tree *prev,char c)
{
	if(root==NULL)
			return NULL;
			
	if(c=='L')
	{
		root->left=to_dll(root->left,root,'L');
		to_dll(root->right,root,'R');
	}
	else if(c=='R')
	{
		to_dll(root->left,root,'R');
		root->right=to_dll(root->right,root,'L');
	}
}
*/
void print(struct tree *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<"->";
		root=root->left;
	}
}

bool is_identical_bst(int a[],int b[],int n,int *i1)
{
	int min1=a[*i1],max1=a[*i1],min2=a[*i1],max2=a[*i1];
	bool flag,flag1,flag2;	
	flag1=false;
	flag2=false;
	
	for(int i=*i1;i<n && (!flag1 || !flag2);i++)
	{
		if(a[i]<min1 && flag1==false)
		{
			min1=a[i];
			flag1=true;
		}
		if(a[i]>max1 && flag2==false)
		{
			max1=a[i];
			flag2=true;
		}
	}
	
	flag=false;
	flag1=false;
	flag2=false;
	
	for(int i=0;i<n && (!flag1 || !flag2);i++)
	{
		if(a[*i1]==b[i])
			flag=true;
			
		else if(flag==true)
		{
			//cout<<"FLAG TRUE:"<<b[i]<<":"<<(b[i]<min1)<<":"<<(b[i]>max1)<<"\n";
			if(b[i]<min2 && flag1==false)
			{
			//	cout<<"MIN"<<min2<<"->"<<b[i]<<"\n";
				min2=b[i];
				flag1=true;
			}
			if(b[i]>max2 && flag2==false)
			{
			//	cout<<"MAX"<<max2<<"->"<<b[i]<<"\n";
				max2=b[i];
				flag2=true;
			}
		}
	}
	

	
	cout<<a[*i1]<<":"<<min1<<" "<<max1<<" "<<min2<<" "<<max2<<"\n";

	*i1=*i1+1;
	
	if((min1==a[*i1-1]||max1==a[*i1-1])&&(min2==a[*i1-1]||max2==a[*i1-1]))
		return is_identical_bst(a,b,n,i1);
		
	if((min1==a[*i1-1]||max1==a[*i1-1])||(min2==a[*i1-1]||max2==a[*i1-1]))
		return false;
		
	if(min1==min2 && max1==max2)
		return is_identical_bst(a,b,n,i1);
	
	return false;
	
}

void print_ancestors(struct tree *root)
{
	stack<struct tree *> s;
	s.push(root);
		while(1)
		{
			struct tree *node=s.front();
			
			if(node->right)
				s.push(node->right);
			if(node->left)
				s.push(node->left);
			
			{	
				if(node->left)
					node=node->left;
				else if(node->right)
					node=node->right;
				else
					break;
			}
		}
		
	}
}

int main()
{
	struct tree *root=create();
	
	inorder(root);
	cout<<"\n";
	
	//child_sum_prop(root);
	
//	postorder(root);
//	cout<<"\n";
	
//	int ht;
//	cout<<is_balanced(root,ht);
//	cout<<":"<<ht<<"\n";
	
//	cout<<diameter(root,ht)<<"\n";
	
//	find_path_sum(root,0);

//	double_tree(root);

/*	for(int i=0;i<100;i++)
		width[i]=0;
	
	find_width(root,0);

	for(int i=0;i<5;i++)
		cout<<width[i]<<" ";
*/
	
//	cout<<"\nFoldable:";
//	cout<<is_foldable(root)<<"\n";			

/*	nodes_at_k_distance(root,3);
	cout<<"\n";
*/

/*	int arr[]={4, 2, 5, 1, 3};
	int n=5;
	sorted_printing(arr,0,n);
*/	

//	inorder_successor(root,7);

//	kth_smallest(root,8);
		
//	cout<<level_of_node(root,68,1);

//	print_keys(root,2,12);

//	cout<<is_sumtree(root);


//	to_sumtree(root);
	
/*	int arr[20]={0};
	vertical_sum(root,arr,10);
	
	for(int i=0;i<20;i++)
		cout<<arr[i]<<" ";
*/
	
//	sum_path(root,0);

/*
	struct tree *root1 = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    // construct the above tree
    int ind=0;
    root1 = construct_tree (pre, preLN, &ind,n);
 
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    inorder (root1);*/		

  /*  int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );

	struct tree *root1= construct_b_tree(pre,post,0,size-1);
	
	inorder(root1);
	cout<<"\n";
	postorder(root1);
*/
	
//	boundary_traversal(root);

//	find_floor(root,8);
	
/*	int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] ),ind=0;
	
	struct tree* root1=construct_from_preorder(pre,&ind,INT_MIN,INT_MAX,size);
	inorder(root1);*/

//	int sum=0;
//	sum_of_greater_keys(root,&sum);

//	cout<<largest_independant_set(root);

//	root=remove_keys(root,8,16);

//	root=to_dll(root);
//	print(root);

   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   int i1=0;
   printf("%s\n", is_identical_bst(a, b, n,&i1)?
             "BSTs are same":"BSTs not same");

	cout<<"\n";
	inorder(root);
	cout<<"\n";
	
}

/*
				 7
		    3        11
		 1    5    9    13
		0 2  4 6  8 10 12 14 
										*/
