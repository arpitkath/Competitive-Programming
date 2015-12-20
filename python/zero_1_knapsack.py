def zero_1_knapsack(w,v,c):#w-weight,v-value,c-capacity
    m=[[0 for i in range(c+1)] for i in range(len(v))]#column will be capacity,raw will make us choos if we pick up i'th item or not.
    """m[i][j] equal to max value in knapsack of size j with items permitted from 1...i"""
    for i in range(len(w)):
        for j in range(c+1):
            if j<w[i]:
                m[i][j]=m[i-1][j]#if i'th item has weight greater than total capacity.
            else:
                m[i][j]=max(m[i-1][j],(m[i-1][j-w[i]]+v[i]))
    maxm=0
    for i in range(c+1):
        maxm=max(m[len(w)-1][i],maxm)
    return maxm
print zero_1_knapsack([1,3,4,5],[1,4,5,7],7)