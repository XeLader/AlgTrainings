#include "iostream"
#include "stdlib.h"

using namespace std;

int main()
{
  unsigned long long n, c, cc = 0, l = 0, r = 0, countA, countB, max = 0;
  char *s;
  
  cin >> n >>c;
  s = (char*)calloc(n, sizeof(char));
  for(unsigned int i = 0; i < n; i++)
  {
    cin >>s[i];
  }
  countA = s[0] == 'a';
  countB = s[0] == 'b';
  
  for (l; l < n; l++)
  {
    while (cc <= c and r < n)
    {
      r++;
      cc += countA * (s[r] == 'b');
      countA += s[r] == 'a';
      countB += s[r] == 'b';
    }
    if (max < (r-l)) max = (r-l);
    cc -= countB * (s[l] == 'a');
    countA -= s[l] == 'a';
    countB -= s[l] == 'b';
  }
    
  cout << max;
}
