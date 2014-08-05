#include<iostream>

using namespace std;

bool arr[100][100];

struct trie
{
	bool data;
	struct trie* next[2];
};

struct trie *create_node(bool data)
{
	struct trie* node=new struct trie;
	node->next[0]=NULL;
	node->next[1]=NULL;
	node->data=data;
}

void print_row(int i,int c)
{
	for(int j=0;j<c;j++)
		cout<<arr[i][j]<<" ";
	cout<<"\n";
}

void print(int r,int c)
{
	struct trie *root= create_node(0),*temp=root;

	for(int i=0;i<r;i++)
	{
		temp=root;
		bool to_print=false;
		for(int j=0;j<c;j++)
		{ 

			if(NULL==temp->next[arr[i][j]])
			{
				temp->next[arr[i][j]]=create_node(arr[i][j]);
				to_print=true;
			}
			temp=temp->next[arr[i][j]];
			
			if(j==c-1&&to_print)
				print_row(i,c);
			
		}
	}
}

int main()
{
	int r,c;

	while(1)
	{
		cin>>r>>c;
		
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>arr[i][j];
				
		print(r,c);
	}	
}
