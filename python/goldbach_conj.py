"""Goldbach's conjecture->It states:Every even integer greater than 2 can be expressed as the sum of two primes.
This is a program to print all the partitions of a even number and number of partitions"""
from math import sqrt
def check_prime(num): # This is a brute force algorithm to calculate if a number is prime or not.
    if num==1 or num==2:
        return True
    for i in range(2,int(sqrt(num))+1):
        if (num % i) == 0:
            return False
    return True
t=int(raw_input())
for i in range(t):
    n=int(raw_input())
    count=0
    l=[]
    n/=2
    for j in range(2,n+1):
        if f(j) and f((2*n)-j):
            count+=1
            l.append(str(j)+"+"+str((2*n)-j))
    print str(2*n)+" has "+str(count)+" representation(s)"
    for j in l:
        print j
