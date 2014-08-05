/*	
Find all possible interpretations of an array of digits
May 28, 2013

Consider a coding system for alphabets to integers where ‘a’ is represented as 1, ‘b’ as 2, .. ‘z’ as 26. 
Given an array of digits (1 to 9) as input, write a function that prints all valid interpretations of input array.
http://www.geeksforgeeks.org/find-all-possible-interpretations/
*/

#include<iostream>
#include<string.h>

using namespace std;

char alphabet[27][2] = {"", "a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "v", "z"};

struct tree* root=NULL;
char str1[100],strn[2];
int n,size=0,arr[100];

struct tree
{
	int len;
	char str[100];
	struct tree* left;
	struct tree* right;
}; 

struct tree* create_tree(char str1[], int val)
{
	struct tree* node= new struct tree;
	char strn[100];
	strcpy(strn,str1);
	node->len=val;
	strcpy(node->str,strn);
	
	if( ( ( ( arr[val+1] * 10 ) + arr[val+2] ) <= 26) && (val < n-2) )
	{
		strcat(strn,alphabet[arr[val+1]]);
		node->left=create_tree(strn,val+1);
		
		strcpy(strn,str1);
		strcat(strn,alphabet[10*arr[val+1]+arr[val+2]]);
		node->right=create_tree(strn,val+2);
	}
	
	else if(val < n-1)
	{
		strcat(strn,alphabet[arr[val+1]]);
		node->left=create_tree(strn,val+1);
		node->right=NULL;
	}
	
	else if(val==n-1)
	{
		cout<<node->str<<"->";
	}
	
	return node;
}

int main()
{
	int t;
	strcpy(str1,"");
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		struct tree* root=create_tree("",-1);
		cout<<"END";
	}
}
