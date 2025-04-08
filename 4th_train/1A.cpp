#include "iostream"
#include "fstream"
#include "stdlib.h"

using namespace std;

int* partition(int *start, int *end, int predicate)
{
  int temp;
  while (start <= end)
  {
    if(*start >= predicate)
    {
      temp = *end;
      *end = *start;
      *start = temp;
      end--;
    }
    if (*start < predicate)
      start++;
  }
  return start;
}

int main()
{
  int N, *a, x;
  cin >> N;
  a = (int*)calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
    cin >> a[i];
  cin >> x;
  int *m = partition(a, a+N-1, x);
  cout << (int)(m - a) << '\n' << N - (int)(m - a);
}
