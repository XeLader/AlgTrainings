#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
  long long a, b, c, x;
  scanf("%lld\n%lld\n%lld", &a, &b, &c);
  x = ceil((3*a+b-c)/3.0);
  if (x<0) x=0;
  printf("%lld", x);
}
