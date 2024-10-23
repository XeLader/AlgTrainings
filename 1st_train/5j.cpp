#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;


int main()
{
  long long  K=0, x, y, len;
  int i, N, j, r = 0, l = 0;
  
  long long coor[1500][2];
  
  set<pair<long long, long long>> used;
  multiset<long long> neight;
  multiset<long long>::iterator itr, itl;
  
  
  scanf("%d", &N);
  
  for(i  = 0 ; i < N; i++)
    scanf("%lld %lld", coor[i], coor[i] + 1);
  
  for(i  = 0 ; i < N; i++)
  {  
    used.clear();
    neight.clear();
    for(j  = 0 ; j < N; j++)
    {
      x = coor[i][0] - coor[j][0];
      y = coor[i][1] - coor[j][1];
      len = x*x+y*y;
      neight.emplace(len);
      if (used.contains(make_pair(x,y)))
        K--;
      used.emplace(make_pair(-x,-y));
    }
    itr = neight.begin();
    r = 0;
    l = 0;
    for(itl = neight.begin(); itl != neight.end(); itl++, l++)
    {
      while(itr!=neight.end() and *itr == *itl)
      {  
        itr++;
        r++;
      }
      K += r - l - 1;
    }
      
  }
  
  printf("%lld", K);
}

