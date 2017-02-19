// https://people.eecs.berkeley.edu/~jrs/61b/lec/36

#include <iostream>

using namespace std;

struct SNode{
	int data;
	SNode* left;
	SNode* right;
};

SNode* right_rotate(SNode* x){
	SNode* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

SNode* left_rotate(SNode* x){
	SNode* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

SNode* splay(SNode* root, int data){
	if(root == NULL || root->data == data)
		return root;
	if(data < root->data){
		if(root->left == NULL) // If key is not present, take the last accessed node to the top.
			return root;
		if(root->left->data > data){
			root->left->left = splay(root->left->left, data);
			root = right_rotate(root);
		}
		else if(root->left->data < data){
			root->left->right = splay(root->left->right, data);
			if(root->left->right)
				root->left = left_rotate(root->left);
		}
		else
			return root->left ? right_rotate(root) : root;
	}
	else{
		if(root->right == NULL)
			return root;
		if(data < root->right->data){
			root->right->left = splay(root->right->left, data);
			if(root->right->left)
				root->right = right_rotate(root->right);
		}
		else if(data > root->right->data){
			root->right->right = splay(root->right->right, data);
			root = left_rotate(root);
		}
		return root->right ? left_rotate(root) : root;
	}
}

