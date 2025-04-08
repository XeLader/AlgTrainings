#include "iostream"

using namespace std;

int main()
{
  int n, m, k;
  unsigned long long *a, *s;
  cin >> n;
  a = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  s = (unsigned long long*)calloc(n, sizeof(unsigned long long));
  s[0] = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  cin >> m >> k;
  int rep = 0;
  int l = n - 1, r = n - 1;
  for (r; r > 0; r--)
  {
    while (l > 0 and rep + (a[l] == a[l-1])  <= k and a[l-1] <= a[l])
    {
      l--;
      rep += (a[l] == a[l+1]); 
    }
    s[r] = l+1;
    if (l == r) l--; 
    else rep -= (a[r] == a[r-1]); 
    
  }
  int x;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    cout << s[x-1]<< ' '; 
  }
    
}
