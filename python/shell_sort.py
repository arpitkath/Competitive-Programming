def shell_sort(l):
    n,h = len(l),1
    while h < (n/3):
        h=int((3*h)+1) # 1,4,13,40,121,364-increment sequence.
    while h >= 1:
        # h-sort the array.
        for i in range(h,n):
            j=int(i)
            while j>=h and (l[j]<l[j-h]):
                l[j],l[j-h]=l[j-h],l[j]
                j-=h
        h//=3
    return l
print (shell_sort([3,5,8,5,7,2,55,98,5,7,59]))