#include "stdlib.h"
#include "stdio.h"

void merge(int* A, int Na, int *B, int Nb, int *R)
{
  int a = 0, b = 0, r = 0;
  
  while (r < Na + Nb)
  {
    if(a == Na)
      while (r < Na + Nb)
      {
        R[r] = B[b];
        r++;
        b++;
      }
      
    else if (b == Nb)
      while (r < Na + Nb)
      {
        R[r] = A[a];
        r++;
        a++;
      }
      
    else
    {
      if (A[a] < B[b])
      {
        R[r] = A[a];
        a++;
      }
      else
      {
        R[r] = B[b];
        b++;
      }
      r++;
    }
  }
}

void merge_sort(int *A, int N, int *R)
{
    if (N < 2)
    {
      R[0] = A[0];
      return;
    }
    
    merge_sort(A, N/2, R);
    merge_sort(A + N/2, N - N/2, R + N/2);
    
    for (int i = 0; i < N; i++)
      A[i] = R[i];
    
    merge(A, N/2, A + N/2, N - N/2, R);
}


int main()
{
  int N, *a, *r;
  scanf("%d", &N);
  a = (int*)calloc(N, sizeof(int));
  r = (int*)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
    scanf("%d", a+i);
  
  merge_sort(a, N, r);
  
  for (int i = 0; i < N; i++)
    printf("%d ",*(r + i));
}
