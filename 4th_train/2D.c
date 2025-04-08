#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const unsigned long long p = 1e9+7;
unsigned long long x;

void preproc(unsigned int *str, int len, unsigned long long *hash_dir, unsigned long long *hash_rev, unsigned long long *pow)
{
  hash_dir[0] = 0;
  hash_rev[0] = 0;
  pow[0] = 1;
  for (int i = 1; i < len + 1; i++)
  {
      hash_dir[i] = (hash_dir[i-1] * x + str[i-1]) % p;
      hash_rev[i] = (hash_rev[i-1] * x + str[len - i]) % p;
      pow[i] = (pow[i-1] * x) % p;
  }
}


int main()
{
  unsigned int len;
  scanf("%d %d", &len, &x);
  x++;
  
  unsigned int *str = calloc(len, sizeof(unsigned long long));
  unsigned long long *hash_dir = calloc(len + 1, sizeof(unsigned long long));
  unsigned long long *hash_rev = calloc(len + 1, sizeof(unsigned long long));
  unsigned long long *pow = calloc(len + 1, sizeof(unsigned long long));
  
  for (int i = 0; i < len; i++)
    scanf("%d", str + i);
  
  preproc(str, len, hash_dir, hash_rev, pow);
  
  for(int i = len/2; i >= 0; i--)
    if ((hash_dir[i] + hash_rev[len-2*i]*pow[i])%p == (hash_rev[len-i]%p))
      printf("%d ", len - i);
}
