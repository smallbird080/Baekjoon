n = int(input())

for _ in range(n):
    m = int(input())
    clothes = {}
    for _i in range(m):
        item, category = input().split()
        if category in clothes:
            clothes[category] += 1
        else:
            clothes[category] = 1
    
    result = 0;
    for num_clothes in clothes.values():
        result = (result+1) * (num_clothes + 1) - 1
    
    print(result)