def modify_letter(s):
    if 'A' in s:
        for ch in ['B', 'C', 'D', 'F']:
            s = s.replace(ch, 'A')
    elif 'B' in s:
        for ch in ['C', 'D', 'F']:
            s = s.replace(ch, 'B')
    elif 'C' in s:
        for ch in ['D', 'F']:
            s = s.replace(ch, 'C')
    else:
        s = ''.join(['A' for _ in s])
    return s


s = input()

print(modify_letter(s))