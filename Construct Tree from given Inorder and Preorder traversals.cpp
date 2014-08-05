#include<iostream>

using namespace std;

struct tree
{
	char data;
	struct tree *left;
	struct tree *right;
};

struct tree * create_tree(char c)
{
	struct tree *node=new struct tree;
	
	node->data=c;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}
//in_start: inorder position
int build_cnt=0;
struct tree* build_tree(char *in,char *pre, int in_strt, int in_end)
{
	if(in_strt>in_end)
		return NULL;
	
	struct tree *root = new struct tree;
	
	int in_pos;
	for(int i=in_strt;i<=in_end;i++)
		if(pre[build_cnt]==in[i])
		{
			in_pos=i;
			break;
		}
	root = create_tree(pre[build_cnt]);
	
	build_cnt++;
	
	if(in_strt == in_end)
    	return root;

	
//	root->left=build_tree(in,pre,in_strt,in_pos-1);
	root->right=build_tree(in,pre,in_pos+1,in_end);

	
	return root;
}

void inorder(struct tree* root)
{
	cout<<root->data<<"->";
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	int len = sizeof(in)/sizeof(in[0]);
	struct tree *root = build_tree(in, pre, 0, len-1);
	
	inorder(root);
}
