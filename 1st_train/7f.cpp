#include <iostream>
#include <set>
#include <array>

using namespace std;

int main()
{
  int n;
  int sd, sm, sy, ed, em, ey;
  set<array<int,3>> events;
  set<array<int,3>>::iterator itr;
  set<int> sovr;
  set<int>::iterator itrS;
  bool add;
  
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> sd >> sm >> sy >> ed >> em >> ey;
    sy = sy*10000 + sm * 100 + sd;
    ey = ey*10000 + em * 100 + ed;
    if ( ey > sy+18*10000)
    {
      if ( ey >= sy+80*10000)
        ey = sy+80*10000 ;
      events.insert({sy + 180000, 1, i+1});
      events.insert({ey, -1, i+1});
    }
  }
  
  if (events.size() == 0)
    cout << "0";
  else if (events.size() == 2)
    cout << (*events.begin())[2];
  else
  {
    for (itr= events.begin(); itr != events.end(); itr++)
      switch ((*itr)[1])
      {
        case 1:
          sovr.insert((*itr)[2]);
          add = true;
          break;
        
        case -1:
          if (add){
            for( itrS = sovr.begin(); itrS != sovr.end(); itrS++)
                cout << *itrS<< ' ';
            cout << '\n';
          }
          add = false;
          sovr.erase((*itr)[2]);
          break;
      }
  }
}



