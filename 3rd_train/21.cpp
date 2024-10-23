#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int N, cub[100];
  int *dp;
  
  scanf("%d", &N);
  
  dp = (int*)calloc(N+1, sizeof(int));
  dp[0] = 0;
  dp[1] = 1;
  
  int i=1, j;
  
  while (i * i * i <= N)
  {
     cub[i-1] =   i * i * i;
     i++;
  }
  int maxCub = i-1;
  
  for (i = 2; i<= N; i++)
  {
    dp[i] = 10000;
    for (j = 0; j < maxCub; j++)
    {
      if (dp[i] > dp[i-cub[j]] + 1)
        dp[i] = dp[i-cub[j]]+1;
      if (i < cub[j+1])
        break;
    }
  }
  
  printf("%d", dp[N]);
}
