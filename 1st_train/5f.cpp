#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
  int N, M, a, b, minPrice = 10000, minPower, Sum = 0;
  
  multiset<int, greater<int>> Rooms;
  map<int, multiset<int>, greater<int>> AirCond;
  
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    Rooms.emplace(a);
  }
  
  cin >> M;
  
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    AirCond[a].insert(b);
  }
  
  multiset<int, greater<int>>::iterator itr;
  map<int, multiset<int>, greater<int>>::iterator itc;
  
  itr = Rooms.begin();
  
  
  while(itr != Rooms.end())
  {
    itc = AirCond.begin();
    while(itc -> first >= *itr and itc!=AirCond.end())
    {
      
      if (minPrice > *((itc -> second).begin()))
      {
        minPrice = *((itc -> second).begin());
        minPower = itc -> first;
      }
    itc++;
    }
    Sum += minPrice;
    AirCond[minPower].erase(minPrice);
    if (AirCond[minPower].size() == 0)
      AirCond.erase(minPower);
    itr++;
  }
  
  cout << Sum;
}
