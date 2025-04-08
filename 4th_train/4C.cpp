#include <stdio.h>

using namespace std;

int s[20][20] = {0};
int parts = 0;
int N;

int sumEdge()
{
  int sum = 0;
  for (int i = 0 ; i < N; i++)
    for (int j = i; j < N; j++)
      sum += s[i][j] * (((parts >> i) & 1) != ((parts >> j) & 1));
  return sum;
}


int main()
{
  scanf("%d", &N);
  int count = 1, maxSum = 0, maxGroup = 0; 
  
  for (int i = 0; i < N; i++)
  {
    count *= 2;
    for (int j = 0; j < N; j++)
      scanf("%d", &s[i][j]);
  }   
  

  for (parts = 1; parts < count/2; parts++)
  {
    int temp = sumEdge();
    if (temp > maxSum)
    {
      maxSum = temp;
      maxGroup = parts;
    }
  }
  
  printf("%d\n", maxSum);
  for (int i = 0; i < N; i++)
    printf("%d ", ((maxGroup >> i) & 1) + 1); 
}
