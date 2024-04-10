    
def fibo(n):
    global res2, dp
    
    if len(dp) <= n:
        dp.append(fibo(n - 2) + fibo(n - 1))
        
    return dp[n]

dp = [0, 1, 1]
cnt = 0
n = int(input())
fibo(n)
cnt = n - 3 + 1
print(dp[n], cnt)