#include <iostream>
#include <cstdio>

using namespace std;

void SelectionSort(int arr[], int sz){
      int i, j, first, temp;
      for (i= sz - 1; i > 0; i--)
     {
           first = 0;                 // initialize to subscript of first element
           for (j=1; j<=i; j++)   // locate smallest between positions 1 and i.
          {
                 if (arr[j] < arr[first])
                 first = j;
          }
         temp = arr[first];   // Swap smallest found with element in position i.
         arr[first] = arr[i];
         arr[i] = temp;
     }
}

int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr)/sizeof(arr[0]);
	SelectionSort(arr, sz);
	for(int i = 0; i < sz; i++) cout<<arr[i]<<" ";
	return 0;
}
