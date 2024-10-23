#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
  int f, s, t, count = 0;
  cin >> f;
  cin >> s;
  if (cin >> t)
    do
    {
      if (s>t and s>f)
        count++;
      f = s;
      s = t;
    } while (cin >>t);
  cout << count;
}
