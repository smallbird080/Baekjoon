n,m = map(int, input().split())
poke = {}
for i in range(1,n+1):
    name = input().rstrip()
    poke[i] = name
    poke[name] = i

for _ in range(m):
    q = input().rstrip()
    if q.isdigit():
        print(poke[int(q)])
    else:
        print(poke[q])