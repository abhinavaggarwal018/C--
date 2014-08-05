#include<iostream>
#include<stack>
#include<queue>

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


int inorder(struct tree *root)
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

int preorder_without_recursion(struct tree*root)
{
	struct tree*node=root;
	stack<struct tree*> s;
	while(!s.empty()||node!=NULL)
	{
		if(node!=NULL)
		{
			cout<<(node->data)<<"->";  //for preorder
			s.push(node);
			node=node->left;
		}
		else
		{
			node=s.top();
			s.pop();
			//cout<<(node->data)<<"->";  // for inorder
			node=node->right;
		}
	}
		cout<<"END\n";
}

int postorder_without_recursion(struct tree* root)
{
	stack<struct tree*> s;
	struct tree *node =root;
	while(!s.empty()||node!=NULL)
	{
		if(node!=NULL)
		{
			if(node->right!=NULL)
			s.push(node->right);
			s.push(node);
			node=node->left;
		}
		else
		{
			node=s.top();
			s.pop();
			struct tree* node1;
			if(!s.empty())
			node1=s.top();
			else
			node1=NULL;
			if(node->right==node1)
			{
				s.pop();
				s.push(node);
				node=node->right;
			}
			else
			{
				cout<<node->data<<"->";
				node=NULL;
			}
		}
	}
	cout<<"END\n";
}

void level_order(struct tree* root)
{
	struct tree* curr;
	queue<struct tree*> q;
	q.push(root);
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		cout<<(curr->data)<<"->";
		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!=NULL)
			q.push(curr->right);
	}
	cout<<"END\n";
}

void zig_zag(struct tree* root)
{
	deque<struct tree*> dq;
	struct tree* curr;
	dq.push_back(root);
	bool flag=1,num1=0;   // flag=1 signifies start from front and flag=0 signifies start from end.
	int cnt1=1,cnt=0;
	while(!dq.empty())
	{
		cnt1--;
		if(flag==1)
		{
			//cout<<"f1*";
			curr=dq.front();
			dq.pop_front();
			cout<<curr->data<<"->";
			
			if(cnt1==0)
				num1=1;
			
			if(curr->left!=NULL)
			{
				cnt++;
				dq.push_back(curr->left);
			}
			
			if(curr->right!=NULL)
			{
				cnt++;
				dq.push_back(curr->right);
			}
			
			if(num1==1)
			{
				if(flag==1)
					flag=0;
				else
					flag=1;
				num1=0;
				cnt1=cnt;
				cnt=0;
			}
		}
		else if(flag==0)
		{
			//cout<<"f0*";
			curr=dq.back();
			dq.pop_back();
			
			cout<<curr->data<<"->";
			
			if(cnt1==0)
				num1=1;
			
			if(curr->right!=NULL)
			{
				cnt++;
				dq.push_front(curr->right);
			}
			
			if(curr->left!=NULL)
			{
				cnt++;
				dq.push_front(curr->left);
			}
			
			if(num1==1)
			{
				if(flag==1)
					flag=0;
				else
					flag=1;
				num1=0;
				cnt1=cnt;
				cnt=0;
			}
		}
	}
	cout<<"END\n";	
}

bool check_exist(struct tree* root,int val)
{
	if(root==NULL)
		return false;
	if(root->data==val)
		return true;
	if((root->data)>val)
		return check_exist(root->left,val);
	if(root->data<val)
		return check_exist(root->right,val);
}

void least_common_ancestor(struct tree* root, int val1,int val2)
{
	
	if(val1>val2)
		swap(val1,val2);
	
	if(root==NULL)
	{
		cout<<"These elements are not present in tree :END\n";
		return;
	}
	
	if(val1<=(root->data)&&val2>=root->data)
	{
		if(check_exist(root,val1)&&check_exist(root,val2))
		{
			cout<<"LCA is for root having data as "<<root->data<<":END\n";
			return;
		}
		
		else
		{
			cout<<"These elements are not present in tree :END\n";
			return;
		}
	}
	
	else if(root->data<val2)
		least_common_ancestor(root->right,val1,val2);
	
	else if(root->data>val2)
		least_common_ancestor(root->left,val1,val2);
	
}

