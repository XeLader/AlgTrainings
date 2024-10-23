#include <stdio.h>
#include <unordered_set>

using namespace std;

int main()
{
  int N = 0, Shots = 0;
  int x, y;
  
  scanf("%d", &N);
  
  unordered_set<int> Xpos= {};
  
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &x, &y);
    if (x == 0)
      Shots++;
    else if (!Xpos.contains(x))
    {
      Shots++;
      Xpos.insert(x);
    }
  }
  
  printf("%d", Shots);
}
