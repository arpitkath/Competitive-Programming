#include <iostream>
using namespace std;

int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int sz = 9;

//linear search
int lSearch(int num){
    for(int i = 0; i < sz; i++)
            if(arr[i] == num) return i;
    return -1;
}

//Binary search
int bSearch(int num){
    int start  = 0, end = sz - 1;
    while(end >= start){
              int mid = start + (end - start) / 2;
              if(num == arr[mid]) return mid;
              else if(num < arr[mid]) end = mid - 1;
              else start = mid + 1;
    }
    return -1;
}

int main() {
	for(int i = 0; i < sz; i++) cout<<bSearch(i+1)<<" ";
	return 0;
}
