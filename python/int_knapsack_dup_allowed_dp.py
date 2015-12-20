"""You have n types of items, where the ith item type has an integer size si and a real value vi. You need to ﬁll a knapsack of total capacity C with a selection of items of maximum value. You can add multiple items of the same type to the knapsack."""
def int_knapsack_dup_allowed_dp(weight,val,c):
    m=[0]*(c+1)
    t=0
    for i in range(1,c+1):
        m[i]=m[i-1]
        for j in range(0,len(w)):
            if i>=weight[j]:
                t=m[i-weight[j]]+val[j]
            if t>m[i]:
                m[i]=t
    return m[-1]
print f([2,3,4],[10,2,2],6)