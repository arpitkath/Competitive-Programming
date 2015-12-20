"""This algorithm gives floor of square root of n."""
def sqrt_binary_search(n): #if n>1
	if n==0 or n==1:
		return n
	else:
		low,high=1,n/2
		ans=0#used when n is not perfect square
		while low<=high:
			mid=low+(high-low)/2
			if mid**2==n:
				return mid
			if mid**2<n:
				"""Since we need floor,we update ans when mid** is smaller than n"""
				low=mid+1
				ans=mid
			else:
				high=mid-1
		return ans