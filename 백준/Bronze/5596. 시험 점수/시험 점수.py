sum = 0
res = 0
for tc in range (2):
    sum = 0
    a, b, c, d = map(int, input().split())
    sum += a + b + c + d
    if res < sum:
        res = sum
        
print(res)
    