import sys
from collections import Counter

n = int(sys.stdin.readline().strip())
titles = [sys.stdin.readline().strip() for _ in range(n)]
counts = Counter(titles)
max_count = max(counts.values())
best_title = min(title for title, c in counts.items() if c == max_count)
print(best_title)
