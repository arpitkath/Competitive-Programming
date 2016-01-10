/*This includes following functions:
-insertion
-finding height of node
-single rotate a node left
-single rotate a node right
-double rotate a node left
-double rotate a node right
-in order traversal
-check if given tree is AVL or not using level order traversal technique
*/

#include<iostream>
#include<cmath>
#include<queue>

#define max(a,b) (((a)>(b))?(a):(b))
using std::cout;

struct AVLNode{
	int data;
	int height;
	AVLNode* left;
	AVLNode* right;
};

//To initialize AVL  tree
void treeInit(AVLNode* root){
	
}
//To find height of any node
int nodeHeight(AVLNode* root){
	if(!root) return -1;
	return root->height;
}

//To single rotate a node left(used when insertion take place in left subtree of left child of "X" )
AVLNode* singleRotateLeft(AVLNode* root){
	AVLNode* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(nodeHeight(root->left), nodeHeight(root->right))+1;
	temp->height = max(nodeHeight(temp->left), nodeHeight(temp->right))+1;
	return temp;
}

//To single rotate a node right(used when insertion take place in right subtree of right child of "X" )
AVLNode* singleRotateRight(AVLNode* root){
	AVLNode* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(nodeHeight(root->left), nodeHeight(root->right))+1;
	temp->height = max(nodeHeight(temp->left), nodeHeight(temp->right))+1;
	return temp;
}

//To double rotate a node with left(used when insertion takes place in right subtree of left child of "X")
AVLNode* doubleRotateLeft(AVLNode* root){
	AVLNode* temp = root->left;
	root->left = singleRotateRight(temp);
	return singleRotateLeft(root);
}

//To double rotate a node with right(used when insertion takes place in left subtree of right child of "X")
AVLNode* doubleRotateRight(AVLNode* root){
	AVLNode* temp = root->right;
	root->right = singleRotateLeft(temp);
	return singleRotateRight(root);
}

//Insertion in AVL tree.
AVLNode* insertNode(AVLNode* root, int data){
	if(!root){
		root = new AVLNode();
		root->data = data;
		root->height = 0;
		root->left = root->right = NULL;
	}
	else if(data < root->data){
		root->left = insertNode(root->left, data);
		if(nodeHeight(root->left) - nodeHeight(root->right) == 2){
			if(data < root->left->data) root = singleRotateLeft(root);
			else root = doubleRotateLeft(root);
		}
	}
	else if(data > root->data){
		root->right = insertNode(root->right, data);
		if(nodeHeight(root->right) - nodeHeight(root->left) == 2){
			if(data > root->right->data) root = singleRotateRight(root);
			else root = doubleRotateRight(root);
		}
	}
	root->height = max(nodeHeight(root->left), nodeHeight(root->right))+1;
	return root;
}

//Inorder traversal
void inOrder(AVLNode* root){
	if(root){
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

//To check if given binary search tree is AVL tree or not using level order traversal technique.
bool isAVL(AVLNode* root){
	AVLNode* curr;
	std::queue<AVLNode* >q;
	q.push(root);
	while(!q.empty()){
		curr = q.front();
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
		if(abs(nodeHeight(root->left) - nodeHeight(root->right)) > 1) return false;
		q.pop();
	}
	return true;
}

int main(){
	AVLNode* root = NULL;
	root = insertNode(root, 5);
	root = insertNode(root, 11);
	root = insertNode(root, 8);
	root = insertNode(root, 15);
	root = insertNode(root, 4);
	cout<<isAVL(root);
	//inOrder(root);
}
