#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <math.h>

using namespace std;

void HodKonyom(int x, int y, int *field);

int main()
{
  int gx, gy, rx, ry;
  int redfield[8*8] = {0};
  int greenfield[8*8] = {0};
  
  char a, b;
  
  scanf("%c%i %c%i", &a, &gy, &b, &ry);
  gx = (int)(a - 'a');
  rx = (int)(b - 'a');
  gy --;
  ry --;
  
  HodKonyom(gx, gy, greenfield);
  HodKonyom(rx, ry, redfield);
  
  int mx = 10000;
  for(int x = 0; x < 8; x++)
    for(int y = 0; y < 8; y++)
      if ((redfield[x+y*8] - greenfield[x+y*8])%2 == 0)
        if (max(redfield[x+y*8],greenfield[x+y*8]) < mx)
          mx = max(redfield[x+y*8],greenfield[x+y*8]);
  
  if (mx == 10000)
    cout << -1;
  else
    cout << mx-1;  
}

void HodKonyom(int x, int y, int *field)
{
  queue<int> q;
  field[x+y*8] = 1;
  q.push(x*10+y);
  while(!q.empty())
  {
    x = q.front()/10;
    y = q.front()%10;
    q.pop();
    if (x - 2 >= 0)
    {
      if (y - 1 >= 0)
      {
        if (field [(y-1)*8 + x-2] == 0)
        {
          field [(y-1)*8 + x-2] = field[x+y*8] + 1;
          q.push((x-2)*10+y-1);
        }
      }
      if (y + 1 < 8)
      {
        if (field [(y+1)*8 + x-2] == 0)
        {
          field [(y+1)*8 + x-2] = field[x+y*8] + 1;
          q.push((x-2)*10+y+1);
        }
      }
    }
    if (x - 1 >= 0)
    {
      if (y - 2 >= 0)
      {
        if (field [(y-2)*8 + x-1] == 0)
        {
          field [(y-2)*8 + x-1] = field[x+y*8] + 1;
          q.push((x-1)*10+y-2);
        }
      }
      if (y + 2 < 8)
      {
        if (field [(y+2)*8 + x-1] == 0)
        {
          field [(y+2)*8 + x-1] = field[x+y*8] + 1;
          q.push((x-1)*10+y+2);
        }
      }
    }
    if (x + 2 < 8)
    {
      if (y - 1 >= 0)
      {
        if (field [(y-1)*8 + x+2] == 0)
        {
          field [(y-1)*8 + x+2] = field[x+y*8] + 1;
          q.push((x+2)*10+y-1);
        }
      }
      if (y + 1 < 8)
      {
        if (field [(y+1)*8 + x+2] == 0)
        {
          field [(y+1)*8 + x+2] = field[x+y*8] + 1;
          q.push((x+2)*10+y+1);
        }
      }
    }
    if (x + 1 < 8)
    {
      if (y - 2 >= 0)
      {
        if (field [(y-2)*8 + x+1] == 0)
        {
          field [(y-2)*8 + x+1] = field[x+y*8] + 1;
          q.push((x+1)*10+y-2);
        }
      }
      if (y + 2 < 8)
      {
        if (field [(y+2)*8 + x+1] == 0)
        {
          field [(y+2)*8 + x+1] = field[x+y*8] + 1;
          q.push((x+1)*10+y+2);
        }
      }
    }
  }
}
