def fibo(n):
    dp = [0] * 1000001
    dp[0] = 0
    dp[1] = 1
    
    if n >= 2:
        for i in range(2, n + 1) : 
            dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007

    return dp[n] 

n = int(input())

print(fibo(n))