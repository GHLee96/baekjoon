
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, M, R = map(int, input().split())

graph = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
    
for i in range(1, len(graph)):
    graph[i].sort()

def dfs(now):
    global order
    visited[now] = order
    
    for next in graph[now]:
        if not visited[next]:
            order += 1
            dfs(next)
    return

order = 1
dfs(R)

for i in range(1, N + 1):
    print(visited[i])