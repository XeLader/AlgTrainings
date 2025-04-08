#include <stdio.h>

using namespace std;

bool visited[10];
int countVis = 0;
int matrix[10][10] = {0};
int minSum = 1000000000, sum;
int N;

void dfs(int cur)
{
  
  if (countVis == N - 1)
  {
      if (minSum > sum + matrix[0][cur] and matrix[0][cur] != 0)
        minSum = sum + matrix[0][cur];
      return;
  }
  
  countVis++;
  visited[cur] = true;
  for (int i = 1; i < N; i++)
  {
    if (!visited[i] and sum + matrix[i][cur] < minSum and matrix[i][cur] != 0)
    {
      sum += matrix[i][cur];
      dfs(i);
      sum -= matrix[i][cur];
    }
  }
  countVis--;
  visited[cur] = false;
  
}

int main()
{

  scanf("%d", &N);
  if (N == 1)
    minSum = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &matrix[i][j]);
  sum = 0;
  dfs(0);
  if (minSum < 1000000000)
    printf("%d", minSum);
  else
    printf("-1");
}
