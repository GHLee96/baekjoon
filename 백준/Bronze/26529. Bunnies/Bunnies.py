T = int(input())

dp = [0] * (50)
dp[0] = 1
dp[1] = 1

for i in range(T):
    n = int(input())
    
    for j in range(2, n + 1):
        dp[j] = dp[j - 2] + dp[j - 1]
    
    print(dp[n])
    