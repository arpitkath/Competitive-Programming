# Only works for positive exponents! 
def exp_by_squaring_rec( x, n):
    if ( n == 1 ):
        return x
    if ( n%2 == 0 ):
        return exp_by_squaring_rec( x*x, n//2 )
    return x * exp_by_squaring_rec( x*x, n//2 )

