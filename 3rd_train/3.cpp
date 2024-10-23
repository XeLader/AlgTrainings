#include <iostream>
#include <algorithm>

using namespace std;

int rbin(int, int, int*, int);
void BinSortInput(int , int *, int *);

int main()
{
  int N, K, temp, res;
  int UniqCount = 0;
  int* Cards;
  
  cin >> N;
  Cards = new int[N];
  BinSortInput(N, Cards, &UniqCount);
  
  cin >> K;
  if (N == 0)
    for  (int i = 0; i < K; i++)
    {
       cout << 0 << '\n';  
    }
  else
    for (int i = 0; i < K; i++)
    {
       cin >> temp;
       res = rbin(0, UniqCount - 1, Cards, temp);
       cout << res + (Cards[res] < temp)   << '\n';
    }
}

int rbin(int l, int r, int *arr, int a)
{
 int m;
  while (l<r)
  {
    m = (l + r + 1) / 2;
    if (arr[m] <= a)
      l = m;
    else 
      r = m - 1;
  }
  return l;
}

void BinSortInput(int N, int *arr, int* realCount)
{
  if (N==0)
    return;
  int temp, pos;
  cin >> arr[0];
  realCount[0] ++;
  for (int i = 1; i < N; i++)
  {
    cin >> temp;
    pos = rbin(0, realCount[0]-1, arr, temp);
    if (temp != arr[pos])
    {
    pos = (pos + 1) * (arr[pos] <= temp);
    realCount[0] ++;
    shift_right(arr+pos, arr + i + 1, 1);
    arr[pos] = temp;
    }
  }
}
