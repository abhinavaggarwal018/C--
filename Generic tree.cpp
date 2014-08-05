#include<iostream>
#include<queue>

using namespace std;

struct generic_tree
{
	int data;
	queue <generic_tree*> q;
};

struct generic_tree* create_tree(int val,int val2,int val3)
{
	struct generic_tree * node=new generic_tree;
	cout<<"1";
	node->data=val;
	
	if(val2!=NULL)
		node->q.push(create_tree(val2,NULL,NULL));

	
	if(val3!=NULL)
		node->q.push(create_tree(val3,NULL,NULL));
	cout<<"2";

}


void display(struct generic_tree* root)
{
	if(root==NULL)
		return;
	struct generic_tree* temp=root;
	cout<<(root->data)<<"->";
	queue<struct generic_tree*> node(root->q);
	while(!node.empty())
	{
		temp=node.front();
		node.pop();
		display(temp);
	}
}

int main()
{
	struct generic_tree *root=create_tree(4,1,2);
	display(root);
}


