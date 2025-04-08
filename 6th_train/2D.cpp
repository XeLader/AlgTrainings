#include "iostream"
#include "algorithm"
#include "stdlib.h"

using namespace std;

int main()
{
  unsigned int n, k, *tasks;
  cin >> n >> k;
  tasks = (unsigned int*)calloc(n, sizeof(unsigned int));
  for (unsigned int i = 0; i < n; i++)
    cin >> tasks[i];
  
  sort(tasks, tasks + n);
  
  unsigned int l = 0, r = 1, max = 1;
  for (l; l < n; l++)
  {
    while (tasks[r] - tasks[l] <= k and r < n)
      r++;
    if (r - l > max) max = r - l;
  }
  cout << max;
}
