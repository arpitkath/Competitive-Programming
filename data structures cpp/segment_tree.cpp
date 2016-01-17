/*This segment tree for addition includes:
-building the tree
-getting sum from A[0 .. r-1] or A[l .. r]
-updating a value in array
*/
#include<iostream>

using namespace std;

//To get middle element in a range.
int getMid(int a, int b){
	return a + ((b - a)>>1);
}

//Auxilary function to build a segment tree from a array
void build(int node, int start, int end, int arr[], int tree[]){
	if(start == end) tree[node] = arr[start];
	else{
		int mid = getMid(start, end);
		build((node<<1) , start, mid, arr, tree);
		build((node<<1) + 1, mid + 1, end, arr, tree);
		tree[node] = tree[(node<<1) ] + tree[(node<<1) + 1]; // '+' can be replaced with any binary operator as desired.
	}
}

//Build the tree.
void build(int arr[], int tree[], int sz){
	build(1, 0, sz-1, arr, tree);
}

//Auxilary function -get
int get(int node, int start, int end, int l, int r, int tree[]){
	if(l > end || r < start) return 0;
	else if(l <= start && end <= r) return tree[node];
	else{
		int mid = getMid(start, end);
		return get((node << 1) , start, mid, l, r, tree) + get((node << 1) + 1, mid + 1, end, l, r, tree);
	}
}

//To get sum of elements from A[l .. r]
int get(int tree[], int sz, int l, int r){
	return get(1, 0, sz - 1, l, r, tree);
}

//Auxilary function to Update an index-adding
void update(int node, int tree[], int start, int end, int idx, int val){
	if(start == end) tree[node] += val;
	else{
		int mid = getMid(start, end);
		if(start <= idx && mid >= idx)
			update((node<<1), tree, start, mid, idx, val);
		else
			update((node<<1)+1, tree, mid + 1, end, idx, val);
		tree[node] = tree[node<<1] + tree[(node<<1)+1];
	}
}

//To update a value in the tree-addition
void update(int tree[], int arr[], int sz, int idx, int val){
	arr[idx] += val;
	update(1, tree, 0, sz-1, idx, val);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int sz = 5;
	int tree[2*sz]={0};
	build(arr,tree,sz);
	cout<<get(tree, sz, 2,4)<<endl;
	//for(int i = 1; i < 2*sz-1; i++) cout<<tree[i]<<endl;
	//update(tree, arr, sz, 3, 5);
	//cout<<get(tree,sz,4,4)<<endl;
	//cout<<"--------"<<endl;
	//for(int i = 1; i < 2*sz-1; i++) cout<<tree[i]<<endl;
}
