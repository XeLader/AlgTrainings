#include <stdio.h>

using namespace std;

bool checkLines[10] = {0};
bool checkDiagPlus[10*2-1] = {0};
bool checkDiagMinus[10*2-1] = {0};
unsigned long long count = 0;
int N;



void permute(int k)
{
  if (k == 0)
  {
    count++;
    return;
  }
  for(int line = 0; line < N; line++)
  {
    if(!checkLines[line] and !checkDiagPlus[line + k - 1] and !checkDiagMinus[line - k + N])
    {
      checkLines[line] = true;
      checkDiagMinus[line - k + N] = true;
      checkDiagPlus[line + k - 1] = true;
      permute(k-1);
      checkLines[line] = false;
      checkDiagMinus[line - k + N] = false;
      checkDiagPlus[line + k - 1] = false;
    }
  }
}

int main()
{
  scanf("%d", &N);
  permute(N);
  printf("%lld", count);
}
