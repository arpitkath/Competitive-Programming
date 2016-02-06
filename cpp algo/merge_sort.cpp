#include <iostream>
using namespace std;

void merge(int a[], int b[], int n, int m, int c[]){
	int i = 0, j = 0, k = 0;
	while(i != n && j != m){
		if(a[i] > b[j]) c[k++] = b[j++];
		else c[k++] = a[i++];
	}
	while(i != n) c[k++] = a[i++];
	while(j != m) c[k++] = b[j++];
}

void mergeSort(int arr[], int sz){
	if(sz > 1){
		int mid = sz/2;
		int n = mid, m = mid;
		if(sz%2 != 0) m++;
		int a[n], b[m], i;
		for(int i = 0; i < n; i++) a[i] = arr[i];
		for(int j = 0; j < m; j++) b[j] = arr[n + j];
		mergeSort(a, n);
		mergeSort(b, m);
		merge(a, b, n, m, arr);
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	mergeSort(arr,5);
}
