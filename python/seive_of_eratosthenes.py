"""
	GET ALL PRIME NUMBERS TILL "N"
    -For all numbers m: 2 .. √n, if m is unmarked:
        add m to primes list;
        mark all it's multiples, starting from square, lesser or equal than n (k * m ≤ n, k ≥ m);
    -otherwise, if m is marked, then it is a composite number;
    -check all numbers in range √n .. n. All found unmarked numbers are primes, add them to list.
"""
from math import sqrt
def seive_of_eratosthenes(n):
	primes=[]
	temp=[0]*(n+1)
	for i in range(2,int(sqrt(n))+1):
		if temp[i]==0:
			primes.append(i)
			for j in range(i**2,n+1):
				if j%i==0 and temp[j]==0:
					temp[j]=1
	for i in range(int(sqrt(n)),n+1):
		if temp[i]==0:
			primes.append(i)
	return primes
#working till 10**5 in 0.85s
			
			
			