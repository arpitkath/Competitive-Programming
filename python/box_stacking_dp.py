def box_stacking_dp(n):
    x=[0]*90
    y=[0]*90
    z=[0]*90
    dp=[0]*90
    N=3*n
    #taking input as all combinations of length,width and height of box.
    for i in range(n):
        s=map(int,raw_input().split())
        x[3*i],y[3*i],z[3*i]=s[0],s[1],s[2]
        x[(3*i)+1],y[(3*i)+1],z[(3*i)+1]=s[1],s[2],s[0]
        x[(3*i)+2],y[(3*i)+2],z[(3*i)+2]=s[2],s[0],s[1]
    #sorting combinations of boxes in increasing area
    for i in range(N):
        for j in range(i+1,N):
            if (x[j]<x[i] and y[j]<y[i]) or (x[i]>y[j] and x[j]<y[i]):
                x[i],x[j]=x[j],x[i]
                y[i],y[j]=y[j],y[i]
                z[i],z[j]=z[j],z[i]
    ans=-1
    for i in range(N):
        dp[i]=z[i]
        for j in range(i):
            if (x[j]<x[i] and y[j]<y[i]) or (y[j]<x[i] and x[j]<y[i]):
                dp[i]=max(dp[i],dp[j]+z[i])
        ans=max(ans,dp[i])
    return ans
