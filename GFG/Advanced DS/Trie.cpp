#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

struct trie_t
{
	bool flag;
	trie_t *children[26];
	
	trie_t()
	{
		this->flag = false;
		for(int i=0;i<26;i++)
			this->children[i]=NULL;
				
	}
};

void initialize(struct trie_t *head)
{
	head->flag=false;
	for(int i=0;i<26;i++)
		head->children[i]=NULL;
		
	return;
}

int delete1(struct trie_t *node, char *str)
{
	if(strlen(str)==0)
	{
		for(int i=0;i<26;i++)
			if(node->children[i]!=NULL)
			{
				node->flag=false;
				return 0;
			}
		return 1;
	}
	
	if(node->children[str[0]-'a']==NULL)
	{
		cout<<"Element not found";
		return 0;
	}
	
	if(delete1(node->children[str[0]-'a'],str+1))
	{
		delete node->children[str[0]-'a'];
		node->children[str[0]-'a']=NULL;
		
		if(node->flag)
			return 0;
			
		for(int i=0;i<26;i++)
		{
			if(node->children[i])
				return 0;
		}
		
		return 1;
	}
	
	return 0;	
}

void insert(struct trie_t *node, char* str)
{
	if(strlen(str)==0)
	{
		node->flag=true;
		return;
	}
	
	if(node->children[str[0]-'a']!=NULL)
		return insert(node->children[str[0]-'a'],str+1);
		
	node->children[str[0]-'a'] = new trie_t();
	return insert(node->children[str[0]-'a'],str+1);	
}

int search(struct trie_t *node, char* str)
{
	if(strlen(str)==0)
	{
		if(node->flag)
			return 1;
		else
			return 0;
	}
	if(node->children[str[0]-'a']==NULL)
		return 0;
		
	return search(node->children[str[0]-'a'],str+1);
}

int main()
{
	char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    trie_t trie;
 
    initialize(&trie);
 
    for(int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
    {
        insert(&trie, keys[i]);
    }
 
    delete1(&trie, "sheer");
 
    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");
    printf("%s %s\n", "sells", search(&trie, "sells") ? "Present in trie" : "Not present in trie");
    printf("%s %s\n", "sea", search(&trie, "sea") ? "Present in trie" : "Not present in trie");
    printf("%s %s\n", "shore", search(&trie, "shore") ? "Present in trie" : "Not present in trie");
 
    return 0;
}
