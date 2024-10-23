#include <iostream>
#include <set>
#include <array>

using namespace std;

int main()
{
  int n, k, a, b;
  set<array<int,3>> events;
  set<array<int,3>>::iterator itr;
  
  set<int> goodseq;
  set<int> nowseq;
  bool HOW;
  int prevtime;
  
  cin >> k;

  for (int j = 0; j < k; j++)
  {
      
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      events.insert({a, -1, i});
      events.insert({b, 1, i});
    }
    HOW = true;
    prevtime = -1;
    if ((*events.begin())[0] == 0 and (*(--events.end()))[0] >= 10000 )
    {
      for (itr= events.begin(); itr != events.end(); itr++)
      {
        if ((*itr)[0] != 0 and nowseq.size() == 0)
        {
          HOW = false;
          break;
        }
        if (nowseq.size() == 1 and (*itr)[0] != prevtime)
          goodseq.insert(*nowseq.begin());
        if ((*itr)[0] != prevtime)
          nowseq.erase((*itr)[2]);
        if ((*itr)[1] == -1)
          nowseq.emplace((*itr)[2]);
        else
          nowseq.erase((*itr)[2]);
        prevtime = (*itr)[0];
      }
    }
    else
      HOW = false; 
     if (HOW and (int)goodseq.size() == n)
       cout<<"Accepted\n";
     else
       cout << "Wrong Answer\n";
    events.clear();
    nowseq.clear();
    goodseq.clear();
  }
}



