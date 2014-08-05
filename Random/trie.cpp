#include<iostream>
#include<string>
using namespace std;

struct trie {
	char data;
	struct trie* child[26];
	bool flag;
	
	trie(char data1) {
		
		data = data1;
		flag = false;
		
		for(int i=0; i<26; i++)
			child[i] = NULL; 
	}
};

void addChild(string str, int index, struct trie *root) {
	if(str.length() == index) {
		root->flag = true;
		return;
	}
	
	if(root->child[str[index]-'a'] == NULL) {
		root->child[str[index]-'a'] = new trie(str[index]);
	}
	
	addChild(str, index+1, root->child[str[index]-'a']);
}

void viewChild(struct trie *root, int pos, string str) {
	if(root->flag == true) {
		cout<<str<<"\n";
	}
	
	bool flag = false;
	
	for(int i=0; i<26; i++) {
		if(root->child[i] != NULL) {
			str = str + root->child[i]->data;
			viewChild(root->child[i], pos+1, str);
		}
	}
	str.resize(str.length()-1);
}

void deleteChild(struct trie *root, int index, string str) {
	
}

int main() {
	int n;
	string str;
	
	cin>>n;
	struct trie * root = new trie('~');
	
	for(int i=0; i<n; i++) {
		cin>>str;
		addChild(str, 0, root);
		str = "";
		viewChild(root, 0, str);
	}
}
