sum = 0
for i in range(4):
    sum += int(input())
    
min = int(sum / 60)
sec = int(sum % 60)

print(min)
print(sec)
