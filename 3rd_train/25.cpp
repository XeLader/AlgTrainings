#include "stdio.h"

using namespace std;

int main()
{
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int dp[1001] = {0};
  int max, min;
  for (int i = 2; i <= n; i++)
  {
    min = 1000000000;
    for (int k = 1; k < i; k++)
    {
      max = 0;
      if ((dp[k] + a) > max)
        max = dp[k] + a;
      if ((dp[i - k] + b) > max)
        max = dp[i - k] + b;
      if (max < min)
        min = max;
    }
    dp[i] = min;
  }
  max = 0;
  for (int i = 1; i <= n; i++)
    if(dp[i] > max)
      max = dp[i];
  printf("%d", max);  
}


