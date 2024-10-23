#include "stdio.h"

using namespace std;

int main()
{
  int K, minX, minY, maxX, maxY;
  scanf("%d", &K);
  
  int x, y;
  scanf("%d %d", &x, &y);
  
  minX = x;
  maxX = x;
  
  minY = y;
  maxY = y;
  
  for( int i = 1; i < K; i++)
  {
    scanf("%d %d", &x, &y);
    if (x> maxX)
     maxX = x;
    else if (x < minX)
      minX = x;
      
    if (y > maxY)
      maxY= y;
    else if (y < minY)
      minY = y;
  }
  
  printf("%d %d %d %d", minX, minY, maxX, maxY);
}
