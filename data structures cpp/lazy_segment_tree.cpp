/*This segment tree with "lazy propagation" for addition includes:
-building the tree
-getting sum from A[0 .. r-1] or A[l .. r]
-updating a value in array
-updating a range lazily
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
int get(int node, int start, int end, int l, int r, int tree[], int lazy[]){
	if(l > end || r < start || end < start) return 0;
	if(lazy[node] != 0){
		tree[node] += (end - start +1)*lazy[node];
		if(start != end){
			lazy[(node<<1)] += lazy[node];
			lazy[(node<<1) + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(l <= start && end <= r) return tree[node];
	else{
		int mid = getMid(start, end);
		return get((node << 1) , start, mid, l, r, tree,lazy) + get((node << 1) + 1, mid + 1, end, l, r, tree,lazy);
	}
}

//To get sum of elements from A[l .. r]
int get(int tree[], int lazy[], int sz, int l, int r){
	return get(1, 0, sz - 1, l, r, tree, lazy);
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

//Utility function to update a range
void updateRange(int node, int tree[], int lazy[], int start, int end, int l, int r, int val){
	if(lazy[node] != 0){
		tree[node] = (end - start + 1) * val;
		if(start != end){
			lazy[(node<<1)] += lazy[node];
			lazy[(node<<1)+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l) return ;
	if(start >= l && end <= r){
		tree[node] += (end - start + 1)*val;
		if(start != end){
			lazy[(node<<1)] += val;
			lazy[(node<<1)+1] += val;
		}
		return;
	}
	int mid = getMid(start, end);
	updateRange((node<<1), tree, lazy, start, mid, l, r, val);
	updateRange((node<<1)+1, tree, lazy, mid + 1, end, l, r, val);
	tree[node] = tree[node<<1] + tree[(node<<1) + 1];
}

//To update a range lazily
void updateRange(int tree[], int lazy[], int sz, int l, int r, int val){
	updateRange(1, tree, lazy, 0, sz-1, l, r, val);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int sz = 5;
	int tree[2*sz-1] = {0};
	int lazy[2*sz-1] = {0};
	build(arr,tree,sz);
	cout<<get(tree,lazy, sz, 2,4)<<endl;
	//for(int i = 1; i < 2*sz-1; i++) cout<<tree[i]<<endl;
	updateRange(tree,lazy, sz, 2, 4,5);
	cout<<get(tree,lazy,sz,2,4)<<endl;
	//cout<<"--------"<<endl;
	//for(int i = 1; i < 2*sz-1; i++) cout<<lazy[i]<<endl;
}