void height(struct tree* node,int curr_height)
{
	//Write a C program to find the depth or height of a tree.
	if(node==NULL)
	{
	
		if(curr_height>max_height)
			max_height=curr_height;
		return;
	
	}
	
	height(node->left,curr_height+1);
	height(node->right,curr_height+1);

}

void elements(struct tree* node)
{
	//Write a C program to determine the number of elements (or size) in a tree.
	if(node==NULL)
		return;
	
	no_of_elements++;
	elements(node->left);
	elements(node->right);	
}

struct tree* destroy(struct tree* node)
{
	//Write a C program to delete a tree (i.e, free up its nodes)
	if(node==NULL)
		return NULL;
		
	struct tree* left1=node->left;
	struct tree* right1=node->right;
	
	delete node;
	destroy(left1);
	destroy(right1);
}

bool is_identical(struct tree* node1,struct tree* node2)
{
	if(node1==NULL&&node2==NULL)
		return true;
	if(node1==NULL||node2==NULL)
		return false;
	if(node1->data!=node2->data)
		return false;
	if(node1->data==node2->data)
		return is_identical(node1->left,node2->left) & is_identical(node1->right,node2->right);
	
}

void clone(struct tree*node1,struct tree*node2)
{
	if(node1==NULL)
	{
		node2=NULL;
		return;
	}
	
	node2->data=node1->data;
	
	node2->left = new struct tree;
	node2->right = new struct tree;
	
	clone(node1->left,node2->left);
	clone(node1->right,node2->right);

}

struct tree* mirror(struct tree* node1)
{
	struct tree* node= new struct tree;
	
	if(node1==NULL)
	{
		node=NULL;
		return node;
	}
	node->data=node1->data;
	
	/*METHOD1
	node->left=mirror(node1->left);
	node->right=mirror(node1->right);
	
	struct tree *temp;
	temp=node->left;
	node->left=node->right;
	node->right=temp;*/
	
	node->left=mirror(node1->right);
	node->right=mirror(node1->left);
	
	return node;
}

void delete_node(struct tree *node, struct tree* prev, int val)
 //'c' denotes prev chile left or right child having value L or R
{
	if(node==NULL)
	{
		cout<<"Node does not exist:END\n";
		return;
	}
	
	else if(node->data==val)
	{
		//cout<<"1";
		if(node->left==NULL && node->right==NULL)
		{
			//cout<<"2";
			if(prev->left->data==val)
				prev->left=NULL;		
			
			else
				prev->right=NULL;
			
			//cout<<"2.5";
			delete node;
			//cout<<"3.5";
		}
		else if(node->left==NULL)
		{
			//cout<<"3";
			if(prev->left->data==val)
				prev->left=node->right;
			
			else
				prev->right=node->right;
			
			delete node;
		}

		else if(node->right==NULL)
		{
			//cout<<"4";
			if(prev->left->data==val)
				prev->left=node->left;
			
			else
				prev->right=node->left;
			
			delete node;
		}
		
		else
		{
			//can be done by deleating largest value in left subtree
			struct tree* temp=node->left;
			int val1;
			
			if(temp->right==NULL)
			{
				val1=temp->data;
				delete_node(temp,node,val1);
			}
			
			else
			{
				while(temp->right->right!=NULL)
				{
					temp=temp->right;
				}
				
				val1=temp->right->data;
				
				delete_node(temp->right,temp,val1);
			}
			
			node->data=val1;
			
		}
		return;
	}
	
	else if( node->data > val)
		delete_node(node->left,node,val);
		
	else 
		delete_node(node->right,node,val);
		
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

	return root;
}

