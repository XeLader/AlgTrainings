#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "queue"

using namespace std;

struct rover
{
  int n;
  int road;
  int time;
};

bool comp(rover a1, rover a2)
{
  return(a1.time < a2.time);
}

int main()
{
  int N, a, b, *order;
  bool main[4] = {0};
  
  rover *list;
  cin >> N >> a >> b;
  main[a%4] = true;
  main[b%4] = true;
  list = (rover*)calloc(N, sizeof(rover));
  order = (int *)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
  {
    cin >> list[i].road >> list[i].time;
    list[i].n = i;
  }
  sort(list, list+N, comp);
  
  queue<rover> road[4];
  bool goaway[4];
  int passed = 0, getto = 0, time = 0;
  while(passed < N)
  {
    time++;
    while (getto < N)
    {
      if(list[getto].time <= time)
      {
        road[list[getto].road % 4].push(list[getto]);
        getto++;
      }
      else break;
    }
    for (int i = 4; i < 8; i ++)
    {
      goaway[i%4] = false;
      if (!road[i % 4].empty())
      {
        if (main[i%4])
        {
          if (!main[(i-1) % 4] or road[(i-1) % 4].empty())
          {
            goaway[i%4] = true;
          }
        }
        else if (road[(i-1) % 4].empty() and (!main[(i+1) % 4] or road[(i+1) % 4].empty()))
        {
          goaway[i%4] = true;
        }
      }
    }
    for (int i = 4; i < 8; i ++)
      if (goaway[i%4])
      {
        passed++;
        order[(road[i%4].front()).n] = time;
        road[i%4].pop();
      }
  }
  
  for (int i = 0; i < N; i ++)
    cout << order[i] << '\n';
  
}
