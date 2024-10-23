#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int N, x,y, prevy = 0, highR=0, highL = 0;
  int *pointR, *pointL;
  
  scanf("%d", &N);
  pointR = (int*)malloc(N*sizeof(int));
  pointL = (int*)malloc(N*sizeof(int));
  
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &x, &y);
    highR += (y > prevy) ? y-prevy: 0;
    highL += (prevy > y) ? prevy - y: 0;
    pointR[i] = highR;
    pointL[i] = highL;
    prevy = y;
  }
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &x, &y);
    if (x > y)
      printf("%d\n", pointL[x-1] - pointL[y-1]);
    else
      printf("%d\n", pointR[y-1] - pointR[x-1]);
  }
  
}
