revCount, count = 0, 0
N = int(input())

for i in range(1, N+1):
  count += i * (N - i + 1)
  revCount += i // 2
  count += revCount
print(count)
