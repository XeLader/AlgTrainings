#include "iostream"
#include "stdlib.h"

using namespace std;

int main()
{
  int n;
  unsigned long long *a, *ps, *ml, *mr;
  
  cin >> n;
  a = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  ps = (unsigned long long*)calloc(n+1, sizeof(unsigned long long));
  ml = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  mr = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  
  
  cin >> a[0];
  ps[0] = 0;
  mr[0] = 0;
  for (int i = 1; i < n; i++)
  {
    cin >> a[i];
    ps[i] = ps[i-1] + a[i-1];
    mr[i] = mr[i-1] + ps[i-1] + a[i-1];
  }
  ps[n] = ps[n-1] + a[n - 1];
  
  ml[n-1] = 0;
  for (int i = n-2; i >= 0; i--)
  {
    ml[i] = ml[i+1] + (ps[n]-ps[i+2]) + a[i+1];
  }
  unsigned long long min = ml[0];
  for (int i = 1; i < n; i++)
    if (min > ml[i] + mr[i]) min = ml[i] + mr[i];
  
  cout << min;
}
