#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const unsigned long long x = 131;
const unsigned long long p = 1e9+7;
unsigned long long *hash;
unsigned long long *pw;
int len;

void preproc(char *str)
{
  hash[0] = 0;
  pw[0] = 1;
  for (int i = 1; i < len + 1; i++)
  {
      hash[i] = (hash[i-1] * x + str[i-1]) % p;
      pw[i] = (pw[i-1] * x) % p;
  }
}

int zfunc(int i)
{
  int l = 0, r = len - i, m;
  while (l<r)
  {
    m = (l + r + 1) / 2;
    if ((hash[m] + hash[i]*pw[m])%p == (hash[i + m])%p)
      l = m;
    else 
      r = m - 1;
  }
  return l;
}


int main()
{
  char str[1000001] = {0};
  scanf("%1000000s", str);
  
  len = strlen(str);
  
  hash = calloc(len + 1, sizeof(unsigned long long));
  pw = calloc(len + 1, sizeof(unsigned long long));
  
  preproc(str);  
  printf("0");
  int temp;
  for (int i = 1; i < len; i++)
  {
    temp = zfunc(i);
    printf(" %d", temp);
  } 
}
