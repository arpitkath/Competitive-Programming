"""This is brute force algorithm using bitmasking to find all the subsets of an array and their count which sum's to 'k' having O(2**n) time complexity """
def subset_sum_k(s,k):
    mask=count=0  # Here mask is bitmasking coefficient
    #s=map(int,s.split())
    while mask<(1<<len(s)): #There are 2**(length of set) subsets
        sm=0 #sum of current subset
        temp=[]
        for i in range(len(s)):
            if (mask & (1<<i))>0: #If i'th bit is set,add it to subset
                sm+=s[i]
                temp.append(s[i])
        if sm==k:
            count+=1
            print "{"+",".join(str(i) for i in temp)+"}"
        mask+=1
    print "Total="+str(count)
