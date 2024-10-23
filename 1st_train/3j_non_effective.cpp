#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main()
{
  int t, d, n, x, y;
  
  pair<int, int> coord(0, 0);
  
  cin >> t >> d >> n;
  
  struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
  
  unordered_set<pair<int,int>, pair_hash> Pos= {coord};
  unordered_set<pair<int,int>, pair_hash> PosTemp;
  
  for (int i = 0; i < n; i ++)
    {
      cin >> coord.first >> coord.second; 
       
        for (x = coord.first - d; x <= coord.first + d; x++)
          for (y = coord.second - (d - abs(x - coord.first)); y <= coord.second + (d - abs(x - coord.first)); y++)
            for (const pair<int,int>& pos : Pos)
              if ((abs (pos.first - x) + abs (pos.second-y))<=t)
              {
                  PosTemp.emplace(make_pair(x, y));
                  break;
              }

        
      Pos.swap(PosTemp);
      PosTemp.clear();
    }
  
  
  cout<<Pos.size()<<'\n';
  for (const pair<int,int>& elem : Pos)
    cout << elem.first<<' '<<elem.second<<'\n';
}
