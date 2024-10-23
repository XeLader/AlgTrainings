#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool checkNull(int*, int);

int main()
{
  int N, K, lc = 0, rc = 0;
  int *tree, *spice;
  int start = 0, end;
  
  scanf("%d %d", &N, &K);
  
  end = N;
  
  tree = (int*)calloc(N, sizeof(int));
  spice = (int*)calloc(K, sizeof(int));
  
  for (int i = 0; i < N; i++)
  {
    scanf("%d", tree +i);
  }
  
  while (rc < N)
  {
    spice[tree[rc] - 1]++;
    if (checkNull(spice, K))
    {
      while (checkNull(spice, K))
      {
        spice[tree[lc] - 1]--;
        lc++;
      }
      if (rc - lc + 1 < end - start)
      {
        start = lc - 1;
        end = rc;
      }
    }
    rc++;
  }
  printf("%d %d", start+1, end+1);
}

bool checkNull(int *arr, int N)
{
  int p = 0;
  while (p < N)
    if (arr[p])
      p++;
    else
      return 0;
  return 1;
}
