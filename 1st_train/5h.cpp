#include <stdio.h>
#include <stdlib.h>


using namespace std;

bool checkMax(int*, int);

int main()
{
  int N, K, lc = 0, rc = 0, letter['z'-'a' + 1] = {0};
  int ts = 0, length = 0;
  char *str;
  
  scanf("%d %d", &N, &K);

  
  str = (char*)calloc(N + 1, sizeof(char));
  
  scanf("%s", str);
  letter[str[rc]-'a']++;
  
  while (rc < N - 1)
  {  
    rc++;
    letter[str[rc]-'a']++;
    while (!checkMax(letter, K))
    {
      letter[str[lc]-'a']--;
      lc++;
    }
    if (length < rc - lc)
    {
      length = rc - lc;
      ts = lc;
    }
  }
  
  
  printf("%d %d", length+1, ts+1);
}

bool checkMax(int *arr, int N)
{
  int p = 0;
  while (p < 26)
    if (arr[p] <= N)
      p++;
    else
      return 0;
  return 1;
}
