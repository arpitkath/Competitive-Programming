# This can be used to find prime factors of a number in log(n) time after pre-computation.
"""
 We will store the smallest prime factors only. If n is composite, then it has such a prime factor, otherwise n is a prime and then the n itself is the smallest prime factor. It is obvious, for any even number n, sp(n)=2. 
"""
maxm=10**5    # maximum upto which smallest prime factors will be saved
pr=[2]*maxm   # smallest primes will be saved here
def modified_seive():
    global pr
    v=[0]*maxm
    for i in range(3,maxm,2):
        if v[i]==0:
            pr[i]=i
            j=i
            while(j*i<maxm):
                if(v[j*i]==0):
                    v[j*i]=1
                    pr[j*i]=i
                j+=2
"""
# To find prime factors in log(n) time.
def prime_factor(n):
    prime=[1]
    while(n>1):
        prime.append(pr[n])
        n/=pr[n]
    return "x".join(str(i) for i in prime)
"""