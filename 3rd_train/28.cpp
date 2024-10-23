#include "stdio.h"
#include "stdlib.h"
#include "cstring"

using namespace std;

int main()
{
  // N S W E U D
  char Rules[6][101] = {{0}, {0}, {0}, {0}, {0}, {0}};
  int len[6] = {0};
  int* dp[6];
  for (int i = 0; i < 6; i ++)
  {   
    int j = 0;
    do 
    {
      Rules[i][j] = getchar();
      j++;
    }
    while(Rules[i][j-1]!='\n');
    Rules[i][j - 1] = '\0';
    len[i] = strlen(Rules[i]);
  }   
  char Command; 
  int N;
  
  scanf ("%c %d", &Command, &N);
  
  for (int i = 0; i < 6; i++)
  {
    dp[i] = (int*)malloc(sizeof(int)*N);
    dp[i][0] = 1;
  } 
  for (int i = 1; i < N; i++)
    for (int j = 0; j < 6; j++)
    {
      dp[j][i] = 1;
      for (int k = 0; k < len[j]; k++)
      {
        switch (Rules[j][k])
        {
          case 'N':
            dp[j][i]+= dp[0][i-1];
          break;
        
          case 'S':
            dp[j][i]+= dp[1][i-1];
          break;
          
          case 'W':
            dp[j][i]+= dp[2][i-1];
          break;
          
          case 'E':
            dp[j][i]+= dp[3][i-1];
          break;
          
          case 'U':
            dp[j][i]+= dp[4][i-1];
          break;
          
          case 'D':
            dp[j][i]+= dp[5][i-1];
          break;
        }
      }
    }
  
  switch (Command)
        {
          case 'N':
            printf("%d",dp[0][N-1]);
          break;
        
          case 'S':
            printf("%d",dp[1][N-1]);
          break;
          
          case 'W':
            printf("%d",dp[2][N-1]);
          break;
          
          case 'E':
            printf("%d",dp[3][N-1]);
          break;
          
          case 'U':
            printf("%d",dp[4][N-1]);
          break;
          
          case 'D':
            printf("%d",dp[5][N-1]);
          break;
        }
}


