#include <iostream> 
#include <set>
#include <array>
#include <cmath>

using namespace std; 

int main()
{
  int N, W, L;
  int x1, y1, z1, x2, y2, z2, sq;
  int usedbl = 0 ,totalsq, nowsq = 0, minused;
  
  set<array<int,4>> events;
  set<array<int,4>>::iterator itr;
  
  set<int> UB;
  set<int>::iterator UBTR;
  
  cin >> N >> W >> L;
  
  minused = N + 1;
  totalsq = W*L;
  
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d %d %d %d %d",  &x1, &y1, &z1, &x2, &y2, &z2);
    sq = abs(x1 - x2) * abs (y1-y2);
    events.insert({z1, 1, sq, i});
    events.insert({z2, -1, sq, i});
  }

  for(itr = events.begin(); itr != events.end(); itr++)
  {
    switch ((*itr)[1])
    {
      case 1:
        usedbl ++;
        nowsq += (*itr)[2];
        if (nowsq == totalsq and usedbl < minused)
          minused = usedbl;
        break;
        
      case -1:
        usedbl --;
        nowsq -= (*itr)[2];
        break;
    }
  }
  
  if (minused == N+1)
    cout << "NO";
  else
  {
    cout << "YES\n";
    cout << minused << '\n';
    for(itr = events.begin(); itr != events.end(); itr++)
    {
      switch ((*itr)[1])
      {
        case 1:
          usedbl ++;
          nowsq += (*itr)[2];
          UB.insert((*itr)[3]);
          if (nowsq == totalsq and usedbl == minused)
          {
            for(UBTR = UB.begin(); UBTR != UB.end(); UBTR++)
              cout<<*UBTR + 1<< '\n';
            return 0;
          }
            
          break;
        
        case -1:
          usedbl --;
          nowsq -= (*itr)[2];
          UB.erase((*itr)[3]);
          break;
    }
    }
  }
  
}
