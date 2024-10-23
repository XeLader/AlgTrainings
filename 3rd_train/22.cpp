#include "stdio.h"

using namespace std;

int main()
{
  int N, arr[1000], senLen[1000] = {0}, nextEl[1000] = {0};
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++)
    scanf("%d", arr + i);
      
  for (int i = N-1; i >= 0; i--)
  { 
    if (senLen[i] == 0)
      senLen[i] = 1;
    for (int j = i-1; j > -1; j--)
    {
      if (arr[j] < arr[i] and senLen[j] < senLen[i] + 1)
      {
        senLen[j] = senLen[i] + 1;
        nextEl[j] = i;
      }
    }
  }
  int maxLen = 0, start = 0;
  
  
  for (int i = 0; i < N; i++)
  {
    if (maxLen < senLen[i])
      {
        maxLen = senLen[i];
        start = i;
      }
  }
  for (int i = 0; i < maxLen; i++)
  {
    printf("%d ", arr[start]);
    start = nextEl[start];
  }
}
