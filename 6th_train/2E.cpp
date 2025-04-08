#include "iostream"
#include "algorithm"
#include "stdlib.h"

using namespace std;

int main()
{
  unsigned int *seq;
  int n;
  cin >> n ;
  seq = (unsigned int*)calloc(n, sizeof(unsigned int));
  for (unsigned int i = 0; i < n; i++)
    cin >> seq[i];
  
  sort(seq, seq + n);
  
  int l, r;
  if (n % 2)
  {
    cout << seq[n/2]<<' ';
    l = n/2 - 1;
    r = l + 2;
  }
  else
  {
    r = n/2;
    l = r-1;
  }
  while(l >= 0)
  {
    cout << seq[l] << ' ' << seq[r] << ' ';
    r++;
    l--;
  } 
}
