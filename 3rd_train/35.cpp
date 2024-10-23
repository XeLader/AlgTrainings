#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main()
{
  unsigned int N;
  cin >> N;
  
  vector<set <unsigned int>> needed(N);
  vector<stack <unsigned int>> graph(N);
  stack <unsigned int> order;
  set<unsigned int, std::greater<unsigned int>> available; 
  for ( unsigned int i = 0; i < N; i++)
    available.insert(i);
  
  for ( unsigned int i = 0; i < N; i++)
  {
    unsigned int M;
    cin >> M;
    unsigned int temp;
    for( unsigned int j = 0; j < M; j++)
    {
      cin >> temp;
      available.erase(temp - 1);
      graph[i].push(temp - 1);
      needed[temp -1].insert(i);
    }
  }
  
  for (unsigned int i = 0; i < N; i++)
  {
    unsigned int max = *available.begin();
    order.push(max + 1);
    while(!graph[max].empty())
    {
      needed[graph[max].top()].erase(max);
      if (needed[graph[max].top()].empty())
      {
        available.insert(graph[max].top());
      }
      graph[max].pop();
    }
    available.erase(max);
  }
  
    for (unsigned int i = 0; i < N; i++)
  {
    cout << order.top()<<' ';
    order.pop();
  }
}
