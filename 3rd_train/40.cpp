#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  
  
  map<int,set<int>> m;
  
  int con = -1;
  
  queue<int> p;
  bool visited[4000] = {0};
  int v, curv;
  
  for (int i = 0; i < K; i++)
  {
    int k;
    int a, b;
    cin >> k;
    
    set<int> mt[4000];
    set<int> curmv;
    
    for (int j = 0; j < k; j++)
    {
      cin >> a >> b;
      a--; b--;
      mt[a].insert(b);
      mt[b].insert(a);
      curmv.insert(a);
      curmv.insert(b);
      visited[a] = 0;
      visited[b] = 0;
    }
    
    while (!curmv.empty())
    {
      v = *(curmv.begin());  
      p.push(v);
      visited[v] = true; 
      curmv.erase(v);
      m[con].insert(v);
      m[v].insert(con);
      while(!p.empty())
      {
        curv = p.front();
        p.pop();
        for (auto it = (mt[curv]).begin(); it != (mt[curv]).end(); it++)
        {
            if (!visited[*it])
            {
              visited[*it] = true;
              curmv.erase(*it);
              p.push(*it);
              m[con].insert(*it);
              m[*it].insert(con);
            }
        }
      }
      con--;
    }
  } 
  
  int* price = new int[N  - con];
  int *adpt = price - con;
  vector<set<int>> squeue;
  
  
  for (int i = 0; i < N - con; i ++)
    price[i] = 1000000000;
  
  adpt[0] = 0;
  int h = 0, maxh = 0;
  
  squeue.push_back({0}); 
  
  while(h <= maxh)
  {
    while(!squeue[h].empty())
    {
      curv = *(squeue[h].begin());
      if (curv >= 0)
      {
        if (maxh < h + 1)
        {
          maxh ++;
          squeue.push_back({});
        }
        for (auto it = (m[curv]).begin(); it != (m[curv]).end(); it++)
        {
          if (adpt[*it] > adpt[curv] + 1)
          {
            adpt[*it] = adpt[curv] + 1;
            squeue[h + 1].insert(*it);
          }
        }
      }  
      else
      {
        for (auto it = (m[curv]).begin(); it != (m[curv]).end(); it++)
        {
          if (adpt[*it] > adpt[curv])
          {
            adpt[*it] = adpt[curv];
            squeue[h].insert(*it);
          }
        }
      }
      squeue[h].erase(curv);
    }
    h++;
  }
  
  
  if (adpt[N-1] == 1000000000)
    cout << -1;
  else
    cout << adpt[N-1];
}
