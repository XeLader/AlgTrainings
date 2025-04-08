#include "iostream"

using namespace std;

int main()
{
  unsigned long long A, B, C, D;
  scanf("%llu %llu %llu %llu", &A, &B, &C, &D);
  
  if (A == 0)
  {
      printf("%llu %llu", 1, C + 1);
      return 0;
  }
  else if (B == 0)
  {
      printf("%llu %llu", 1, D + 1);
      return 0;
  }
  else if (C == 0)
  {
      printf("%llu %llu", A + 1, 1);
      return 0;
  }
  else if (D == 0)
  {
      printf("%llu %llu", B + 1, 1);
      return 0;
  }

  if (A > B)
  {
    if (C >= D)
    {
      if (B + D + 2 >= C + 2 or B + D + 2 >= A + 2)
      {
        if (A + 2 >= C + 2)
          printf("%llu %llu", 1, C + 1);
        else 
          printf("%llu %llu", A + 1, 1);
      }
      else
        printf("%llu %llu", B + 1, D + 1);
    }
    else
    {
       if (A > D)
        printf("%llu %llu", 1, D + 1);
       else
        printf("%llu %llu", A + 1, 1);
    } 
  } 
  else   
  {
    if (D >= C)
    {
      if (A + C + 2 >= B + 2 or A + C + 2 >= D + 2)
      {
      if (D + 2 >= B + 2)
        printf("%llu %llu", B + 1, 1);
      else
        printf("%llu %llu", 1, D + 1);
      }
      else
        printf("%llu %llu", A + 1, C + 1);
    }
    else
    {
       if (B > C)
        printf("%llu %llu", 1, C + 1);
       else
        printf("%llu %llu", B + 1, 1);
    } 
  } 
}
