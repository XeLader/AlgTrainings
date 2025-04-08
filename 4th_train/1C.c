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

int main()
{
  int Na, Nb, *a, *b, *r;
  scanf("%d", &Na);
  a = (int*)calloc(Na, sizeof(int));
  for (int i = 0; i < Na; i++)
    scanf("%d", a+i);
    
  scanf("%d", &Nb);
  b = (int*)calloc(Nb, sizeof(int));
  for (int i = 0; i < Nb; i++)
    scanf("%d", b+i); 
    
  r = (int*)calloc(Na + Nb, sizeof(int));  
  merge(a, Na, b, Nb, r);
  
  for (int i = 0; i < Na + Nb; i++)
    printf("%d ",*(r + i));
}
