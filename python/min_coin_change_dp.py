#Here "n" is change that has to be made and "s" is list containing denominations
from fractions import gcd
def min_coin_change_dp(n,s):
    s=map(int,s.split())
    s.sort()
    #check condition if change can be made from given denominations
    #if yes,then continue else return 0
    g=s[0]
    for i in range(1,len(s)):
        g=gcd(g,s[i])
    if n%g!=0:
        return 0
    maxm=999999999
    dp=[maxm for i in xrange(n+1)]
    dp[0]=0
    for i in range(1,n+1):
        for j in range(len(s)):
            if s[j]<=n:
                sub_res=dp[i-s[j]]
                if sub_res!=maxm and sub_res+1<dp[i]:
                    dp[i]=sub_res+1
    return dp[-1]