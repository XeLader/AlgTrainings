#include <iostream>
#include <algorithm>

using namespace std;

int rbin(int l, int r, int *arr, int a);

int main()
{
  int n, m, count, temp, a, b;
  int *in, *out, *points;
  
  cin >> n >> m;
  in = new int[n];
  out = new int[n];
  points = new int[m];
  
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    in[i] = min(a,b);
    out[i] = max(a,b);
  }
  
  for (int i = 0; i < m; i++)
    cin >> points[i];
  
  sort(in, in + n);
  sort(out, out + n);
    
  count = 0;
  int i = 0;
  while (i < m)
  {
    count = 0;
    temp = rbin(0, n - 1, in, points[i]);
    count = (temp + 1) * (in[temp] <= points[i]) ;
    temp = rbin(0, n - 1, out,points[i]-1);
    count -= (temp + 1) * (out[temp] < points[i]) ;
    cout << count <<' ';
    i++;
  }
}


int rbin(int l, int r, int *arr, int a)
{
 int m;
  while (l<r)
  {
    m = (l + r + 1) / 2;
    if (arr[m] <= a)
      l = m;
    else 
      r = m - 1;
  }
  return l;
}

