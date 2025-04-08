#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <vector>
#include <queue>

using namespace std;

bool comp(array<int, 3> it1, array<int, 3> it2)
{
  return it1[1] < it2[1];
}

int main()
{ 
  unsigned int N, d, v, R;
  scanf("%u\n%u %u\n%u", &N, &d, &v, &R);
  vector<vector<array<int, 3>>> timeTable(N);
  d--; v--;
  int *curPos = (int*)calloc(N, sizeof(int));
  int *visitingTime = (int*)calloc(N, sizeof(int));
  queue<int> q;
  q.push(d);
  for (unsigned int f, t, d_t, a_t, i = 0; i < R; i++)
  {
    scanf("%u %u %u %u", &f, &d_t, &t, &a_t);
    timeTable[f-1].push_back({t-1, d_t, a_t});
  }
  
  for (unsigned int i = 0; i < N; i++)
  {
    sort(timeTable[i].begin(), timeTable[i].end(), comp);
    curPos[i] = timeTable[i].size();
    visitingTime[i] = -1;
  }
  
  visitingTime[d] = 0;
  while (!q.empty())
  {
    int curCity = q.front();
    q.pop();
    while(curPos[curCity] > 0)
    {
      if (visitingTime[curCity] <= timeTable[curCity][curPos[curCity] - 1][1])
      {
        if(visitingTime[timeTable[curCity][curPos[curCity] - 1][0]] > timeTable[curCity][curPos[curCity] - 1][2] or 
            visitingTime[timeTable[curCity][curPos[curCity] - 1][0]] == -1)
        {
          visitingTime[timeTable[curCity][curPos[curCity] - 1][0]] = timeTable[curCity][curPos[curCity] - 1][2];
          q.push(timeTable[curCity][curPos[curCity] - 1][0]);
        }
        curPos[curCity]--;
      }
      else break;
    }
  }
  
  printf("%d", visitingTime[v]);
  
}
