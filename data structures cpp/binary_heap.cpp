/*This includes the following functions:
-accesing  parent,left child,right child
-getting maximum element
-printing heap
-heapify
-delete maximum
-insert into heap
-resize the heap
-Build heap from a given array
-heap sort
*/

#include<iostream>
#include<cstdlib>
using std::cout;

//Let it be a max heap.
struct Heap{
	int *arr;
	int capacity;
	int count;
};

//To create a new heap.
Heap* createHeap(int capacity){
	Heap* heap = new Heap();
	heap->capacity = capacity;
	heap->count = 0;
	heap->arr = (int* )malloc(sizeof(int)*heap->capacity);
	return heap;
}

//Parent of a node
int parent(Heap* heap, int i){
	if(i <= 0 || i >= heap->count) return -1;
	else return (i-1) >> 1;
}

//Left child of a node
int leftChild(Heap* heap, int i){
	int left = (i << 1) + 1;
	if(left >= heap->count) return -1;
	else return (i << 1) + 1;
}

//Right child of node
int rightChild(Heap* heap, int i){
	int right = (i << 1) + 2;
	if(right >= heap->count) return -1;
	else return (i << 1) + 2;
}

//Getting maximum element
int getMax(Heap* heap, int i){
	if(heap->count == 0) return -1;
	else return heap->arr[0];
}

//Printing elements of heap
void printHeap(Heap* heap){
	for(int i = 0; i < heap->count; i++) cout << heap->arr[i] <<" ";
	cout << "\n";
}
//Perform heapify !
void heapify(Heap* heap, int i){
	int l, r, max, temp;
	l = leftChild(heap, i);
	r = rightChild(heap, i);
	if(l != -1 && (heap->arr[l] > heap->arr[i])) max = l;
	else max = i;
	if(r != -1 && (heap->arr[r] > heap->arr[max])) max = r;
	if(max != i){
		//swap arr[i] with arr[max]
		temp = heap->arr[i];
		heap->arr[i] = heap->arr[max];
		heap->arr[max] = temp;
	}
	else return;
	heapify(heap, max);
}

//To delete maximum element from heap and return it.
int deleteMax(Heap* heap){
	if(heap->count == 0) return -1;
	int data = heap->arr[0];
	heap->arr[0] = heap->arr[heap->count - 1];
	heap->count--;
	heapify(heap, 0);
	return data;
}

//To resize the heap to double its capacity
void resizeHeap(Heap* heap){
	int* prev = heap->arr;
	heap->arr = (int* )malloc(sizeof(int)*heap->capacity*2);
	for(int i = 0; i < heap->capacity; i++) heap->arr[i] = prev[i];
	heap->capacity = heap->capacity*2;
	delete prev;
}

//To insert element into heap.
void insert(Heap* heap, int data){
	if(heap->count == heap->capacity) resizeHeap(heap);
	heap->count++;
	int i = heap->count -1;
	while((i > 0) && (data > heap->arr[(i-1)>>1])){
		heap->arr[i] = heap->arr[(i-1)>>1];
		i = (i-1) >> 1;
	}
	heap->arr[i] = data;
}

//Build heap from a given array of size sz.
void buildHeap(Heap* heap, int arr[], int sz){
	while(sz > heap->capacity) resizeHeap(heap);
	for(int i = 0; i < sz; i++) heap->arr[i] = arr[i];
	heap->count = sz;
	for(int i = (sz-2)>>1; i >= 0; i--) heapify(heap, i);
}

//Heap sort.
void heapSort(int arr[], int n){
	Heap* heap = createHeap(n);
	int temp;
	buildHeap(heap, arr, n);
	int sz = heap->count;
	for(int i = n-1; i > 0; i--){
		temp = heap->arr[0];
		heap->arr[0] = heap->arr[heap->count - 1];
		heap->arr[heap->count-1] = temp;
		heap->count--;
		heapify(heap, 0);
	}
	heap->count = sz;
	for(int i=0;i<7;i++) arr[i] = heap->arr[i];
}

int main(){
	Heap* heap = createHeap(3);
	insert(heap, 5);
	insert(heap, 6);
	insert(heap, 9);
	insert(heap, 8);
	insert(heap, 53);
	insert(heap,7);
	insert(heap,40);
	printHeap(heap);
	int arr[] = {5,6,9,8,53,7,40};
	heapSort(arr,7);
	for(int i=0;i<7;i++)cout<<arr[i]<<" ";
	return 0;
}
