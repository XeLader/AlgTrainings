#include "stdio.h"
#include "stdlib.h"

int* partition(int *start, int *end, int predicate)
{
  int temp;
  while (start <= end)
  {
    if(*start >= predicate)
    {
      temp = *end;
      *end = *start;
      *start = temp;
      end--;
    }
    if (*start < predicate)
      start++;
  }
  return start;
}

int main()
{
  int N, *a, x;
  scanf("%d", &N);
  a = (int*)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
    scanf("%d", a+i);
  scanf("%d", &x);
  int *m = partition(a, a+N-1, x);
  printf("%d\n%d",(int)(m - a), N - (int)(m - a));
}
