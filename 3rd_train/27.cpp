#include <string>
#include <iostream>


using namespace std;

int main()
{
  string A, B;
  cin >> A >> B;
  unsigned int N = A.length();
  unsigned int M = B.length();
  
  unsigned int *dp = new unsigned int[(N+1)*(M+1)];
  dp[0] = 0;
  
  for (unsigned int i = 1; i <= N; i++)
      dp[i] = i;
        
  for (unsigned int j = 1; j <= M; j++)
    dp[j*(N+1)] = j;
  
  unsigned int min;
  for (unsigned int i = 1; i <= N; i++)
    for (unsigned int j = 1; j <= M; j++)
    { 
      min = dp[(j-1)*(N + 1)+ i - 1] + !(A[i-1]==B[j-1]);
      if (min > (dp[j*(N + 1) + i - 1] + 1))
        min = dp[j*(N +  1) + i - 1] + 1;
      if (min > (dp[(j-1)*(N  + 1) + i] + 1))
        min = dp[(j-1)*(N + 1) + i] + 1;
      dp[j*(N+1)+i] = min;
    }
  cout << dp[(N + 1)*(M + 1) - 1];
}
