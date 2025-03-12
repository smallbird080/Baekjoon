import itertools

n = int(input())
dices = []
for i in range(4):
    string = input()
    dices.append(set())
    for c in string:
        dices[i].add(c)
for i in range(n):
    target = input()
    res = False
    for sets in itertools.permutations(dices, 4):
        for i in range(len(target)):
            if target[i] not in sets[i]:
                break
        else:
            res = True
            break
    print("YES" if res else "NO")