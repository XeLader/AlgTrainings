#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
  int N, M, K;
  cin >> N >> M;
  
  int l, r;
  set<int> *map = new set<int>[N];
  int *a = new int[M];
  int *b = new int[M];
  for (int i = 0; i < M; i ++)
  {
    cin >> l >> r;
    l--; r--;
    map[l].insert(r);
    map[r].insert(l);
    a[i] = (l < r) ? l : r;
    b[i] = (l < r) ? r : l;
  }
  
  queue<int> p;
  
  cin >> K;
  
  int*** s = new int**[K];
  //int* e = new int[M]{0};
  int e[20000] = {0};
  for (int i = 0; i < K; i++)
  {
    s[i] = new int*[N];
    for (int j = 0; j < N; j++)
    {
      s[i][j] = new int[2];
      s[i][j][0] = 1000000000;
      s[i][j][1] = 1000000000;
    }
  }
  
  
  int v, curv;
  for (int i = 0; i < K; i++)
  {
  
    bool *inQueue = new bool[N]{0};
    cin >> v;
    v--;
    
    p.push(v);
    inQueue[v] = true;
    
    s[i][v][0] = 0;
    
    while(!p.empty())
    {
      curv = p.front();
      p.pop();
      inQueue[curv] = false;
      
      for (auto it = (map[curv]).begin(); it != (map[curv]).end(); it++)
      {
        if (s[i][*it][0] > s[i][curv][1] + 2)
        {
          s[i][*it][0] = s[i][curv][1] + 2;
          if (!inQueue[*it])
          {
            inQueue[*it] = true;
            p.push(*it);
          }
        }
        
        if (s[i][*it][1] > s[i][curv][0] + 2)
        {
          s[i][*it][1] = s[i][curv][0] + 2;
          if (!inQueue[*it])
          {
            inQueue[*it] = true;
            p.push(*it);
          }
        }
      }
    }
    
    for (int j = 0; j < M; j++)
    {
      int mini = s[i][a[j]][0];
      if (mini > s[i][a[j]][1]) mini = s[i][a[j]][1]; 
      if (mini > s[i][b[j]][0]) mini = s[i][b[j]][0];
      if (mini > s[i][b[j]][1]) mini = s[i][b[j]][1];
      
      if (e[j] < mini + 1)
        e[j] = mini + 1; 
    }
    
    delete[] inQueue;
  }
  
  int min = 1000000000;
  
  for (int i = 1; i < K; i ++)
  {
    for (int j = 0; j<N; j++)
    {
      if (s[0][j][0] < s[i][j][0])
        s[0][j][0] = s[i][j][0];
      if (s[0][j][1] < s[i][j][1])
        s[0][j][1] = s[i][j][1];
    }
  }
  
  for (int i = 0; i < N; i ++)
  {
    if(min > s[0][i][0]) min = s[0][i][0];
    if(min > s[0][i][1]) min = s[0][i][1];
  }
          
  for (int i = 0; i < M; i ++)
      if (min > e[i])
        min = e[i];
  
  if (min >= 1000000000)
    cout << -1;
  else
    cout << min/2.0;
  
}
