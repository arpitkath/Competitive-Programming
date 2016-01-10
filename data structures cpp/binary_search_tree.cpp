/*This includes the following:
-insert nodes
-search node
-find parent of a node
-minimum element
-maximum element
-pre order,post order, in order traversal.
-level order traversal
-deleting nodes
-finding height of tree
-deleting the tree using post order.
-Check if a path exists for a perticular sum
-finding least common ancestor
*/

#include<iostream>
#include<queue>

#define max(a,b) ( ((a)>(b)) ? (a) : (b) )

using std::cout;

struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
	//BSTNode* parent;
};

//To initialize a binary search tree.
void BSTInit(BSTNode* root, int data){
	root->data = data;
	root->left = root->right = NULL;
}

//To insert nodes to tree.
void insertNode(BSTNode* root, int data){
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	while(1){
		if(data < root->data){
			if(!root->left){
				root->left = newNode;
				break;
			}
			else root = root->left;
			
		}
		else{
			if(!root->right){
				root->right = newNode;
				break;
			}
			else root = root->right;
		}
	}
}

//Searching if a element is present or not, if exist return the node.
BSTNode* searchTree(BSTNode* root, int data){
	while(root){
		if(data == root->data) return root;
		else if(data > root->data) root = root->right;
		else root = root->left;
	}
	return NULL;
}
//Finding parent of a given node
BSTNode* findParent(BSTNode* root, int data){
	BSTNode* curr = NULL;
	while(root){
		//if(!root) return NULL;
		if(data == root->data) break;
		else if(data > root->data){
			curr = root;
			root = root->right;
		}
		else{
			curr = root;
			root = root->left;
		}
	}
	return curr;
}
//Finding minimum element in tree
int findMin(BSTNode* root){
	while(root->left) root = root->left;
	return root->data;
}

//Finding maximum element in tree
int findMax(BSTNode* root){
	while(root->right) root = root->right;
	return root->data;
}

//Pre order traversal.
void preOrder(BSTNode* root){
	if(root){
		cout << root->data << " " ;
		preOrder(root->left);
		preOrder(root->right);
	}
}

//Post order traversal.
void postOrder(BSTNode* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " " ;
	}

}
//In order traversal.
void inOrder(BSTNode* root){
	if(root){
		inOrder(root->left);
		cout << root->data << " " ;
		inOrder(root->right);
	}
}
//Deleting a node in binary search tree.
BSTNode* deleteNode(BSTNode* root, int data){
	BSTNode* temp ;
	if(root == NULL) cout << "No node to delete!\n";
	else if(data < root->data) root->left = deleteNode(root->left, data);
	else if(data > root->data) root->right = deleteNode(root->right, data);
	else{
		if(root->left == NULL && root->right==NULL){
			delete root;
			root=NULL;
		}
		else if(root->left==NULL){
			temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL){
			temp=root;
			root=root->left;
			delete temp;
		}
		else{
			temp=searchTree(root->right,findMin(root->right));
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
	return root;
	}
}

//Find height of tree.
int getHeight(BSTNode* root){
	if(!root) return -1;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

//Level order traversal .
void levelOrder(BSTNode* root){
	BSTNode* curr;
	std::queue<BSTNode*>q;
	q.push(root);
	while(!q.empty()){
		curr = q.front();
		cout << curr->data << " ";
		q.pop();
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
}

//To delete the tree completely using post order technique.
void deleteTree(BSTNode* root){
	if(!root) return ;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

//Check if a path exists for a perticular sum
bool checkPathSum(BSTNode* root, int sum){
	if(root == NULL) return (sum == 0);
	sum = sum-root->data;
	if((root->left && root->right) || (!root->left && root->right))
		return checkPathSum(root->left, sum) || checkPathSum(root->right, sum);
	else if(root->left) return checkPathSum(root->left, sum);
	else return checkPathSum(root->right, sum);
}

//Find least common ancestor of two given nodes
BSTNode* LCA(BSTNode* root, BSTNode* nodeA, BSTNode* nodeB){
	if((nodeA->data > root->data && nodeB->data < root->data) || (nodeA->data < root->data && nodeB->data > root->data))
		return root;
	else if(root->data > nodeA->data) return LCA(root->left, nodeA, nodeB);
	else return LCA(root->right, nodeA, nodeB);
}
int main(){
	BSTNode* root = new BSTNode();
	BSTInit(root, 5);
	insertNode(root, 3);
	insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 8);
	insertNode(root, 7);
	insertNode(root, 9);
//	cout << LCA(root, searchTree(root, 2), searchTree(root, 4))->data;
}
