"""The alternate method is using longest_common_subsequence() between this array and sorted(this) array."""

def longest_increasing_subsequence_dp(l):
	ans=[1]*len(l)
	for i in range(len(l)):
		for j in range(i,len(l)):
			if l[j]<l[i] and ans[i]<ans[j]+1:
				ans[i]=ans[j]+1
return max(ans)
