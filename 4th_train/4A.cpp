#include <stdio.h>

using namespace std;

bool check[9] = {0};
char perm[10] = {0};
int N;

void permute(int k)
{
  if (k == 0)
  {
    printf("%s\n", perm);
    return;
  }
  for(int i = 0; i < N; i++)
  {
    if(!check[i])
    {
      check[i] = true;
      perm[N - k] = '1' + i;
      permute(k-1);
      check[i] = false;
    }
  }
}

int main()
{
  scanf("%d", &N);
  permute(N);
}
