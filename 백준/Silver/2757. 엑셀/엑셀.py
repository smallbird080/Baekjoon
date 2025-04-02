while True:
    s = input()
    s = s[1:]
    r, c = map(int,s.split('C'))
    if r == 0 and c ==0:
        break
    alphabet = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    column = []
    while c > 0:
        c -= 1
        idx = c % 26
        c = c // 26 
        column.insert(0, alphabet[idx])
    ans =''.join(column)
    ans += str(r)
    print(ans)