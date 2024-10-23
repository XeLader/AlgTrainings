N, M = map(int, input().split())

dp = [0]*N*M

dp[0] = 1
i = 0 
j = 0
while (i < M and j < N):
    x = i
    y = j
    while(x>=0 and y < N):
        if (y + 2 < N):
            if (x > 0):
                dp[(y+2)*M + x-1] += dp[y*M + x]
            if (x+1 < M):
                dp[(y+2)*M + x+1] += dp[y*M + x]
        if (x + 2 < M):
            if (y > 0):
                dp[(y - 1)*M + x + 2] += dp[y*M + x]
            if (y+1 < N):
                dp[(y+1)*M + x + 2] += dp[y*M + x]
        x -= 1
        y += 1
    if (i < M - 1):
        i += 1
    else:
        j += 1
print(dp[N*M-1])
