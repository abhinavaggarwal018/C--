#include<abhinav.h>

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

int find_size(struct tree *root,int *minm,int *maxm,int *ans)
{
	if(root==NULL)
	{
		*maxm=max(*maxm,-1000);
		*minm=min(*minm,1000);
		
		return 0;
	}
	
	struct tree *temp=root;
	int left,right,min1=1000,min2=1000,max1=-1000,max2=-1000,cnt1=0,cnt2=0,cnt;
	
	left=find_size(root->left,&min1,&max1,ans);
	right=find_size(root->right,&min2,&max2,ans);
	
	cout<<max1<<":"<<min2<<":"<<root->data<<":"<<*ans<<"\n";
	
	if(left==0&&right==0)
		cnt=1;
		
	else if(left==0 && root->data < min2)
		cnt=1+right;

	else if(right==0 && root->data > max1)
		cnt=1+left;
		
	else if(root->data >max1 && root->data < min2)
		cnt=left+right+1;
			
	else 
		cnt=1;
		
	*ans=max(*ans,cnt);

		*maxm=max(root->data,max(max1,max2));
		
		*minm=min(root->data,min(min1,min2));
		
	return cnt;
}
int main()
{
      struct tree *root = create_tree(50);
	  root->left        = create_tree(10);
	  root->right       = create_tree(60);
	  root->left->left  = create_tree(5);
	  root->left->right = create_tree(20);
	  root->right->left  = create_tree(55);
	  root->right->left->left  = create_tree(45);
	  root->right->right = create_tree(70);
	  root->right->right->left = create_tree(65);
	  root->right->right->right = create_tree(80);

	//cout<<root->right;
	inorder(root);
	cout<<"END\n";

	int minm=1000,maxm=-1000,ans=0;
	find_size(root,&minm,&maxm,&ans);
	cout<<ans;
}
