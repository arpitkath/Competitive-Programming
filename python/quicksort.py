'''The partition function to partition the subarray into two halves,first half having elements lower than some piviot element and rigth half elements greater than it.
   It returns the partitioning point.'''
def partition(arr,first,last):
    mid=first+(last-first)/2
    piviot=arr[mid]
    arr[first],arr[mid]=arr[mid],arr[first]
    left,right=first+1,last
    while left<=right:
        while left<=right and arr[left]<=piviot:
            left=left+1
        while left<=right and arr[right]>=piviot:
            right=right-1
        if left<right:
            arr[left],arr[right]=arr[right],arr[left]
    arr[left-1],arr[first]=arr[first],arr[left-1]
    return left-1
'''It is the function whic divides the array into smaller sub arrays'''
def qsort(arr,left,right):
    if left<=right:
        split=partition(arr,left,right)
        qsort(arr,left,split-1)
        qsort(arr,split+1,right)
'''It is a quick-sort helper function'''     
def quicksort(arr):
    qsort(arr,0,len(arr)-1)
    return arr
'''To test the sorting function'''
print quicksort([1,7,5,3,9,5])