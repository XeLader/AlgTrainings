#include <stdio.h>
#include <unordered_set>

using namespace std;

int main()
{
  int N = 0, Truth = 0;
  int a, b;
  
  scanf("%d", &N);
  
  unordered_set<int> Position = {};
  
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &a, &b);
    if (a + b == N-1 and !Position.contains(a) and (a >= 0) and (b >= 0))
    {
      Truth++;
      Position.insert(a);
    }
  }
  
  printf("%d", Truth);
}
