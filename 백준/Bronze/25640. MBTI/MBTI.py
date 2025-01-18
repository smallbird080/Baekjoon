mbti=input()
n = int(input())
cnt=0
for i in range(n):
    friend=input()
    if mbti==friend:
        cnt += 1

print(cnt)