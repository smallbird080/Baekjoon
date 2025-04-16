def is_yujinsu(n):
    s = str(n)
    length = len(s)

    for i in range(1, length):  # i = 나눌 지점 (1~length-1)
        left = s[:i]
        right = s[i:]
        prod_left = 1
        prod_right = 1

        for ch in left:
            prod_left *= int(ch)
        for ch in right:
            prod_right *= int(ch)

        if prod_left == prod_right:
            return "YES"
    return "NO"

n = int(input())
print(is_yujinsu(n))