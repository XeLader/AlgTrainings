#include "stdio.h"
#include "math.h"

using namespace std;

int main()
{
  int h, m, s;
  int a, b, c;
  
  scanf("%d:%d:%d", &h, &m, &s);
  a = h*60*60 + m*60 +s;
  
  scanf("%d:%d:%d", &h, &m, &s);
  b = h*60*60 + m*60 +s;
  
  scanf("%d:%d:%d", &h, &m, &s);
  c = h*60*60 + m*60 +s;
  
  if (c < a)
  c += 24*60*60;
  
  b += round((c - a) / 2.f);
  
  if (b >= 24*60*60)
    b -= 24*60*60;
  
  printf("%02d:%02d:%02d", b/3600, (b/60)%60, b%60);
  
}
