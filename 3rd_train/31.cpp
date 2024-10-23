#include <stdio.h>
#include <stdlib.h>

using namespace std;

void rfc(int x, int y);
 
int  *map, Sq = 0, N = 0; 

int main()
{
  int x, y;
  scanf("%d", &N);
  map =(int*)calloc(N*N, sizeof(int));
  
  for (int i = 0; i < N*N; i++)
    scanf(" %c ", map + i);
  
  scanf("%d %d", &x, &y);
  rfc(x-1, y-1);
  
  printf("%d", Sq);
}

void rfc(int x, int y)
{
  Sq++;
  map[N*y+x] = 0; 
  if (map[N*(y+1)+x] == '.')
    rfc(x, y+1);
  if (map[N*(y-1)+x] == '.')
    rfc(x, y-1);
  if (map[N*y+x+1] == '.')
    rfc(x+1, y);
  if (map[N*y+x-1] == '.')
    rfc(x-1, y);
}
