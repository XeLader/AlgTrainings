#include "iostream"
#include "stdlib.h"

using namespace std;

int main()
{
  unsigned int n, *a;
  unsigned long long *ps, sum = 0,l, r;
  cin >> n;
  a = (unsigned int*)calloc(n, sizeof(unsigned int));
  ps = (unsigned long long*)calloc(n+1, sizeof(unsigned long long));
  ps[0] = 0;
  for (unsigned int i = 0; i < n; i++)
  {
    cin >> a[i];
    ps[i+1] = ps[i] + a[i];
  }
  
  for (unsigned int i = 1; i < n-1; i++)
  {
    l = ps[i] % 1000000007;
    r = (ps[n] - ps[i+1]) % 1000000007;
    sum += (((l*a[i]) % 1000000007)*r) % 1000000007;
    sum %= 1000000007;
  }
  cout << sum;
}
