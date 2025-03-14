n = int(input())
st = input()
numS = st.count('s')
numT = st.count('t')
while numS != numT:
    if st[0] == 's':
        st = st[1:]
        numS -= 1
    elif st[0] == 't':
        st = st[1:]
        numT -= 1
print(st)