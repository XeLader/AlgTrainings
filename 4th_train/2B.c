#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const unsigned long long x = 131;
const unsigned long long p = 1e9+7;

void preproc(char *str, int len, unsigned long long *hash, unsigned long long *pow)
{
  hash[0] = 0;
  pow[0] = 1;
  for (int i = 1; i < len + 1; i++)
  {
      hash[i] = (hash[i-1] * x + str[i-1]) % p;
      pow[i] = (pow[i-1] * x) % p;
  }
}


int main()
{
  char str[50001] = {0};
  scanf("%50000s", str);
  
  int len = strlen(str);
  
  unsigned long long *hash = calloc(len + 1, sizeof(unsigned long long));
  unsigned long long *pow = calloc(len + 1, sizeof(unsigned long long));
  
  preproc(str, len, hash, pow);

  int i = 1;
  while (i < len && (hash[len])%p != (hash[len-i] + hash[i]*pow[len-i])%p)
    i++;
  
  if ((hash[len])%p != (hash[len-i] + hash[i]*pow[len-i])%p)
    i++; 
    
  printf("%d", i);
}
