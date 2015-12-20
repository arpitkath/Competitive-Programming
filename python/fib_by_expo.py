def fib_by_expo(n):
    def mult(x,y):
        if ( len(y) == 2 ):
            a = x[0]*y[0]+x[1]*y[1]
            b = x[2]*y[0]+x[3]*y[1]
            return [a,b]
        a = x[0]*y[0] + x[1]*y[2]
        b = x[0]*y[1] + x[1]*y[3]
        c = x[2]*y[0] + x[3]*y[2]
        d = x[2]*y[1] + x[3]*y[3]
        return [a,b,c,d]
    def matrix_power( x, n ):
        if ( n == 1 ):
            return x
        if ( n%2 == 0 ):
            return matrix_power( mult(x, x), n//2 )
        return mult(x, matrix_power( mult(x, x), n//2 ) )
    A = [1,1,1,0]
    v = [1,0]
    return mult(matrix_power(A,n-2),v)[0]#change n-2-->n-1 if fib(1)=1,we have assumed fib(1)=0 here
print fib_by_expo(10)