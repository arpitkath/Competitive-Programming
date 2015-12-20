"""To calculate (a^b)%c """
"""This algo takes O(b) time.So exponentiation by squaring is practically used which takes O(log(b)) time."""
def mod_exp(a,b,c):
	res=1
	for i in range(b): #this step is valid because (a*b)%c = ((a%c)*(b%c))%c
		res*=a
		res%=c
	return res%c
