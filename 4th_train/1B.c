#include "stdio.h"
#include "stdlib.h"


void sort(int *start, int *end)
{
  int pivoti = rand() % (end - start);
  int *eq = start, *gr = start + 1, *now = start + 1, pivot = *(start + pivoti);
  *(start + pivoti) = *eq;
  *eq = pivot;
  while (now <= end)
  {
    if(*now == *eq)
    {
      *now = *gr;
      *gr = *eq;
      gr++;
    }
    else if(*now < *eq)
    {
      *eq = *now;
      *now = *gr;
      *gr = pivot;
      gr++;
      eq++;
    }
    now++;
  }
  
  if (eq - 1 > start)
    sort(start, eq - 1);
  if (gr< end)
      sort(gr, end);
}

int main()
{
  int N, *a, x;
  scanf("%d", &N);
  a = (int*)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
    scanf("%d", a+i);
    
  if (N > 1)  
    sort(a, a + N - 1);
  
  for (int i = 0; i < N; i++)
    printf("%d ",*(a+i));
}
