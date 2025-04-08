#include <stdio.h>

using namespace std;

char stack[17] = {0};
int stackCount = 0, N;
char rbs[16];


void step(int pos)
{ 
  
  if (pos == N - 1 and stackCount == 1)
  {
    if (stack[1] == '(')
      rbs[pos] = ')';
    else
      rbs[pos] = ']';
    printf("%s\n", rbs);
    return;
  }
  
  if (stackCount + pos < N)
  {
    stackCount++;
    stack[stackCount] = '(';
    rbs[pos] = '(';
    step(pos + 1);
    stackCount--;
  }
  
    if (stackCount + pos < N)
  {
    stackCount++;
    stack[stackCount] = '[';
    rbs[pos] = '[';
    step(pos + 1);
    stackCount--;
  }
  
  if(stack[stackCount] == '(')
  {
    rbs[pos] = ')';
    stackCount--;
    step(pos + 1);
    stackCount++;
    stack[stackCount] = '(';
  }
  
  
  if(stack[stackCount] == '[')
  {
    rbs[pos] = ']';
    stackCount--;
    step(pos + 1);
    stackCount++;
    stack[stackCount] = '[';
  }
}

int main()
{
  scanf("%d", &N);
  step(0);
}

