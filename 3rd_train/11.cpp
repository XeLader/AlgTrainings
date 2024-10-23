#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int N, K, s = 0, n = 0;
  double Stor[10000], Steck[10000], Sorted[10000];
  
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++)
  {
    s = 0; n = 0;
    scanf("%d", &K);
    for (int j = 0; j < K; j++)
    {
      scanf("%la", Stor+j);
      Sorted[j] = Stor[j]; 
    }
    sort(Sorted, Sorted + K);
    
    for (int j = 0; j < K; j++)
    {
      Steck[s] = Stor[j];
      s++;
      while (s > 0 and Steck[s-1] == Sorted[n])
      {
        s--;
        n++;
      }
    }
    
    if (s != 0 or n <K)
      printf("%d\n", 0);
    else
      printf("%d\n", 1);
  }
}
