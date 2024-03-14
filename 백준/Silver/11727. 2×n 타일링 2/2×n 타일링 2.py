def GODSungYun(n):
    # a(n) = a(n-1) + 2a(n-2)
    if (n==1):
        return 1
    result = 1
    a1,a2 = 0,1
    for i in range(n):
        result = 2*a1+a2
        a1 = a2
        a2 = result
    return result

n = int(input())
print(GODSungYun(n)%10007)