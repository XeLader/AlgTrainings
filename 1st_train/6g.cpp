#include <iostream>

using namespace std;

long long binsearch(long long n, long long k, long long t);

int main()
{
  long long n, m, t, temp;
  cin >> n >> m >> t;
  if (n > m)
  {
  temp = n;
  n = m;
  m = temp;
  }
  cout << binsearch(n, m, t);
}

long long binsearch(long long n, long long k, long long t)
{
    long long r = n/2;
    long long l = 0;
    long long m = 0;
    while (l < r)
    {
        m = (r + l +1) / 2;
        if (n*k-(n-m*2)*(k-m*2) <= t)
            l = m;
        else
            r = m - 1;
    }
    return l;
}
