"""Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum..
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j"""
def count_inversion(lst):
    return merge_count_inversion(lst)[1]
"""Here we will be using variation of merge sort algorithm to count inversion in array int O(nlog(n)) time"""
"""Brute force can do it in O(n^2)"""
def merge_count_inversion(lst):
    if len(lst) <= 1: #Base Case
        return lst, 0
    middle = int( len(lst) / 2 ) # Spliting list
    left, a = merge_count_inversion(lst[:middle]) #To count inversions in left part of array
    right, b = merge_count_inversion(lst[middle:]) #To count inversions in right part of array
    result, c = merge_count_split_inversion(left, right) # To count inversions in merging parts of sorted left and right subarrays.
    return result, (a + b + c) # Return sorted list as well as total inversion count.
"""Function to count split inversions as well as returning the sorted list"""
def merge_count_split_inversion(left, right):
    result = []
    count = 0
    i, j = 0, 0 # i for indexing left list and j for right
    left_len = len(left)
    while i < left_len and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            count += left_len - i #As the list individualy are sorted , so if right[j]<left[i] then all other elements in right of the left list are greater than right[j] making inversion pairs.
            j += 1
    result += left[i:]
    result += right[j:]
    return result, count  
