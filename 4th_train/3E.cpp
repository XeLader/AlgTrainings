#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int N;
vector<array<int, 2>> *roads;
int (*T_V)[2];
int *dist, *changes;
double *time;
bool *visited, *probed;

int bfs(int start)
{  
  int minTime = 1000000000;
  int minTown;
  for (int i = 1; i <= N; i++)
    visited[i] = false;
  
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty())
  {
    int curCity = q.front();
    visited[curCity] = true;
    
    q.pop();
    if (time[curCity] > dist[curCity] * 1.0 / T_V[curCity][1] + T_V[curCity][0] + time[start])
    {
      time[curCity] = dist[curCity] * 1.0 / T_V[curCity][1] + T_V[curCity][0] + time[start];
      changes[curCity] = start;
    } 
    if(minTime > time[curCity] and !probed[curCity])
    {
        minTime = time[curCity];
        minTown = curCity;
    }
    for(size_t i = 0; i < roads[curCity].size(); i++)
    {
      if(visited[roads[curCity][i][0]] == false)
      {
        dist[roads[curCity][i][0]] = dist[curCity] + roads[curCity][i][1];  
        q.push(roads[curCity][i][0]);
      } 
    }
  }
  
  return minTown;
}

int main()
{

  scanf("%d" , &N);
  
  roads = new vector<array<int, 2>>[N+1];
  T_V = new int[N+1][2];
  dist = (int*)calloc(N+1, sizeof(int));
  changes = (int*)calloc(N+1, sizeof(int));
  time = (double*)calloc(N+1, sizeof(double));
  probed  = (bool*)calloc(N+1, sizeof(bool));
  visited = (bool*)calloc(N+1, sizeof(bool));
  
  for (int T, V, i = 1; i <= N; i++)
  {
    scanf("%d %d", &T, &V);
    T_V[i][0] = T;
    T_V[i][1] = V;
    time[i] = 1000000000;
  }
  
  for (int A, B, S, i = 1; i <= N-1; i++)
  {
    scanf("%d %d %d", &A, &B, &S);
    roads[A].push_back({B,S});
    roads[B].push_back({A,S});
  }
  
  dist[1] = 0;
  time[1] = 0;
  probed[1] = true;
  int nextTown = 1;
  for (int i = 0; i < N; i++)
  {
    nextTown = bfs(nextTown); 
    probed[nextTown] = true;
  }
  
  for (int i = 1; i <= N; i++)
    if (time[i] > time[nextTown])
      nextTown = i;
    
  printf("%f\n", time[nextTown]);
  
  while (nextTown != 1)
  {
    printf("%d ", nextTown);
    nextTown = changes[nextTown];
  }
  printf("1");
}
