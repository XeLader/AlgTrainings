#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  unsigned int N, M;
  int **map, **step;
  queue <pair<unsigned int, unsigned int>> squeue;
  
  cin >> N >> M;
  
  map = new int*[N];
  step = new int*[N];
  for (unsigned int i = 0; i <N; i++)
  {
    map[i] = new int[M];
    step[i] = new int[M]{0};
    for (unsigned int j = 0; j < M; j++)
    {
      cin >> map[i][j];
    }
  }
  
  squeue.push({0, 0});
  step[0][0] = 1;
  while(!squeue.empty())
  {
    //pair<unsigned int, unsigned int> dot = squeue.front;
    
    unsigned int x = squeue.front().first / M, y = squeue.front().first % M;
    unsigned int xd = squeue.front().second / M, yd = squeue.front().second % M;
    if (xd == x)
    { 
      unsigned int xnew = x;
      if (x > 0)
      {
        while (xnew > 0)
        {
          if (map[xnew-1][y] == 2)
          {
            cout << step[x][y];
            return 0;
          } 
          else if (map[xnew-1][y] == 0)
            xnew--;
          else
            break;
        }
        if (step[xnew][y] == 0)
        {
          step[xnew][y] = step[x][y] + 1;
          squeue.push({xnew * M + y, x*M + y});
        }
      }
      if (x < N - 1)
      {
        xnew = x;
        while (xnew < (N- 1))
        {
          if (map[xnew+1][y] == 2)
          {
            cout << step[x][y];
            return 0;
          } 
          else if (map[xnew+1][y] != 1)
            xnew++;
          else
            break;
        }
        if (step[xnew][y] == 0)
        {
          step[xnew][y] = step[x][y] + 1;
          squeue.push({xnew * M + y, x*M + y});
        }
      }
    }
    if (yd == y)
    { 
      unsigned int ynew = y;
      if (y > 0)
      {
        while (ynew > 0)
        {
          if (map[x][ynew - 1] == 2)
          {
            cout << step[x][y];
            return 0;
          } 
          else if (map[x][ynew - 1] == 0)
            ynew--;
          else
            break;
        }
        if (step[x][ynew] == 0)
        {
          step[x][ynew] = step[x][y] + 1;
          squeue.push({x * M + ynew, x*M + y});
        }
      }
      if (y < M - 1)
      {
        ynew = y;
        while (ynew < (M - 1))
        {
          if (map[x][ynew + 1] == 2)
          {
            cout << step[x][y];
            return 0;
          } 
          else if (map[x][ynew + 1] != 1)
            ynew++;
          else
            break;
        }
        if (step[x][ynew] == 0)
        {
          step[x][ynew] = step[x][y] + 1;
          squeue.push({x * M + ynew, x*M + y});
        }
      }
    }
    squeue.pop();
  }
}
