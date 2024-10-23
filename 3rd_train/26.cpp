#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int N, M;
  unsigned long long *dp;
  //scanf("%d %d", &N, &M);
  
  
  int x, y;
  
  for (M = 1; M <= 50; M++)
  for (N = 1; N <= 50; N++)
  {
  
  dp = (unsigned long long *)calloc(N*M, sizeof(unsigned long long));
  dp[0] = 1;
  int i = 0, j = 0;
  
  while (i < M and j < N)
  {
    x = i;
    y = j;
    while(x>=0 and y < N)
    {
      
      if (y + 2 < N)
      {
        if (x > 0)
            dp[(y+2)*M + x-1] += dp[y*M + x];
        if (x+1 < M)
          dp[(y+2)*M + x+1] += dp[y*M + x];
      }
      if (x + 2 < M)
      {
        if (y > 0)
          dp[(y - 1)*M + x + 2] += dp[y*M + x];
        if (y+1 < N)
          dp[(y+1)*M + x + 2] += dp[y*M + x];
      }
      x--;
      y++;
    }
    if (i < M - 1)
     i++;
    else
     j++;
    
  }
  
  printf("%d %d - %llu\n",N, M, dp[N*M-1]);
  free(dp);
  }
  printf("All OK");
}

