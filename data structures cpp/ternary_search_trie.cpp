/*This ternary trie includes following:
-insertion
-searching
-printing all strings in alphabetical order using in order technique
*/

#include<iostream>

using std::cout;
using std::string;

struct Node{
	int data;
	bool isEnd ;
	Node *left, *eq, *right;
};

//Utility function for insertion
Node* insert(Node* root, string s, int i){
	int letter = (int)s[i] - (int)'a';
	if(!root){
		root = new Node();
		root->data = letter;
	}
	if(letter < root->data) root->left = insert(root->left, s, i);
	else if(letter > root->data) root->right = insert(root->right, s, i);
	else if(i < s.length() -1) root->eq = insert(root->eq, s, i+1);
	else {
		root->data = letter;
		root->isEnd = true;
	}
	return root;
}

//Inserting string in trie
void insert(Node* root, string s){
	root = insert(root, s, 0);
}

//Utility function for Searching word in trie
Node* search(Node* root, string s, int i){
	if(root==NULL) return NULL;
	int letter = (int)s[i] - (int)'a';
	if(letter < root->data) return search(root->left, s, i);
	else if(letter > root->data) return search(root->right, s, i);
	else if(i < s.length() - 1) return search(root->eq, s, i+1);
	else return root;
}

//Search word in trie
bool search(Node* root, string s){
	Node* curr = search(root, s, 0);
	if(!curr) return false;
	else return curr->isEnd;
}

//Utility fucntion for-Print all strings in trie using in order technique
void printAll(Node* root, string s){
	if(root){
		printAll(root->left, s);
		if(root->isEnd) cout << s +(char)(root->data + (int)'a')<< "\n";
		printAll(root->eq, s+(char)(root->data + (int)'a'));
		printAll(root->right, s);
	}
}

//Print all strings in trie using in order technique
void printAll(Node* root){
	printAll(root, "");
}

int main(){
	Node *root = new Node();
	insert(root,"hello");
	insert(root,"low");
	insert(root,"wassup");
	insert(root,"what");
	insert(root,"abcd");
	insert(root,"ok");
	printAll(root);
	//cout<<search(root, "cdeggg");
}
