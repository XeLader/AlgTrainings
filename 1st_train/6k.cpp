#include <iostream>
#include <algorithm>

using namespace std;

int finder(int *, int *, int);
int numless(int *, int, int);
int numgrt( int *a, int L, int t);
int lbinsearchge(int l, int r, int *T, int x);

int main()
{
  int N, L, x, d, a, c, m;
  int **arr;
  cin >> N >> L;
  
  arr = new int*[N];
  
  for (int i = 0; i < N; i++)
  {
    arr[i] = new int[L];
    cin >> x >> d >> a >> c >> m;
    arr[i][0] = x;
    for (int j = 1; j < L; j++)
    {
      arr[i][j] = arr[i][j-1] + d;
      d = (a*d+c)%m;
    }
  }
  
  for (int i = 0; i < N; i++)
    for (int j = i+1; j < N; j++)
    {
      cout << finder(arr[i], arr[j], L)<<'\n';
    }

}

int finder(int *a, int *b, int L)
{
  int less, gt, m;
  int l = min(a[0], b[0]);
  int r = max(a[L-1], b[L-1]);
    while (l < r)
    {
      m = (l + r) /2;
      less = numless(a, L, m) + numless(b, L, m);
      gt = numgrt(a, L, m) + numgrt(b, L, m);
      if (less <= L - 1 and gt <= L)
      {
        return m;
      }
      else if (gt > L)
        l = m + 1;
      else if (less > L - 1)
        r = m - 1;
    }
    return l;
}






int lbinsearchge(int l, int r, int *T, int x)
{
  int m;
  while (l < r)
  {
    m = (r + l) / 2;
    if (T[m] >= x)
      r = m;
    else
      l = m + 1;
  }
  return l;
}


int numless(int *a, int L, int t)
{
  int less = lbinsearchge(0, L-1, a, t);
  if (a[less] < t)
    return L;
  else
    return less;
}

int numgrt( int *a, int L, int t)
{
  return L - numless(a, L, t + 1);
}
