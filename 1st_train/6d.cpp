#include <iostream>

using namespace std;

long long binsearch(long long, long long, long long, long long, long long);

int main()
{
    long long w, n, a, b, h, temp, c, d;
    cin >> n >> a >> b >> w >> h;
    if (w < h)
    {
        temp = w;
        w = h;
        h = temp;
    }
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    c = binsearch(w, h, a, b, n);
    d = binsearch(w, h, b, a, n);
    if (c < d)
      cout << d;
    else cout << c;
    
}

long long binsearch(long long w, long long h, long long a, long long b, long long n)
{
    long long r = w;
    long long l = 0;
    long long m = 0;
    while (l < r)
    {
        m = (r + l + 1) / 2;
        if ((w/(a+2*m)) * (h / (b+2*m)) >= n)
            l = m;
        else
            r = m - 1;
    }
    return l;
}
