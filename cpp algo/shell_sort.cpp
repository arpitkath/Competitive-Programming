#include <iostream>
#include <cstdio>

using namespace std;

void hSort(int arr[], int sz, int h){
	for(int i = 0; i < sz-h+1; i += h){
		int j = i;
		while((j > 0) && (arr[j-h] > arr[j])){
			int temp = arr[j];
			arr[j] = arr[j-h];
			arr[j-h] = temp;
			j -= h;
		}
	}
}

void shellSort(int arr[], int sz){
	int h = 1;
	while(h < sz) h = 3*h + 1;
	while(h > 0){
		hSort(arr, sz, h);
		h = h/3;
	}

}

int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr)/sizeof(arr[0]);
	shellSort(arr,sz);
	for(int i = 0; i < sz; i++) cout<<arr[i]<<" ";
	return 0;
}
