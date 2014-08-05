#include<iostream>

using namespace std;

struct trie
{
	int flag;
	struct trie *child[26];
};

struct trie* create_trie(int data)
{
	struct trie* node=new trie;
	
	for(int i=0;i<26;i++)
		node->child[i]=NULL;
	
	node->flag=data;
	
	return node;
}

bool insert(struct trie *root,char a,char b)
{
	if(root->child[a-'a'])
	{
		if((root->child[a-'a'])->child[b-'a'])
			root->child[a-'a']->child[b-'a']->flag++;
		else
			root->child[a-'a']->child[b-'a']=create_trie(1);
		
		return true;
	}
	
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
			if(insert(root->child[i],a,b)==true)
				return true;
	}
	
	return false;
}

void insert_trie(struct trie *root,int a,int b)
{
	cout<<1;
	if(root==NULL)
		return;
		
	if(insert(root,a,b))
		return;

	
	root->child[a-'a']=create_trie(0);
	root->child[a-'a']->child[b-'a']=create_trie(1);

}

void display(struct trie *root,int cnt=0)
{
	if(root==NULL)
		return;
		
	for(int i=0;i<26;i++)
	{
		if(root->child[i])
		{
			if(cnt==0)
				cout<<"-->";
				
			else 
				for(int i=0;i<cnt;i++)
					cout<<"    |";
			
			cout<<char(i+'a');
			display(root->child[i],cnt+1);
		}
	}
}
int main()
{
	struct trie *root= create_trie(0);
	
	int n;
	char a,b;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		cout<<a<<b;
		insert_trie(root,a,b);
	}
	
	display(root,0);
}
