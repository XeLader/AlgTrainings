#include <iostream>
#include <set>
#include <array>
#include <map>

using namespace std;

int main()
{
  int n, m;
  int t, c = 0;
  
  int guests[3];
 
  map<int, int> Counts;
  map<int, int> itr2;
  set<array<int,2>> events;
  set<array<int,2>>::iterator itr;

  
  cin >> m >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> guests[0] >> guests[1] >> guests[2];
    t = 0;
    for (int j = 1; j <= m; j++)
    { 
      t += guests[0];
      events.insert({t, i});
      if (!(j%guests[1]))
        t += guests[2];
    }
  }
  
  for (itr= events.begin(); itr != events.end(); itr++)
  {
    c++;
    Counts[(*itr)[1]] ++;
    if (c == m)
    {
      t = (*itr)[0];
      break;
    }  
  }
  
  cout << t << '\n';
  for (int i = 0; i < n; i++)
    cout << Counts[i]<<' ';
}



