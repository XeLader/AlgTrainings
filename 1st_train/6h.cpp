#include <iostream>

using namespace std;

long long binsearch(int n, int k);
long long L[10000];
long long Count(int m, int n);

int main()
{
  long long temp = 0;
  int n, k;
  cin >> n >> k;
  
  
  
  for (int i = 0; i < n; i++)
  {
    cin >> L[i];
    temp += L[i];
  }
  
  if (k > temp) cout << 0;
  else cout << binsearch(n, k);
}

long long binsearch(int n, int k)
{
    long long r = 10000000;
    long long l = 0;
    long long m = 0;
    while (l < r)
    {
        m = (r + l +1) / 2;
        if (Count(m, n) >= k)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

long long Count(int m, int n)
{
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum+= L[i]/m;
  }
  return sum;
}
