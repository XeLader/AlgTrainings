#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
  int N, *arr,x;
  cin >> N;
  arr = new int[N];
  for (int i = 0; i<N; i++)
    cin>>arr[i];
  int diff, close_i = 0;
  cin >> x;
  diff = abs(x-arr[0]);
  for(int i = 1; i< N; i++)
    if (diff > abs(x-arr[i]))
    {
      diff = abs(x-arr[i]);
      close_i = i;
    }
  cout << arr[close_i];
  delete arr;
}
