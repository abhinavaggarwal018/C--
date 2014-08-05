/* http://www.geeksforgeeks.org/trie-insert-and-search/ 
Every node of trie consists of multiple branches. 
Each branch represents a possible character of keys. 
We need to mark the last node of every key as leaf node.*/

#include<iostream>
#include<stdio.h>

using namespace std;

struct trie{
	bool flag;
	struct trie* children[26];
};

struct trie* create_trie()
{
	struct trie *node=new struct trie;
	
	node->flag=false;
	
	for(int i=0;i<26;i++)
		node->children[i]=NULL;
	
	return node;
}

void insert(struct trie *node, string str, int max_len, int level)
{
	
	if(level<max_len-1)
	{	
		if(node->children[str[level]-'a']==NULL)
			node->children[str[level]-'a']= create_trie();
		insert(node->children[str[level]-'a'],str,max_len,level+1);
	}
	
	else if(level==max_len-1)
	{
		if(node->children[str[level]-'a']==NULL)
			node->children[str[level]-'a']= create_trie();
		node->children[str[level]-'a']->flag=true;
	}
}
//level is no. of characters completed
void search(struct trie *node, string str, int max_len, int level)
{
	if(node->children[str[level]-'a']==NULL)
	{
		if(level==0)
			cout<<"No character begins with such string:END\n";
			
		else if(level==max_len && node->flag==true)
			cout<<"The complete match obtained is: " << str <<" :END\n"; 				
			
		else if(node->flag==false)
		{
			cout<<"The incomplete match obtained is: ";
			for(int i=0;i<level;i++)
				cout<<str[i];
			cout<<" :END\n"; 	
		}
		
		else if(node->flag==true)
		{
			cout<<"The maximum level obtained is the length of such max string: ";
			for(int i=0;i<level;i++)
				cout<<str[i];
			cout<<" :END\n"; 	
		}		
	}
		
	else if(level==max_len-1 && node->children[str[level]-'a']->flag==false)
	{
		cout<<"This incomplete match obtained is: ";
		for(int i=0;i<=level;i++)
			cout<<str[i];
		cout<<" :END\n"; 	
	}
	
	else if(level==max_len-1 && node->children[str[level]-'a']->flag==true)
	{
		cout<<"This complete match obtained is: "<<str<<" :END\n"; 	
	}
	
	else if(level < max_len-1)
		search(node->children[str[level]-'a'],str,max_len,level+1);
	
	else
		cout<<"ERROR!!!\n";
}

bool delete_trie(struct trie *root, string str, int idx, int n, bool &done)
{
	if(root==NULL)
		return false;
		
	if(root->children[str[idx]-'a'])
	{
		cout<<str[idx];
		
		if(idx==n-1)
		{
			root->children[str[idx]-'a']->flag=false;
			
			for(int i=0;i<26;i++)
				if(root->children[str[idx]-'a']->children[i])  // case where it is part of larger substring
					done=true;
			
			if(done==false)
			{
				delete root->children[str[idx]-'a'];
				root->children[str[idx]-'a']=NULL;
			}
			
		}
		
		else if(done==false)
		{
			delete_trie(root->children[str[idx]-'a'],str,idx+1,n,done);
			//cout<<"A:"<<done;
			
			if(root->children[str[idx]-'a']->flag==true)
				done=true;
				
			else	
				for(int i=0;i<26;i++)
					if(root->children[str[idx]-'a']->children[i])
					{
			//			cout<<"i:"<<i;
						done=true;
					}
			
			if(done==false)
			{
				delete root->children[str[idx]-'a'];
				root->children[str[idx]-'a']=NULL;
			}
			
		}
		
		return true;
	}
	
	return false;
}

int main()
{
	string str;
	struct trie *root=create_trie();
	
	int t;
	
	cout<<"\n1. Insert\n2.Search\n3.Delete\n4.Exit\n";

	while(1)
	{
		cout<<"\nYourChoice: ";
		cin>>t;
		
		if(t==4)
			return 0;
		
		int n=str.length();
		bool done;
		
		cout<<"\nEnter String: ";
		cin>>str;
	
		done=false;
		
		if(t==1)
			insert(root,str,str.length(),0)	;
		
		else if(t==2)
			search(root,str,str.length(),0)	;
		
		else if(t==3)
		{
			if(delete_trie(root, str, 0, n, done))
				cout<<"\nSuccessful";
			else
				cout<<"\nNo such node exists";
		}
	}
}
