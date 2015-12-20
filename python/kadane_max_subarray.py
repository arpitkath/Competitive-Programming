""" the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array of numbers which has the largest sum. For example, for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray with the largest sum is 4, −1, 2, 1, with sum 6."""
def kadane_max_subarray(s):
	maximum=-1
	sum=0
	flag=1 # flag will be 1 if all elements in array are negitive.
	for i in s:
		if i>=0:
			flag=-1
		sum+=i
		if sum<0:
			sum=0
		if sum>maximum:
			maximum=sum
	if flag==-1:
		return maximum
	else:
		return max(s) #when all elements are negitive,return least negitive.
