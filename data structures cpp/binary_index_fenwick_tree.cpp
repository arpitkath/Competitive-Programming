#include<iostream>
#include<cstdio>

using namespace std;

//To read cummulative frequency till index id , i.e arr[0 .. id]
int get(int tree[], int id){
	int sum = 0;
	id++;
	while(id > 0){
		sum += tree[id];
		id -= (id & (-id));
	}
	return sum;
}

//Overloaded function to get sum of arr[l .. r]
int get(int tree[], int l, int r){
	return get(tree, r) - get(tree, l-1);
}

//To add some value to any index id
void update(int tree[], int sz, int id, int val){
	id++;
	while(id <= sz){
		tree[id] +=val;
		id += (id & (-id));
	}
}

//To create a BIT using a frequency array.
int* createBit(int arr[], int sz){
	int *tree = new int[sz+1];
	for(int i = 0; i <=sz; i++) tree[i] = 0;
	for(int i = 0; i < sz; i++) update(tree, sz, i, arr[i]);
	return tree;
}

//To update a given range with same value 
void updateRange(int tree[], int sz, int l, int r, int val){
	update(tree, sz, l, val);
	update(tree, sz, r+1, -val);
}

int main(){
	int f[] = {3, 4, 5, 6, 7, 8, 9, 2, 1, 1, 3, 2 };
	int n = sizeof(f)/sizeof(f[0]);
	int *tree = createBit(f, n);
	cout<<get(tree,0)<<endl;
	//update(tree, n, 5, 3);
	//cout<<get(tree, 5)<<endl;
	//updateRange(tree,n, 0, 4, 5);
	//cout<<get(tree, 1,5);
}
