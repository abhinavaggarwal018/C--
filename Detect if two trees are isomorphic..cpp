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

int main()
{
	string str;
	struct trie *root=create_trie();
	cin>>str;
	insert(root,str,str.length(),0);
	cin>>str;
	insert(root,str,str.length(),0)	;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		search(root,str,str.length(),0)	;
	}
}
