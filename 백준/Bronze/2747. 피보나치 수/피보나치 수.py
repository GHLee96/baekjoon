def fibo(n):
    global dp
    
    if len(dp) <= n:
        dp.append(fibo(n - 2) + fibo(n - 1))
        
    return dp[n]
    
n = int(input())
dp = [0, 1]
print(fibo(n))