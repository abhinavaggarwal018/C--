#include<iostream>
#include<cstring>

using namespace std;

int n;
char str1[100][100],str[100][100];

struct list
{
	int data;
	struct list *next;
};

struct trie
{
	bool end;
	struct trie *child[26];
	struct list *head;
};

struct list *create_list(int data)
{
	struct list *node=new struct list;
	node->next=NULL;
	node->data=data;
	return node;
}

struct trie *create_trie()
{
	struct trie *node= new struct trie;
	
	node->end=false;
	
	for(int i=0;i<26;i++)
		node->child[i]=NULL;
	
	node->head=NULL;
}

char* sort(char str[])
{
	for(int i=0;i<strlen(str);i++)
		for(int j=i+1;j<strlen(str);j++)
			if(str[j]<str[i])
			{
				char c=str[i];
				str[i]=str[j];
				str[j]=c;
			}
	
	return str;
}

void insert(struct trie* parent,int i, int ind,int len)
{
	struct trie *temp=parent;
	
	while(ind<len)
	{
		while(temp->child[(str[i][ind]-'a')]!=NULL&&ind<len)
		{
			temp=temp->child[(str[i][ind]-'a')];
	
			if(ind==len-1)
				temp->end=true;
	
			ind++;
		}
	
		if(ind<len)
		{
			temp->child[(str[i][ind]-'a')]=create_trie();
			temp=temp->child[(str[i][ind]-'a')];
		
			if(ind==len-1)
				temp->end=true;
		
			ind++;
		}
	}
	
	if(temp->head==NULL)
		temp->head=create_list(i);
	
	else
	{
		struct list *node=temp->head;
		
		while(node->next!=NULL)
			node=node->next;
			
		node->next=create_list(i);
	}
}

struct trie* print(struct trie * parent)
{
	if(parent->end==true)
	{
		struct list *temp=parent->head;
		
		while(temp)
		{
			cout<<str1[temp->data]<<"\n";
			temp=temp->next;
		}
	}

	for(int i=0;i<26;i++)
		if(parent->child[i]!=NULL)
		{
		/*	cout<<char(i+'a');
			cout<<parent->child[i]->end;
			if(parent->child[i]->end)
			{
				cout<<"HERE\n";
				if(parent->child[i]->head)
				cout<<parent->child[i]->head->data;
			}*/
			print(parent->child[i]);
		}	
			
}

using namespace std;

int main()
{
	while(1)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>str1[i];
			
			int len = strlen(str1[i]);
	        
			for(int i1=0;i1<len;i1++)
	        	str[i][i1]=str1[i][i1];
	        str[i][len]='\0';
	        
		}
		
		for(int i=0;i<n;i++)
			sort(str[i]);
			
		struct trie *parent=create_trie();
		
		for(int i=0;i<n;i++)
			insert(parent,i,0,strlen(str[i]));
		
		print(parent);
	}
}

