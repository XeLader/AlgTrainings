#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

void rfc(int s);

int *Visited;
set<int> *conList;

int main()
{
  int V, E, s, e;  
  scanf("%d %d", &V, &E);
  conList = new set<int>[V];
  Visited = new int[V]{0};
  for (int i = 0; i < E; i++)
  {
    scanf("%d %d", &s, &e);
    conList[e-1].emplace(s-1);
  }
  
  rfc(0);
  
  for (int i = 0; i < V; i++)
    if (Visited[i])
      printf("%d ", i+1);
}


void rfc(int s)
{
  Visited[s] = 1;
  for(set<int>::iterator itr = conList[s].begin(); itr!=conList[s].end(); itr++)
    if (Visited[*itr]==0) 
      rfc(*itr);
}

