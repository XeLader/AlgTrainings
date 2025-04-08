n = int(input())
a, b = map(int, input().split())
roads = list((list(), list(), list(), list()))
main_roads = [False]*4
main_roads[a % 4] = True
main_roads[b % 4] = True

for i in range(n):
    road, time = map(int, input().split());
    roads[road % 4].append([time, i])

times = list()
for i in range(4):
    roads[i].sort(key=lambda rover: rover[0])
    if roads[i]:
        times.append(roads[i][0][0])

time = min(times)
passed_time = [0]*n

while(not all((not road) for road in roads)):
    current_state = [list()]*4
    passed = [False]*4
    for i in range(4):
        if (roads[i]):
            if (roads[i][0][0] <= time):
                current_state[i] = roads[i][0]
                passed[i] = True

    for i in range(4):
        if(passed[i]):
            if (not main_roads[i]):
                if ( (main_roads[i-1] and current_state[i-1]) or (main_roads[(i+1)%4] and current_state[(i+1) % 4]) or (main_roads[(i+2)%4] and current_state[(i+2) % 4])):
                    passed[i] = False

            if (main_roads[i-1] == main_roads[i] and current_state[i-1]):
                    passed[i] = False
   
    for i in range(4):
        if (passed[i]):
           passed_time[current_state[i][1]] = time
           roads[i].pop(0)
    
    time += 1

for i in passed_time:
    print(i)
