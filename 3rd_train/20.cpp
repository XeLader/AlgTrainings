#include <iostream>
#include <functional>
#include <set>
#include <map>

using namespace std;

int main()
{
  long unsigned int N, K, P;
  int count = 0;
  cin >> N >> K >> P;
  
  int *queue = new int[P];
  int *nextUse = new int[P];
  
  set<int> onFloor;
  multimap <int, int, greater<int>> next;
  map <int, long unsigned int> lastUse;
  
  for (long unsigned int i = 0; i < P; i++)
    cin >> queue[i];
  
  for (long int i =(long int) P-1; i >= 0; i--)
  {
    if (!lastUse.contains(queue[i]))
      nextUse[i] = P; 
    else
      nextUse[i] = lastUse[queue[i]]; 
    lastUse[queue[i]] = i;  
  }
  
  for (long unsigned int i = 0; i < P; i++)
  {
    if (!onFloor.contains(queue[i]))
    {
      if (onFloor.size() == K)
      {
        onFloor.erase((*next.begin()).second);
        next.erase(next.begin());
      }   
      onFloor.insert(queue[i]);
      next.insert({nextUse[i], queue[i]});
      count ++;
    }
    else
    {
      next.insert({nextUse[i],queue[i]}); 
      next.erase(i);
    }
  }
  cout<<count;
}
