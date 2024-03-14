def tiling(n):
    if(n==1):
        return 1
    result = 0
    a1 = 0
    a2 = 1
    for i in range(0,n):
        result = a1+a2
        a1 = a2
        a2 = result
    return result

n = int(input())
print(tiling(n)%10007)