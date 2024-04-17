import sys 

sys.setrecursionlimit(10**6)
T = int(input())

offset = [1, 2, 3]

def set_dp(max_n, max_m):
    global dp
    
    MOD = 1000000009
    dp[1][1], dp[2][1], dp[3][1] = 1, 1, 1
    
    for i in range(1, max_n + 1):
        for j in range(1, max_m + 1):
            if j == 1 and i > 3:
                dp[i][j] = 0
            elif j > 1:
                dp[i][j] = sum(dp[i-k][j-1] for k in offset if i-k >= 0) % MOD

    return

dp = [[0] * (1000 + 1) for _ in range(1000 + 1)]
set_dp(1000, 1000)

for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    print(dp[N][M])
    