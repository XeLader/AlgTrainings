#include <iostream>

using namespace std;

int main()
{
  int L , N;
  cin >> L >> N;
  unsigned long long cuts[110];
  unsigned long long dp[110][110] = {0};
  
  cuts[0] = 0;
  cuts[N+1] = L;
  for (int i = 0; i < N; i++)
    cin >> cuts[i + 1];
  int l, r, g;
  unsigned long long min;
  for (int k = 1; k <= N; k++)
  {
    r = k; l = 0;
    while (r <= N)
    {
      dp[l][r] = cuts[r+1] - cuts[l];
      g = l;
      min = (dp[l][g] + dp[g + 1][r]);
      g++;
      while (g < r)
      {
        if (min > dp[l][g] + dp[g+1][r])
          min = dp[l][g] + dp[g+1][r];
        g++;
      }
      dp[l][r]+=min;
      l++;
      r++;
    }
  }
  
  cout << dp[0][N];
}
