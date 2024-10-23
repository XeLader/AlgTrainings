#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void BinSortInput(int, int *, int *);
int rbin(int l, int r, int *arr, int a);

int main()
{
  int N, D, maxvar = 1, *arr, *arrN, *var;
  unordered_set<int> varUsed, varAvail;
  
  cin >> N >> D;
  arr = new int[N];
  arrN = new int[N];
  var = new int[N];
  
  BinSortInput(N, arr, arrN);
  var[arrN[0]] = 1;
  varUsed.emplace(1);
  
  int r = 1, l = 0;
  
  while (r < N)
  {
    if (arr[r] - arr[l] <= D)
    {
      if (varAvail.empty())
      {
      maxvar ++;
      var[arrN[r]] = maxvar;
      varUsed.emplace(var[arrN[r]]);
      }
      else
      {
        var[arrN[r]] =*(varAvail.begin());
        varAvail.erase(var[arrN[r]]);
        varUsed.emplace(var[arrN[r]]);
      }
      r++;
    }
    else 
    {
      while(arr[r] - arr[l] > D)
      {
        varAvail.emplace(var[arrN[l]]);
        varUsed.erase(var[arrN[l]]);
        l++;
      }
      var[arrN[r]] =*(varAvail.begin());
      varAvail.erase(var[arrN[r]]);
      varUsed.emplace(var[arrN[r]]);
      r++;
    }
    
  }
  cout << maxvar <<'\n';
  for (int i = 0; i < N; i++)
  {
    cout << var[i] <<' ';
  }
}

void BinSortInput(int N, int *arr, int *arrN)
{
  int temp, pos;
  cin >> arr[0];
  arrN[0] = 0;
  for (int i = 1; i < N; i++)
  {
    cin >> temp;
    pos = rbin(0, i-1, arr, temp);
    pos = (pos + 1) * (arr[pos] <= temp);
    shift_right(arr+pos, arr + i + 1, 1);
    arr[pos] = temp;
    shift_right(arrN+pos, arrN + i + 1, 1);
    arrN[pos] = i;
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
