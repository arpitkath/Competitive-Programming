""" the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array of numbers which has the largest sum. For example, for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; the contiguous subarray with the largest sum is 4, −1, 2, 1, with sum 6."""
def max_subarray_dp(s):
	l=[0]*len(s)
	# l[i]=l[i-1]+s[i] if we extend sum till s[i] else 0
	if s[0]>0:
		maximum=s[0]
	else:
		maximum=0
	for i in range(len(s)):
		if l[i-1]+s[i]>0:
			l[i]=l[i-1]+s[i]
		else:
			l[i]=0
	for i in l:
		if i>maximum:
			maximum=i
	return maximum