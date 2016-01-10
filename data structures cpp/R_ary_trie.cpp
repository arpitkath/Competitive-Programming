/* 26-ary trie includes th following functions:
-insertion
-searching
-deleting word
-counting number of prefix
*/
#include<iostream>

using std::cout;
using std::string;

struct Node{
	int data;
	bool isEnd;
	Node* child[26];
};

//Initializing a empty trie
void initTrie(Node* root){
	root->data = 0;
	root->isEnd = false;
}
//Inserting string in trie
void insert(Node* root, string s){
	Node* curr = root;
	curr->data++;
	for(int i = 0; i < s.length(); i++){
		int letter = (int)s[i] - (int)'a';
		if(curr->child[letter] == NULL) curr->child[letter] = new Node();
		curr->child[letter]->data++;
	    curr = curr->child[letter];		
	}
	curr->isEnd = true;
}

//Searching words
bool searchWord(Node* root, string s){
	Node* curr = root;
	for(int i = 0; i < s.length(); i++){
		int letter = (int)s[i] - (int)'a';
		if(curr->child[letter] == NULL) return false;
		else curr = curr->child[letter];
	}
	return curr->isEnd;
}

//Delete word from trie
void deleteWord(Node* root, string s){
	Node* curr = root;
	root->data--;
	for(int i = 0; i < s.length(); i++){
		int letter = (int)s[i] - (int)'a';
		curr = curr->child[letter];
		curr->data--;
	}
	curr->isEnd = false;
}

//Find number of words with given prefix string
int prefixCount(Node* root, string pre){
	Node* curr = root;
	for(int i = 0; i < pre.length(); i++){
		int letter = (int)pre[i] - (int)'a';
		curr = curr->child[letter];
		if(!curr || curr->data == 0) return 0;
	}
	return curr->data;
}
int main(){
	Node* root = new Node();
	initTrie(root);
	insert(root, "abcd");
	insert(root, "abab");
	insert(root, "acb");
	insert(root, "alldone");
	insert(root, "huh");
	//cout<<root->child[0]->child[1]->data;
	//cout<<searchTrie(root, "abc");

}








