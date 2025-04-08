#include "iostream"

using namespace std;

int main()
{
  int x1, x2, y1, y2, x, y;
  scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y);
  if (x < x1)
  {
    if (y > y2)
      printf("NW");
    else if (y > y1)
      printf("W");
    else
      printf("SW");
  }
  else if (x < x2)
  {
    if (y > y2)
      printf("N");
    else
      printf("S");
  }
  else
  {
    if (y > y2)
      printf("NE");
    else if (y > y1)
      printf("E");
    else
      printf("SE");
  }
}
