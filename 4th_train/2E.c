#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int min(int a, int b)
{
  if (a < b)
    return a;
  else return b;
}

void calc_odd(char *s, int* d, int n)
{
  int l = 0;
  int r = -1;
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    if (i <= r)
       k = min(r - i, d[r - i + l]);
    while(i + k + 1 < n && i - k - 1 >= 0 && s[i + k + 1] == s[i - k - 1])
       k++;
    d[i] = k;
    if (i + k > r)
    {
      l = i - k;
      r = i + k;
    }
  }
}

void calc_even(char *s, int* d, int n)
{
  int l = 0;
  int r = -1;
  for (int i = 0; i < n - 1; i++)
  {
    int k = 0;
    if (i <= r)
       k = min(r - i, d[r - i + l - 1]);
    while (i + k + 1 < n && i - k >= 0 && s[i - k] == s[i + k + 1])
       k++;
    d[i] = k;
    if (i + k - 1 > r)
    {
      l = i - k + 1;
      r = i + k;
    }
  }
}

int main()
{
  char str[100001] = {0};
  scanf("%100000s", str);
  
  int len = strlen(str);
  int *d_odd = (int*)calloc(len, sizeof(int));
  int *d_even = (int*)calloc(len, sizeof(int)); 
  calc_odd(str, d_odd, len);
  calc_even(str, d_even, len);
  
  unsigned long long sum = 0;
  for(int i = 0; i < len; i++)
    sum += d_odd[i] + d_even[i] + 1;
  
  printf("%d", sum);
  
}