bool is_isomorphic(struct tree *node1,struct tree* node2)
{
/*	Write a function to detect if two trees are isomorphic. 
Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. 
Any number of nodes at any level can have their children swapped.
Two empty trees are isomorphic.
*/
	if(node1==NULL && node2==NULL)
		return true;
		
	if(node1==NULL||node2==NULL)
		return false;
	else
		return ((node1->data==node2->data)&((is_isomorphic(node1->left,node2->left)&is_isomorphic(node1->right,node2->right))||(is_isomorphic(node1->right,node2->left)&is_isomorphic(node1->left,node2->right))));
}

struct tree* remove_keys(struct tree *node, int min,int max)
{
	if(node==NULL)
		return NULL;
		
	if(node->left!=NULL)
		node->left=remove_keys(node->left,min,max);
		
	if(node->right!=NULL)
		node->right=remove_keys(node->right,min,max);
		
	struct tree* temp=node->right;
	
	if(node->data<min)
	{
		temp=node->right;
		delete node;
		return temp;
	}
		
	if(node->data>max)
	{
		temp=node->left;
		delete node;
		return temp;
	}	
		
	return node;
}

/*
struct tree* remove_keys(struct tree *node,int min,int max)
{	
	if(node==NULL)
		return node;
	
	cout<<":>"<<node->data<<"<:";
	
	if(node->data<min)
	{
		cout<<1;
		struct tree *temp=node->left;
		delete node;
		destroy(temp);
		return remove_keys(node->right,min,max);
	}
	
	else if(node->data>max)
	{
		cout<<2;
		struct tree* temp=node->right;
		delete node;
		destroy(node->right);
		return remove_keys(node->left,min,max);
	}
	
	cout<<3;
	
	node->left=remove_keys(node->left,min,max);
	node->right=remove_keys(node->right,min,max);
	
	cout<<4;
	
	return node;
}
*/
int  main()
{
	int n;
	int val,num;
	//cin>>val;
	struct tree *root=create_tree(7);
	//cin>>num;
	//while
	//(num--)
	//{
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
		//root->right=insert(root->right,b);
	//}

	//cout<<root->right;
	inorder(root);
	cout<<"END\n";

	preorder(root);
	cout<<"END\n";

	postorder(root);
	cout<<"END\n";
	
	preorder_without_recursion(root);
	
	postorder_without_recursion(root);
	
	level_order(root);
	
	zig_zag(root);
	
	max_height=0;
	height(root,0);
	cout<<"Maximum Height="<<max_height<<"\n";
	
/*	int min1,max1;
	cin>>min1>>max1;
	root=remove_keys(root,min1,max1);
	inorder(root);
	cout<<"END\n";
*/	
	cin>>num;
	delete_node(root,NULL,num);
	level_order(root);
	
	no_of_elements=0;
	elements(root);
	cout<<"Elements="<<no_of_elements<<"\n";
/*	
	root=destroy(root);
	inorder(root);
*/	
	struct tree* root_temp;
	root_temp=mirror(root);
	inorder(root_temp);
	cout<<"END\n";
	
		
	struct tree *n1 = create_tree(1);
    n1->left        = create_tree(2);
    n1->right       = create_tree(3);
    n1->left->left  = create_tree(4);
    n1->left->right = create_tree(5);
    n1->right->left  = create_tree(6);
    n1->left->right->left = create_tree(7);
    n1->left->right->right = create_tree(8);
 
    struct tree *n2 = create_tree(1);
    n2->left         = create_tree(3);
    n2->right        = create_tree(2);
    n2->right->left   = create_tree(4);
    n2->right->right   = create_tree(5);
    n2->left->right   = create_tree(6);
    n2->right->right->left = create_tree(8);
    n2->right->right->right = create_tree(7);
 
    if (is_isomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
	
	//clone(root,root_temp);
	if(is_identical(root,root_temp)==true)
		cout<<"Identical Trees :END\n";
	else
		cout<<"Non Identical Trees:END\n";
	
	int val1,val2;
	cin>>val1>>val2;
	least_common_ancestor(root,val1,val2);

}



/*
				 7
		    3        11
		 1    5    9    13
		0 2  4 6  8 10 12 14 
										*/
