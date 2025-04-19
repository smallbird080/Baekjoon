import sys

input = sys.stdin.readline
N, M = map(int, input().split())
correct = list(map(int, input().split()))
correct_idx = set(int(x) - 1 for x in input().split())  
answer = [0] * N
prev = 0                                    
for i in range(N):
    if i in correct_idx:            
        answer[i] = correct[i]
    else:                            
        forbidden = {prev, correct[i]}     
        if i + 1 < N and (i + 1) in correct_idx:
            forbidden.add(correct[i + 1])
        for v in range(1, 6):
            if v not in forbidden:
                answer[i] = v
                break
    prev = answer[i]
print(*answer)
