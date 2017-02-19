// Implementation of CLRS's RB tree algorithms.

#include <iostream>

using namespace std;

void left_rotate(RBNode*, RBNode*);
void right_rotate(RBNode* , RBNode* );
void insert(RBNode* , RBNode *);
void RB_insert_fixup(RBNode* , RBNode* );

string RED = "RED", BLACK = "BLACK";

struct RBNode{
	int data;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	string color; // Should be a boolean, but made a string to increase readability.
};

void left_rotate(RBNode* root, RBNode* z){
	RBNode* y = z->right;
	z->right = y->left;
	if(y->left)
		y->left->parent = z;
	y->parent = z->parent;
	if(!z->parent)
		root = y;
	else if(z == z->parent->left)
		z->parent->left = y;
	else
		z->parent->right = y;
	y->left = z;
	z->parent = y;
}

void right_rotate(RBNode* root, RBNode* z){
	RBNode* y = z->left;
	z->left = y->right;
	if(y->right)
		y->right->parent = z;
	y->parent = z->parent;
	if(!z->parent)
		root = y;
	else if(z == z->parent->left)
		z->parent->left = y;
	else
		z->parent->right = y;
	y->right = z;
	z->parent = y;
}

void insert(RBNode* root, RBNode* z){
	RBNode* y = NULL;
	RBNode* x = root;
	while(x){
		y = x;
		if(z->data > x->data)
			x = x ->right;
		else
			x = x->left;
	}
	z.parent = y;
	if(!y)
		root = z;
	else if(z->data < y->data)
		y->left = z;
	else
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = RED;
	RB_insert_fixup(root, z);
}

void RB_insert_fixup(RBNode* root, RBNode* z){

	while(z->parent->color == RED){
		if(z->parent == z->parent->parent->left){
			RBNode* y = z->parent->parent->right;
			if(y->color == RED){
				y->color = BLACK;
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->right){
					z = z->parent;
					left_rotate(root, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(root, z->parent->parent);
			}
		}
		else{
			RBNode* y = z->parent->parent->left;
			if(y->color == RED){
				y->color = BLACK;
				z->parent->color = RED;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->left){
					z = z->parent;
					right_rotate(root, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(root, z->parent->parent);
			}
		}
	}
}

