from collections import deque
N, K = map(int,input().split())
G={}
for i in range(1, N+1):
    G[i] = dict()
for i in range(K):
    a,b,weight=map(int,input().split())
    G[a][b] = weight
    G[b][a] = weight
    
        
Start, finish = map(int,input().split())
Q = deque()
S={}
S[Start] = 0
Q.append(Start)
while Q:
    v=Q.popleft()
    for u in G[v]:
        if(u not in S or S[v]+G[v][u]<S[u]):
            S[u]=S[v]+G[v][u]
            Q.append(u)
if finish in S:
    print(S[finish])
else:
    print(-1)
