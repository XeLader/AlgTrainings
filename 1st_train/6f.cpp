#include <iostream>
#include <cmath>

using namespace std;

long long binsearch(long long w, long long h, long long n);

int main()
{
    long long N, x, y, time;
    cin >> N >> x >> y;
    if (x > y)
      time = y;
    else
      time = x;
    cout << time + binsearch(x, y, N-1);
}

long long binsearch(long long x, long long y, long long n)
{
    long long r = x * n;
    long long l = 0;
    long long m = 0;
    while (l < r)
    {
        m = (r + l) / 2;
        if ((m / x + m / y) >= n)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
