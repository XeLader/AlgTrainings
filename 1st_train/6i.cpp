#include <iostream>
#include <algorithm>

using namespace std;

int binsearch(int n, int R, long long *T, int c, int r);
int Count(int m, long long *T, int n, int c);

int main()
{
  long long  *L, *Teams;
  int n, r, c;
  cin >> n >> r >> c;
  
  L = (long long*)calloc(n, sizeof(long long));  
  Teams = (long long*)calloc(n-c+1, sizeof(long long));  
  

  
  for (int i = 0; i < n; i++)
  {
      cin >> L[i];
  }
  
  sort(L, L+n);
  
  for (int i = 0; i < n - c +1; i++)
  {
    Teams[i] = L[i+c-1] - L[i];
  }
  
  cout << binsearch(n - c +1, r, Teams, c, L[n-1]);
}


int binsearch(int n, int R, long long *T, int c, int r)
{
    int l = 0;
    int m = 0;
    while (l < r)
    {
        m = (r + l) / 2;
        if (Count(m, T, n, c) >= R)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int Count(int m, long long *T, int n, int c)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (T[i] <= m)
    {
      count++;
      i+= c-1;
    }
  }
  return count;
}
