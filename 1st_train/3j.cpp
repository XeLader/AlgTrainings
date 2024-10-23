#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main()
{
  int t, d, n, x, y;
  
  pair<int, int> coord(0, 0);
  
  int diagPos[4] = {0};
  int diagNav[4];
  int *xpos;
  int *ypos;
  int count = 0;
 
  int ArraySize = 10000;
  
  xpos = (int*)malloc(sizeof(int)*ArraySize);
  ypos = (int*)malloc(sizeof(int)*ArraySize);

  cin >> t >> d >> n;
  
  for (int i = 0; i < n; i ++)
    {
      cin >> coord.first >> coord.second; 
      diagNav[0] =  coord.first - coord.second + d;
      diagNav[1] =  coord.first - coord.second - d;
      diagNav[2] =  coord.first + coord.second - d;
      diagNav[3] =  coord.first + coord.second + d;
      
      diagPos[0] += t;
      diagPos[1] -= t;
      diagPos[2] -= t;
      diagPos[3] += t;
       
      diagPos[0] = min(diagPos[0], diagNav[0]);
      diagPos[1] = max(diagPos[1], diagNav[1]);
      diagPos[2] = max(diagPos[2], diagNav[2]);
      diagPos[3] = min(diagPos[3], diagNav[3]);
    }
  
  for (x = ceil((diagPos[2] + diagPos[1])/2.0); x <= (diagPos[3] + diagPos[0])/2; x++)
    for (y = max(diagPos[2] -x, x-diagPos[0])  ; y <= min(diagPos[3] -x, x-diagPos[1]); y++)
    {
      xpos[count] = x;
      ypos[count] = y;
      count++;
      if (count >= ArraySize)
      { 
        ArraySize+=10000;
        xpos = (int *)realloc(xpos, sizeof(int)*ArraySize);
        ypos = (int *)realloc(ypos, sizeof(int)*ArraySize);
      }
    }
  
  cout<<count<<'\n';
  for (int i =0 ; i< count; i++)
    cout << xpos[i]<<' '<<ypos[i]<<'\n';
}
