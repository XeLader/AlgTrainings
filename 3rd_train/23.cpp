#include "stdio.h"

using namespace std;

int main()
{
  int N, revCount = 0; 
  scanf("%d", &N);
  
  unsigned long long count = 0;
  
  
  for (int i = 1; i <= N; i++)
  {
    count += i * (N - i + 1);
    revCount += i/2;
    count += revCount;
  }
  
  printf("%llu", count);
}
