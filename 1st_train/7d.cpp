#include <iostream>
#include <set>
#include <array>

using namespace std;

int main()
{
  int n, a, b, higher = 0, fb = 0, sb = 0, secadd = 0;
  set<array<int,3>> events;
  set<array<int,3>>::iterator itr, itr2;
  set<int> cons;
  
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    if (b - a >= 5)
    {
      events.insert({a, -1, i});
      events.insert({b-5, 1, i});
    }
  }
  
  if (events.size() == 0)
    cout << "0 0 5";
  else if (events.size() == 2)
    cout << "1 " << (*events.begin())[0] << ' ' <<(*events.begin())[0] + 10;
  else
  {
    for (itr= events.begin(); itr != events.end(); itr++)
    {
      if ((*itr)[1] == -1)
      {
        cons.insert((*itr)[2]);
        if ((int)cons.size() > higher)
        {
          higher = cons.size();
          fb = (*itr)[0];
          sb = fb + 5;
        }
      }
      secadd = 0;
      itr2 = itr;
      for(itr2++; itr2 != events.end(); itr2++)
      {
        if ((*itr2)[1] == -1 and !cons.contains((*itr2)[2]))
          secadd++;
        if ((*itr2)[0] - 5 >=  (*itr)[0] and (int)cons.size() + secadd > higher)
        {
          higher = cons.size() + secadd ;
          fb = (*itr)[0];
          sb = (*itr2)[0];
        }
        if ((*itr2)[1] == 1 and !cons.contains((*itr2)[2]))
          secadd --;
      }
      if ((*itr)[1] == 1)
        cons.erase((*itr)[2]);
    }
    cout<< higher << ' ' << fb <<  ' '<<sb;
  }
  


}



