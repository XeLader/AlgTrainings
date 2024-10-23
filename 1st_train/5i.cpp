#include <stdio.h>
#include <stdlib.h>


using namespace std;


int main()
{
  long long  K=0, prev = 0;
  int i, N;
  char *str, ch;
  
  scanf("%d", &N);
  str = (char*)calloc(N, sizeof(char));
  
  for(i  = 0 ; i < N; i++)
    str[i] = getchar();
  
  ch = getchar();
  while (ch >= 'a')
  {  
    
    if (str[i%N] == ch)
    {
      K+= 1 + prev;
      prev++;
    }
    else
    {
      str[i%N] = ch;
      prev = 0;
    }
    i++;
    ch = getchar();
  }
  
  printf("%lld", K);
}

