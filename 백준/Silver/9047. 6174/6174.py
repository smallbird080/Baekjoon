t = int(input())
for _ in range(t):
    cnt = 0
    num = input().zfill(4)
    while num != '6174':
        smallest = int(''.join(sorted(num)))
        largest = int(''.join(sorted(num, reverse=True)))
        result = largest - smallest
        num = str(result).zfill(4)
        cnt += 1
    print(cnt)