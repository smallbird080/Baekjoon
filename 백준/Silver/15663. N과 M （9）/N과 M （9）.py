from itertools import permutations
n,m = map(int,input().split())
nums = [*map(int,input().split())]
result = list(set(permutations(nums,r=m)))
result.sort()
for p in result:
    print(*p)