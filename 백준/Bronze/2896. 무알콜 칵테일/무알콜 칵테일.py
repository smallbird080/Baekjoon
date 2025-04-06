drink = list(map(int, input().split()))
juice = list(map(int, input().split()))
ratio = [d/j for d, j in zip(drink, juice)]
ratio = min(ratio)
for i in range(3):
    if ratio == drink[i] / juice[i]:
        print(0, end=' ')
    else:
        print(drink[i] - juice[i] * ratio, end=' ')