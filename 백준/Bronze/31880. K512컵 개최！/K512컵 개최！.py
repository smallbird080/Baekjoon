n ,m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
sum = 0
for i in range(n):
    sum += A[i]
for i in range(m):
    if B[i] != 0:
        sum *= B[i]
print(sum)
